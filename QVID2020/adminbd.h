#ifndef ADMINBD_H
#define ADMINBD_H

//Clase base
#include <QObject>

//Clases SQL
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlResult>
#include <QVariant>  //Tipo devuelto por query.value
#include <QtSql>

//Clases auxiliares
#include <QFileInfo>
#include <QString>
#include <QVector>
#include <QMessageBox>
#include <QDebug>

class AdminBD : public QObject
{
    Q_OBJECT
public:
    explicit AdminBD( QObject * parent = nullptr );
    ~AdminBD();

    int conectar( QString str_arch_bd );
    int conectar (QString host, QString base, QString user, QString pass, QString tipo, QString puerto);
    QVector< QStringList > consulta ( QString str_consulta);
    bool insertar(QString str_dato);

    bool is_conected();
    bool comprobar_tabla( QString tabla );
    void cerrar();

private:
    QString * str_base;
    QSqlDatabase bd;

public slots:

private slots:

signals:

};

#endif // ADMINBD_H
