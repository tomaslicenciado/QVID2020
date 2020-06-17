#include "interfazsir.h"
#include "ui_interfazsir.h"
#include <QPen>
#include <QPaintDevice>
#include <QPainter>
#include <QTimer>
#include <QPainterPath>

InterfazSIR::InterfazSIR(CsvToDb *conect, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InterfazSIR)
{
    graficado=false;
    datos_SIR.clear();
    datosBDPais.clear();
    if (conect != nullptr){
        conexion=conect;
    }
    else {
        conexion = new CsvToDb;
    }
    ui->setupUi(this);
    ui->rbDatos->toggle();
    ui->tabGraficos->setCurrentIndex(0);
    connect(ui->tabGraficos,SIGNAL(currentChanged(int)),this,SLOT(elegir_grafico(int)));

    connect(ui->rbDatos,SIGNAL(clicked()),this,SLOT(rbOpc()));
    connect(ui->rbHistorico,SIGNAL(clicked()),this,SLOT(rbOpc()));
}

InterfazSIR::~InterfazSIR()
{
    delete ui;
}


void InterfazSIR::iniciar(const QString pais_a_graficar)
{
    pais = pais_a_graficar;
    ui->tabGraficos->setCurrentIndex(0);
    this->setWindowTitle(pais);
    this->show();
}

void InterfazSIR::salir()
{
    QVector<QPainterPath>empty;
    ui->tabSIRM->setPoligonos(empty);
    ui->tabSIRM->repaint();
    ui->tabSIRM->close();
    ui->tabCRM->close();
    calculador.limpiarDatos();
    datos_SIR.clear();
    datosBDPais.clear();
    fechas.clear();
    ui->leC->clear();
    ui->leS->clear();
    ui->leM->clear();
    ui->leR->clear();
    ui->leN->clear();
    ui->leDInc->clear();
    ui->leDInf->clear();
    ui->leTC->clear();
    ui->rbDatos->toggle();
    graficado=false;
    this->close();
}

void InterfazSIR::graficar_SIRM()
{
    ui->tabSIRM->setDatos(datos_SIR);
    QVector<QPainterPath> poligonos;
    QVector<QPen> lapices;
    QPainterPath polSu,polIn,polRec,polMu;

    QPen lapizNegro(Qt::black);
    QPen lapizAzul(Qt::blue);
    QPen lapizVerde(Qt::green);
    QPen lapizRojo(Qt::red);
    lapizNegro.setWidth(2);
    lapizAzul.setWidth(2);
    lapizRojo.setWidth(2);
    lapizVerde.setWidth(2);

    lapices.append(lapizNegro);
    lapices.append(lapizAzul);
    lapices.append(lapizVerde);
    lapices.append(lapizRojo);

    polSu.clear();
    polIn.clear();
    polRec.clear();
    polMu.clear();

//    poligonos.append(polSu);
//    poligonos.append(polIn);
//    poligonos.append(polRec);
//    poligonos.append(polMu);

    ui->tabSIRM->setLapices(lapices);
    //ui->tabSIRM->setPoligonos(poligonos);

    float pasox = ((float)ui->tabSIRM->width()*0.96) / (float)datos_SIR.size();
    float pasoy = ((float)ui->tabSIRM->height()*0.96) / (float)popPais;
    float x = (float)ui->tabSIRM->width()*0.02;
    float y = (float)ui->tabSIRM->height()*0.98;

    for (int i=0;i<datos_SIR.size();i++){
        if (i==0){
            polSu.moveTo(QPointF(x+(float)i*pasox,y - (float)datos_SIR.at(i).at(0)*pasoy));
            polIn.moveTo(QPointF(x+(float)i*pasox,y - (float)datos_SIR.at(i).at(1)*pasoy));
            polRec.moveTo(QPointF(x+(float)i*pasox,y - (float)datos_SIR.at(i).at(2)*pasoy));
            polMu.moveTo(QPointF(x+(float)i*pasox,y - (float)datos_SIR.at(i).at(3)*pasoy));
        }
        polSu.lineTo(QPointF(x+(float)i*pasox,y - (float)datos_SIR.at(i).at(0)*pasoy));
        poligonos.append(polSu);
        polIn.lineTo(QPointF(x+(float)i*pasox,y - (float)datos_SIR.at(i).at(1)*pasoy));
        poligonos.append(polIn);
        polRec.lineTo(QPointF(x+(float)i*pasox,y - (float)datos_SIR.at(i).at(2)*pasoy));
        poligonos.append(polRec);
        polMu.lineTo(QPointF(x+(float)i*pasox,y - (float)datos_SIR.at(i).at(3)*pasoy));
        poligonos.append(polMu);
        ui->tabSIRM->setPoligonos(poligonos);
        ui->tabSIRM->repaint();
        poligonos.clear();
    }
}

