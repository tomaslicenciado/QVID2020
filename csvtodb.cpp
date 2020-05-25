#include "csvtodb.h"
#include <QWaitCondition>



CsvToDb::CsvToDb(QObject *parent):QObject(parent),
                                  manager(new QNetworkAccessManager),
                                  nombres_campos_csv(new QList<QByteArray>),
                                  lineas_csv(new QList<QByteArray>)

{
    if (base.conectar(BD_STR)==2){
        forzar_actualizacion = true;
    }
    else{
        forzar_actualizacion = false;
    }
    motor_libre = true;

    //DEBUG: mostrar en pantalla el punto de ejecución actual
    //qDebug() << "Constructor completo";
}

CsvToDb::~CsvToDb()
{
    delete (manager);
    delete nombres_campos_csv;
    delete lineas_csv;
    base.cerrar();

    //DEBUG: mostrar en pantalla el punto de ejecución actual
    //qDebug() << "Constructor completo";
}

bool CsvToDb::leer_csv()
{
    QEventLoop loop;
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(cargar_csv(QNetworkReply*)));
    manager->get(QNetworkRequest(QUrl(csv_url_str)));
    connect(this,SIGNAL(csv_cargado()),&loop,SLOT(quit()));
    loop.exec();

    this->esperar_motor();

    //DEBUG: mostrar en pantalla el punto de ejecución actual
    //qDebug() << "leer_csv completo";

    //A modo de control, verificamos si el csv está vacío o si se pudo cargar correctamente en memoria
    return (!lineas_csv->isEmpty());
}

bool CsvToDb::esta_libre()
{
    return motor_libre;
}

void CsvToDb::ocupar()
{
    motor_libre = false;
}

void CsvToDb::liberar()
{
    motor_libre = true;
}

QString CsvToDb::get_id_pais(QString pais)
{
    QString id = "0";
    id = base.consulta("SELECT id FROM paises WHERE pais = '"+pais+"'").at(0).at(0);
    return id;
}

QString CsvToDb::get_id_region(QString region, QString id_pais)
{
    QString id = "0";
    if (region != "" && region != "Sin región/Total país"){
        id = base.consulta("SELECT id FROM regiones WHERE region = '"+region+"' AND id_pais = '"+id_pais+"'").at(0).at(0);
    }
    return id;
}

QVector<QStringList> CsvToDb::obtener_datos(QString consulta)
{
    return base.consulta(consulta);
}

QVector<QStringList> CsvToDb::acumular_datos(QVector<QStringList> orig)
{
    QVector<QStringList> result,vaux;
    vaux = orig;
    int iaux;
    QString fecha;
    QString dato;
    QStringList laux;

    for (int i=0;i<vaux.size();i++){
        laux.clear();
        fecha = vaux.at(i).at(0);
        iaux = vaux.at(i).at(1).toInt();
        for (int j=i+1;j<vaux.size();j++){
            if (vaux.at(j).at(0)==fecha){
                iaux += vaux.at(j).at(1).toInt();
                vaux.remove(j);
                j--;
            }
        }
        dato = QString::number(iaux);
        laux.append(fecha);
        laux.append(dato);
        result.append(laux);
    }

    return result;
}

bool CsvToDb::getForzar_actualizacion() const
{
    return forzar_actualizacion;
}

void CsvToDb::set_csv(QString str_url)
{
    csv_url_str = str_url;
}

void CsvToDb::set_tabla(QString str_tabla)
{
    tabla = str_tabla;
}

void CsvToDb::esperar_motor()
{
    while (!this->esta_libre()) {
        qDebug() << "Esperando se libere el motor de trabajo";
    }
}

void CsvToDb::limpiar()
{
    this->liberar();
    this->set_csv("");
    this->set_tabla("");
    this->lineas_csv->clear();
    this->nombres_campos_csv->clear();
    delete manager;
    manager = new QNetworkAccessManager;

}

