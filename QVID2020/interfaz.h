#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <QWidget>
#include <QPaintDevice>
#include <QPainter>
#include <QMouseEvent>
#include <QToolTip>
#include "csvtodb.h"

namespace Ui {
class Interfaz;
}

class Interfaz : public QWidget
{
    Q_OBJECT

public:
    explicit Interfaz(QWidget *parent = nullptr);
    ~Interfaz();

private:
    Ui::Interfaz *ui;
    CsvToDb *netcsv;
    QString pais;
    QString region;
    QVector<QStringList> dat_recup;
    QVector<QStringList> dat_confir;
    QVector<QStringList> dat_muert;

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void listar_regiones(QString pais);
    void calcular_datos();
    void actualizar_bd();
    void proximamente();
    void mostrarProgreso(QString strTabla,int maxV,int actV);
    void forzarAct();

public slots:

signals:
    void sRango(int,int);
    void sValor(int);
    void sTexto(QString);

};

#endif // INTERFAZ_H
