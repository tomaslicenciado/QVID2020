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

QVector<QStringList> AdminBD::consulta(QString str_consulta)
{
    QVector< QStringList > resultado;
    QStringList aux;
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
    QSqlQuery query(bd);
    return query.exec(str_dato);
}

bool AdminBD::is_conected()
{
    return bd.isOpen();
}

bool AdminBD::comprobar_tabla(QString tabla)
{
    QStringList tablas = bd.tables();
    return tablas.contains(tabla);
}

void AdminBD::cerrar()
{
    if (bd.isOpen()){
        bd.close();
    }
}