bool CsvToDb::actualizar_datos_region(QByteArray linea, QString tabla_str)
{
    //Si por alguna razón está ocupado el motor de procesamiento (Por si no se terminó una tarea anterior),
    //esperamos que se libere. Ésto ayuda a mantener un orden secuencial en el trabajo.
    //La secuencialidad es escencial para un correcto manejo de base de datos, cuyo acceso debe ser secuencial
    this->esperar_motor();
    //Una vez liberado el motor, lo ocupamos para realizar las tareas necesarias
    this->ocupar();

    bool r=false;
    //Separo las columnas del csv en sus respectivos campos, separados por ','
    QList< QByteArray > datos_csv = linea.split(',');
    //Obtengo la region
    QString region = datos_csv.at(0);
    //Obtengo el país
    QString pais = datos_csv.at(1);

    //Obtengo de la tabla paises, el id de pais
    QString id_pais = base.consulta("SELECT id FROM paises WHERE pais = '"+pais+"'").at(0).at(0);

    //Obtengo el id de region de la tabla regiones
    QString id_region;
    if (region == ""){
        id_region = "0";
    }
    else {
        id_region = base.consulta("SELECT id FROM regiones WHERE region = '"
                                          +region+"' AND id_pais = '"+id_pais+"'").at(0).at(0);
    }

    //Obtengo los datos de la tabla 'tabla_str' de la bd, correspondientes a la linea del csv
    QVector< QStringList > datos_bd = base.consulta("SELECT fecha,cant FROM "
                                                    +tabla_str+" WHERE id_pais = '"
                                                    +id_pais+"' AND id_region = '"+id_region+"'");

    //Busco los datos del csv que ya estén cargados en la bd, para eliminarlos de datos_csv
    for (int i=4;i<datos_csv.size();i++){
        //Formo un stringlist de la forma {fecha,cantidad} para buscar coincidencias en datos_bd
        QStringList aux;
        aux.append(nombres_campos_csv->at(i));
        aux.append(datos_csv.at(i));

        //Marco el dato coincidente con -1 para ignorarlo a la hora de actualizar la bd
        if (datos_bd.contains(aux)){
            datos_csv.replace(i,"-1");
        }
    }


    //Genero una línea de sql para insertar en una sola conexión todas los paises pendientes de insertar en la bd
    //Ésto disminuirá el tiempo de acceso al disco, aumentando la performance
    QString linea_insertar;
    linea_insertar = "INSERT INTO "+tabla_str+" (fecha,id_pais,id_region,cant) VALUES (";
    int count =0;
    for (int i=4;i<datos_csv.size();i++){
        if (datos_csv.at(i)!="-1"){
            linea_insertar += "'" + nombres_campos_csv->at(i) + "','"
                                  + id_pais + "','" + id_region + "','" + datos_csv.at(i) + "'";

            if (i<datos_csv.size()-1){
                linea_insertar += "),(";
            }
            count ++;
        }
    }
    linea_insertar += ")";
    if (count > 0){
        //DEBUG: Muestro la línea de SQL restante
        //qDebug() << linea_insertar;

        //Ejecuto el insert y controlo que se realice correctamente
        r = base.insertar(linea_insertar);
        if (!r){
            qDebug() << "Error insertando datos" ;
        }
    }

    //DEBUG: mostrar en pantalla el punto de ejecución actual
    //qDebug() << "actualizar_datos_region completo";

    //Liberamos el motor de trabajo
    this->liberar();

    return r;
}

bool CsvToDb::actualizar_tabla(QString str_csv, QString str_tabla)
{
    this->set_tabla(str_tabla);
    this->set_csv(str_csv);

    this->leer_csv();
    this->actualizar_paises();
    this->actualizar_regiones();

    for (int i=0;i< lineas_csv->size();i++){
        this->actualizar_datos_region(lineas_csv->at(i),tabla);
        emit progreso(tabla,lineas_csv->size(),i+1);
    }

    //DEBUG: mostrar en pantalla el punto de ejecución actual
    //qDebug() << "actualizar_tabla completo, tabla = " + tabla;
    this->limpiar();
    this->forzar_actualizacion = false;
    return true;
}

