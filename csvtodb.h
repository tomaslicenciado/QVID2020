#ifndef CSVTODB_H
#define CSVTODB_H

#define BD_STR "../bd/bd.sqlite"

//Clase base
#include <QObject>

//Clases de conectividad
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>

//Clases auxiliares
#include <QDebug>
#include <QString>
#include <QVector>
#include <QMessageBox>
#include <QTimer>
#include <QEventLoop>

//Clase de manejo de base de datos
#include "adminbd.h"

class CsvToDb : public QObject
{
    Q_OBJECT
public:
    explicit CsvToDb(QObject *parent = nullptr);
    ~CsvToDb();

    bool actualizar_tabla(QString str_csv, QString str_tabla);
    QStringList getPaises();
    QStringList getRegiones(QString pais);
    QString get_id_pais(QString pais);
    QString get_id_region(QString region, QString id_pais);
    QVector<QStringList> obtener_datos(QString consulta);
    QVector<QStringList> acumular_datos(QVector<QStringList> orig);



    bool getForzar_actualizacion() const;

private:
    QNetworkAccessManager * manager;
    QString tabla;
    QString csv_url_str;
    QList<QByteArray> *nombres_campos_csv;
    QList<QByteArray> *lineas_csv;
    bool motor_libre;
    AdminBD base;
    bool forzar_actualizacion;

    bool leer_csv();
    bool esta_libre();
    void ocupar();
    void liberar();
    void set_csv(QString str_url);
    void set_tabla(QString str_tabla);
    void esperar_motor();
    void limpiar();

    bool actualizar_datos_region(QByteArray linea,QString tabla);
    void actualizar_paises();
    void actualizar_regiones();

public slots:

private slots:
    void cargar_csv(QNetworkReply* reply);
    void liberar_motor();

signals:
    void csv_cargado();
    void progreso(QString,int,int);

};

#endif // CSVTODB_H
