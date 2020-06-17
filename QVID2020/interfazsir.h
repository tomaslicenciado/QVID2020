#ifndef INTERFAZSIR_H
#define INTERFAZSIR_H

#include <QWidget>
#include "csvtodb.h"
#include "basicsir.h"
#include <QString>
#include <QPointF>
#include <QVector>

namespace Ui {
class InterfazSIR;
}

class InterfazSIR : public QWidget
{
    Q_OBJECT

public:
    explicit InterfazSIR(CsvToDb* conect = nullptr, QWidget *parent = nullptr);
    ~InterfazSIR();

private:
    Ui::InterfazSIR *ui;
    CsvToDb* conexion;
    QString pais;
    int popPais;
    BasicSIR calculador;
    QVector<QVector<double>> datos_SIR; //suceptibles, infectados, recuperados, muertos
    QVector<QStringList> fechas;
    QVector<QVector<QStringList>> datosBDPais;
    bool graficado;

    void graficar_SIRM(); //Graficar suceptibles, infectados, recuperados y muertos
    void graficar_CRM();  //Graficar Confirmados, recuperados y muertos. Confirmados = Infectados + Recuperados + Muertos
    void paintEvent(QPaintEvent *event) override;

protected:

public slots:
    void iniciar(const QString pais_a_graficar);
    void salir();

private slots:
    void rbOpc();
    void elegir_grafico(int pestania);
    void iniciarGraficos();
};

#endif // INTERFAZSIR_H