QStringList CsvToDb::getPaises()
{
    QStringList r;
    QVector<QStringList> paises_bd = base.consulta("SELECT pais FROM paises ORDER BY pais");
    if (paises_bd.size()<=0){
        this->forzar_actualizacion = true;
    }
    for (int i=0;i<paises_bd.size();i++){
        r.append(paises_bd.at(i));
    }
    return r;
}

QStringList CsvToDb::getRegiones(QString pais)
{
    QStringList r;
    QString idPais = this->get_id_pais(pais);
    QVector<QStringList> regiones_bd;
    if (idPais != "0"){
        regiones_bd = base.consulta("SELECT region FROM regiones WHERE id_pais = '"+idPais+"' ORDER BY region");
        for (int i=0; i< regiones_bd.size();i++){
            r.append(regiones_bd.at(i));
        }
    }
    return r;
}

void CsvToDb::actualizar_paises()
{
    //Si por alguna razón está ocupado el motor de procesamiento (Por si no se terminó una tarea anterior),
    //esperamos que se libere. Ésto ayuda a mantener un orden secuencial en el trabajo.
    //La secuencialidad es escencial para un correcto manejo de base de datos, cuyo acceso debe ser secuencial
    this->esperar_motor();
    //Una vez liberado el motor, lo ocupamos para realizar las tareas necesarias
    this->ocupar();

    //cargo en memoria la tabla paises
    QVector< QStringList > paises_bd = base.consulta("SELECT pais FROM paises");
    QVector< QString > paises_csv;

    //Extraigo y guardo en paises_csv todos los países que estén cargados en el csv;
    for (int i=0;i<lineas_csv->size();i++){
        //En una sola linea divido cada línea del csv por las comas y extraigo el pais de esa línea
        paises_csv.append(lineas_csv->at(i).split(',').at(1));
    }

    //Recorro los paises cargados en el csv y veo si se encuentran en la bd.
    for (int i=0;i<paises_csv.size();i++){
        for (int j=0;j<paises_bd.size();j++){
            if (paises_bd.at(j).contains(paises_csv.at(i))){
                //Al encontrar coincidencia, elimino la region de regiones_csv.Esto hace que el elemento en i+1 pase a estar en la
                //posición i, y por ello debo retroceder un índice (i--) para que ese elemento nuevo en i sea tomado en cuenta
                //(recordemos que el for aumenta el valor de i en cada iteración)
                paises_csv.remove(i);
                i--;
                break;
            }
        }
    }

    //Recorro el vector del csv para eliminar los elementos repetidos
    for (int i=0; i< paises_csv.size()-1;i++){
        for (int j=i+1;j<paises_csv.size();j++){
            if (paises_csv.at(j)==paises_csv.at(i)){
                paises_csv.remove(j);
                j--;
            }
        }
    }

    if (paises_csv.size()>0){
        //Genero una línea de sql para insertar en una sola conexión todas los paises pendientes de insertar en la bd
        //Ésto disminuirá el tiempo de acceso al disco, aumentando la performance
        QString linea_insertar;
        linea_insertar = "INSERT INTO paises (pais) VALUES (";

        for (int i=0;i< paises_csv.size();i++){
            linea_insertar += "'" + paises_csv.at(i) + "'";
            if (i<paises_csv.size()-1){
                linea_insertar += "),(";
            }
        }
        linea_insertar += ")";

        //DEBUG: Muestro la línea de SQL restante
        //qDebug() << linea_insertar;

        //Ejecuto el insert y controlo que se realice correctamente
        if (!base.insertar(linea_insertar)){
            qDebug() << "Error insertando paises" ;
        }
    }

    //DEBUG: mostrar en pantalla el punto de ejecución actual
    //qDebug() << "actualizar_paises completo";

    //Liberamos el motor de trabajo
    this->liberar();
}

