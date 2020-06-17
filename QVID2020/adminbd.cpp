#include "adminbd.h"

AdminBD::AdminBD(QObject *parent):QObject(parent)
{
    bd = QSqlDatabase::addDatabase( "QSQLITE" );
}

AdminBD::~AdminBD()
{
    if (bd.isOpen()){
        bd.close();
    }
}

int AdminBD::conectar(QString str_arch_bd)
{
    bool existe_bd = QFileInfo::exists(str_arch_bd);
    bd.setDatabaseName(str_arch_bd);
    if (!existe_bd){
        QMessageBox::warning(nullptr,"Base de datos nueva","No se encontró la base de datos, por lo que se creará una nueva.");
        if (bd.open()){
            QSqlQuery query(bd);
            query.exec("CREATE TABLE paises (id integer primary key autoincrement, pais varchar(250))");
            query.exec("CREATE TABLE regiones (id integer primary key autoincrement, region varchar(250), id_pais int)");
            query.exec("CREATE TABLE confirmados (id integer primary key autoincrement, fecha varchar(250), id_pais int, id_region int, cant int)");
            query.exec("CREATE TABLE muertes (id integer primary key autoincrement, fecha varchar(250), id_pais int, id_region int, cant int)");
            query.exec("CREATE TABLE recuperados (id integer primary key autoincrement, fecha varchar(250), id_pais int, id_region int, cant int)");
            //bd.close();
            QMessageBox::information(nullptr,"Base creada","Finalizó la creación de la base de datos");
            return 2;
        }
        else {
            QMessageBox::critical(nullptr,"ERROR","Hubo un error en la apertura de la base de datos");
            return 0;
        }
    }
    if (!bd.open()){
        return 0;
    }
    return 1;
}

int AdminBD::conectar(QString host, QString base, QString user, QString pass, QString tipo, QString puerto)
{
    if (bd.isOpen()){
        bd.close();
    }

    bd = QSqlDatabase::addDatabase(tipo);
    bd.setHostName(host);
    bd.setPort(puerto.toInt());
    bd.setUserName(user);
    bd.setPassword(pass);
    bd.setDatabaseName(base);

    if (!bd.open()){
        QMessageBox::critical(nullptr,"ERROR CONEXION BD "+tipo,"Hubo un error en la conexión con la base "+base);
        return 0;
    }
    else {
        if (comprobar_tabla("paises")){
            return 1;
        }
        else {
            QSqlQuery query(bd);
            query.exec("CREATE TABLE IF NOT EXISTS `xfnfttiw_db_covid19`.`paises` ( `id` INT NOT NULL AUTO_INCREMENT , `pais` VARCHAR(250) NOT NULL , PRIMARY KEY (`id`)) ENGINE = MyISAM;");
            query.exec("CREATE TABLE IF NOT EXISTS `xfnfttiw_db_covid19`.`regiones` ( `id` INT NOT NULL AUTO_INCREMENT , `region` VARCHAR(250) NOT NULL , `id_pais` INT, PRIMARY KEY (`id`)) ENGINE = MyISAM;");
            query.exec("CREATE TABLE IF NOT EXISTS `xfnfttiw_db_covid19`.`confirmados` ( `id` INT NOT NULL AUTO_INCREMENT , `fecha` VARCHAR(250) NOT NULL , `id_pais` INT, `id_region` INT, `cant` INT, PRIMARY KEY (`id`)) ENGINE = MyISAM;");
            query.exec("CREATE TABLE IF NOT EXISTS `xfnfttiw_db_covid19`.`muertes` ( `id` INT NOT NULL AUTO_INCREMENT , `fecha` VARCHAR(250) NOT NULL , `id_pais` INT, `id_region` INT, `cant` INT, PRIMARY KEY (`id`)) ENGINE = MyISAM;");
            query.exec("CREATE TABLE IF NOT EXISTS `xfnfttiw_db_covid19`.`recuperados` ( `id` INT NOT NULL AUTO_INCREMENT , `fecha` VARCHAR(250) NOT NULL , `id_pais` INT, `id_region` INT, `cant` INT, PRIMARY KEY (`id`)) ENGINE = MyISAM;");
            QMessageBox::warning(nullptr,"Base de datos vacía","La base de datos se encuentra vacía. Debe actualizarla.");
            return 2;
        }
    }
}

QVector<QStringList> AdminBD::consulta(QString str_consulta)
{
    QVector< QStringList > resultado;
    QStringList aux;
    if (!this->is_conected()){
        bd.open();
    }
    if (this->is_conected()){
        QSqlQuery query (bd);
        QSqlRecord record;

        if (query.exec(str_consulta)){

            while (query.next()) {
                aux.clear();
                record = query.record();
                int campos = record.count();

                for (int i=0;i<campos;i++){
                    aux.append(record.value(i).toString());
                }

                resultado.append(aux);
            }
        }
    }

    return resultado;
}

bool AdminBD::insertar(QString str_dato)
{
    if (!this->is_conected()){
        bd.open();
    }
    QSqlQuery query(bd);
    return query.exec(str_dato);
}

bool AdminBD::is_conected()
{
    return bd.isOpen();
}

bool AdminBD::comprobar_tabla(QString tabla)
{
    if (!this->is_conected()){
        bd.open();
    }
    QStringList tablas = bd.tables();
    return tablas.contains(tabla);
}

void AdminBD::cerrar()
{
    if (bd.isOpen()){
        bd.close();
    }
}