void InterfazSIR::graficar_CRM()
{
    ui->tabCRM->setDatos(datos_SIR);
    QVector<QPainterPath> poligonos;
    QVector<QPen> lapices;
    QPainterPath polIn,polRec,polMu;

    QPen lapizAzul(Qt::blue);
    QPen lapizVerde(Qt::green);
    QPen lapizRojo(Qt::red);
    lapizAzul.setWidth(2);
    lapizRojo.setWidth(2);
    lapizVerde.setWidth(2);

    lapices.append(lapizAzul);
    lapices.append(lapizVerde);
    lapices.append(lapizRojo);

    polIn.clear();
    polRec.clear();
    polMu.clear();

    ui->tabCRM->setLapices(lapices);
    //ui->tabSIRM->setPoligonos(poligonos);

    float pasox = ((float)ui->tabSIRM->width()*0.96) / (float)datos_SIR.size();
    float pasoy = ((float)ui->tabSIRM->height()*0.96) / (float)popPais;
    float x = (float)ui->tabSIRM->width()*0.02;
    float y = (float)ui->tabSIRM->height()*0.98;

    for (int i=0;i<datos_SIR.size();i++){
        if (i==0){
            polIn.moveTo(QPointF(x+(float)i*pasox,y - ((float)datos_SIR.at(i).at(1) + (float)datos_SIR.at(i).at(2)
                                                       + (float)datos_SIR.at(i).at(3))*pasoy));
            polRec.moveTo(QPointF(x+(float)i*pasox,y - (float)datos_SIR.at(i).at(2)*pasoy));
            polMu.moveTo(QPointF(x+(float)i*pasox,y - (float)datos_SIR.at(i).at(3)*pasoy));
        }
        polIn.lineTo(QPointF(x+(float)i*pasox,y - ((float)datos_SIR.at(i).at(1) + (float)datos_SIR.at(i).at(2) +
                                                   (float)datos_SIR.at(i).at(3))*pasoy));
        poligonos.append(polIn);
        polRec.lineTo(QPointF(x+(float)i*pasox,y - (float)datos_SIR.at(i).at(2)*pasoy));
        poligonos.append(polRec);
        polMu.lineTo(QPointF(x+(float)i*pasox,y - (float)datos_SIR.at(i).at(3)*pasoy));
        poligonos.append(polMu);
        ui->tabCRM->setPoligonos(poligonos);
        ui->tabCRM->repaint();
        poligonos.clear();
    }
}

void InterfazSIR::paintEvent(QPaintEvent *)
{


}

void InterfazSIR::rbOpc()
{
    if (ui->rbDatos->isChecked()){
        ui->rbHistorico->setChecked(false);
    }
    if (ui->rbHistorico->isChecked()){
        ui->rbDatos->setChecked(false);
    }
}

void InterfazSIR::elegir_grafico(int pestania)
{
    if (graficado){
        if (pestania==0){
            graficar_CRM();
        }
        else{
            graficar_SIRM();
        }
    }
}

void InterfazSIR::iniciarGraficos()
{
    fechas = conexion->obtener_datos("SELECT fecha FROM confirmados WHERE"
                                     " id_pais ='"+conexion->get_id_pais(pais)+"' ORDER BY fecha");
    QVector<QVector<int>> datosIntPais;

    datosBDPais.append(conexion->obtener_datos("SELECT cant FROM confirmados WHERE"
                                               " id_pais ='"+conexion->get_id_pais(pais)+"' ORDER BY fecha"));
    datosBDPais.append(conexion->obtener_datos("SELECT cant FROM recuperados WHERE"
                                               " id_pais ='"+conexion->get_id_pais(pais)+"' ORDER BY fecha"));
    datosBDPais.append(conexion->obtener_datos("SELECT cant FROM muertes WHERE"
                                               " id_pais ='"+conexion->get_id_pais(pais)+"' ORDER BY fecha"));

    for (int i=0;i<datosBDPais.size();i++){
        QVector<int> aux;
        for (int j=0;j<datosBDPais.at(i).size();j++){
            aux.append(datosBDPais.at(i).at(j).at(0).toInt());
        }
        datosIntPais.append(aux);
    }
    popPais = conexion->obtener_datos("SELECT poblacion FROM poblaciones WHERE pais = '"+pais+"'").at(0).at(0).toInt();
    /*
     * setear datos basicsir dependiendo de las opciones elegidas en el ui
     * calcular sir
     */
    double gama,beta;
    if (ui->rbDatos->isChecked()){
        gama = 1/ui->leDInf->text().toDouble();
        beta = ui->leTC->text().toDouble();
        calculador.setear_datos(popPais,ui->leS->text().toInt(),ui->leC->text().toInt() - ui->leR->text().toInt() -
                                ui->leM->text().toInt(),ui->leR->text().toInt(),gama,beta);
    }
    else {
        int cSize=datosIntPais.at(0).size();
        int rSize=datosIntPais.at(1).size();
        int mSize=datosIntPais.at(2).size();
        int s=popPais - datosIntPais.at(0).at(cSize-1);
        int i=datosIntPais.at(0).at(cSize-1)-datosIntPais.at(1).at(rSize-1)-datosIntPais.at(2).at(mSize-1);
        gama=1.0/7.0;
        beta = 2.68;
        calculador.setear_datos(popPais,s,i,datosIntPais.at(1).at(rSize-1),gama,beta);
        ui->leN->setText(QString::number(popPais));
        ui->leC->setText(QString::number(datosIntPais.at(0).at(cSize-1)));
        ui->leM->setText(QString::number(datosIntPais.at(2).at(mSize-1)));
        ui->leR->setText(QString::number(datosIntPais.at(1).at(rSize-1)));
        ui->leS->setText(QString::number(s));
        ui->leTC->setText(QString::number(beta));
        ui->leDInf->setText("7");
        ui->leDInc->setText("5");
    }

    datos_SIR = calculador.calSIR(ui->sbPeriodo->value());
    graficado=true;
    ui->tabGraficos->setCurrentIndex(0);
    this->graficar_CRM();
}