void CsvToDb::actualizar_regiones()
{
    //Si por alguna razón está ocupado el motor de procesamiento (Por si no se terminó una tarea anterior),
    //esperamos que se libere. Ésto ayuda a mantener un orden secuencial en el trabajo.
    //La secuencialidad es escencial para un correcto manejo de base de datos, cuyo acceso debe ser secuencial
    this->esperar_motor();
    //Una vez liberado el motor, lo ocupamos para realizar las tareas necesarias
    this->ocupar();

    //cargo en memoria la tabla paises
    QVector< QStringList > paises_bd = base.consulta("SELECT * FROM paises");
    //cargo en memoria la tabla regiones (sin tomar en cuenta el id, ya que no lo necesito)
    QVector< QStringList > regiones_bd = base.consulta("SELECT region,id_pais FROM regiones");
    QVector< QStringList > regiones_csv;

    //Extraigo y guardo en regiones_csv todas las regiones y sus países que estén cargados en el csv;
    for (int i=0;i<lineas_csv->size();i++){
        QStringList aux;
        //En una sola linea divido cada línea del csv por las comas y extraigo la region de esa línea
        aux.append(lineas_csv->at(i).split(',').at(0));
        //En una sola linea divido cada línea del csv por las comas y extraigo el pais de esa línea
        aux.append(lineas_csv->at(i).split(',').at(1));
        regiones_csv.append(aux);
    }

    //Recorro todas las regiones del csv y las busco en la bd. Si ya están en la bd, las elimino del vector regiones_csv
    for (int i=0;i<regiones_csv.size();i++){
        //Busco si hay regiones vacías ("") en el csv y las ignoro, ya que a esa region le corresponde solo el pais
        // y previo a la llamada de actualizar_regiones habré llamado a actualizar_paises,
        //actualizando todos los paises en la bd
       if (regiones_csv.at(i).at(0) == ""){
           //Si encuentra región vacía, la elimino del vector. Esto hace que el elemento en i+1 pase a estar en la
           //posición i, y por ello debo retroceder un índice (i--) para que ese elemento nuevo en i sea tomado en cuenta
           //(recordemos que el for aumenta el valor de i en cada iteración)
           regiones_csv.remove(i);
           i--;
           continue;
       }

       for (int j=0;j<regiones_bd.size();j++){
           //Busco una coincidencia de regiones
           if (regiones_csv.at(i).at(0) == regiones_bd.at(j).at(0)){

               // Armo el stringlist aux = {id_pais de la tabla, pais del csv}
               QStringList aux;
               aux.append(regiones_bd.at(j).at(1));
               aux.append(regiones_csv.at(i).at(1));

               //Si aux está en la tabla paises, significa que la region (i) del csv está en la tabla regiones,
               //ya que el id_pais asociado a la region (j) de la tabla corresponde al pais asociado a la region (i)
               //del csv (indexOf devuelve -1 si no encuentra lo que busca)
               if (paises_bd.indexOf(aux)!=-1){
                   //Al encontrar coincidencia, elimino la region de regiones_csv.Esto hace que el elemento en i+1 pase a estar en la
                   //posición i, y por ello debo retroceder un índice (i--) para que ese elemento nuevo en i sea tomado en cuenta
                   //(recordemos que el for aumenta el valor de i en cada iteración)
                   regiones_csv.remove(i);
                   i--;
                   break;
               }
           }
       }
    }

    if (regiones_csv.size()>0){
        //Genero una línea de sql para insertar en una sola conexión todas las regiones pendientes de insertar en la bd
        //Ésto disminuirá el tiempo de acceso al disco, aumentando la performance
        QString linea_insertar;
        linea_insertar = "INSERT INTO regiones (region,id_pais) VALUES (";

        //Separo los paises de la bd en 2 listas con indice correlativo, de modo de poder hacer una comparación rápida
        // de regiones_csv.at(i).at(1) (el pais en el csv) y hallar rápidamente el id correspondiente para insertar
        QStringList id_paises, pais_paises;
        for (int i=0;i<paises_bd.size();i++){
            id_paises.append(paises_bd.at(i).at(0));
            pais_paises.append(paises_bd.at(i).at(1));
        }

        for (int i=0;i< regiones_csv.size();i++){
            linea_insertar += "'" + regiones_csv.at(i).at(0) + "','"
                                  + id_paises.at(pais_paises.indexOf(regiones_csv.at(i).at(1))) + "'";
            if (i<regiones_csv.size()-1){
                linea_insertar += "),(";
            }
        }
        linea_insertar += ")";

        //DEBUG: Muestro la línea de SQL restante
        //qDebug() << linea_insertar;

        //Ejecuto el insert y controlo que se realice correctamente
        if (!base.insertar(linea_insertar)){
            qDebug() << "Error insertando regiones" ;
        }
    }

    //DEBUG: mostrar en pantalla el punto de ejecución actual
    //qDebug() << "actualizar_regiones completo";

    //Liberamos el motor de trabajo
    this->liberar();
}

void CsvToDb::cargar_csv(QNetworkReply *reply)
{
    //Si por alguna razón está ocupado el motor de procesamiento (Por si no se terminó una tarea anterior),
    //esperamos que se libere. Ésto ayuda a mantener un orden secuencial en el trabajo.
    //La secuencialidad es escencial para un correcto manejo de base de datos, cuyo acceso debe ser secuencial
    this->esperar_motor();
    //Una vez liberado el motor, lo ocupamos para realizar las tareas necesarias
    this->ocupar();

    //Obtengo todos los bytes que vienen den manager a traves de reply
    QByteArray ba = reply->readAll();

    //almaceno en lineas_csv los datos del csv, separados en líneas utilizando el \n como separador
    *lineas_csv = ba.split('\n');

    //Controlo que el csv no esté vacío y extraigo la pirmer línea, la cual contiene el nombre de todos los campos
    if ( ! lineas_csv->isEmpty() )  {
        *nombres_campos_csv = lineas_csv->at( 0 ).split( ',' );
        lineas_csv->removeFirst();
    }

    //El siguiente es un proceso por el cual se 'limpian impurezas' tales como nombres con '' o regiones con ,
    //(la coma la remplaza por un punto, ya que la coma es separador de campos)
    QList< QByteArray > datos_linea;
    for (int i=0; i<lineas_csv->size()-1; i++){
        datos_linea.clear();

        if ( lineas_csv->at( i ).contains( "\"" ) && lineas_csv->at( i ).split( ',' ).size() != nombres_campos_csv->size() )  {
            QString linea_con_comillas = lineas_csv->at( i );

            int primer_comilla = linea_con_comillas.indexOf( "\"" );
            int segunda_comilla = linea_con_comillas.indexOf( "\"", primer_comilla + 1 );

            QString cadena_con_coma = linea_con_comillas.mid( primer_comilla, segunda_comilla - primer_comilla );
            cadena_con_coma.replace( ",", "." );

            linea_con_comillas.replace( primer_comilla, segunda_comilla - primer_comilla, cadena_con_coma );
            linea_con_comillas.replace("\"","");
            lineas_csv->replace( i, linea_con_comillas.toUtf8() );
        }
        if (lineas_csv->at(i).contains("\'")){
            QString remplazo = lineas_csv->at(i);
            remplazo.replace("\'"," ");
            lineas_csv->replace(i,remplazo.toUtf8());
        }
    }

    if (!lineas_csv->isEmpty()){
        lineas_csv->removeLast();
    }

    emit csv_cargado();

    //Liberamos el motor de trabajo
    this->liberar();

    //DEBUG: mostrar en pantalla el punto de ejecución actual
    //qDebug() << "cargar_csv completo";
}

void CsvToDb::liberar_motor()
{
    this->liberar();
}
