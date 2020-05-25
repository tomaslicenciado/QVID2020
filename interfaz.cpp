#include "interfaz.h"
#include "ui_interfaz.h"

Interfaz::Interfaz(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Interfaz),
    netcsv(new CsvToDb)
{
    ui->setupUi(this);
    this->setWindowTitle("Proyecto QVID-19   v2.0");

    ui->prbProgreso->setValue(0);
    ui->prbProgreso->setTextVisible(false);

    ui->listPaises->addItems(netcsv->getPaises());
    if (netcsv->getForzar_actualizacion()){
        this->forzarAct();
    }
}

Interfaz::~Interfaz()
{
    delete ui;
    delete netcsv;
}

void Interfaz::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPoint esquin_arriba_izq(10,80);
    QPoint esquin_abajo_der(this->width() - 70, this->height() - 75);
    ui->teInfo->viewport()->setAutoFillBackground(false);
    QPen lapiz;
    lapiz.setColor(QColor(0,0,0));
    painter.setPen(lapiz);
    painter.fillRect(QRect(0,0,this->width(),this->height()),QColor(174,23,23));
    painter.drawImage(this->width()-140,7,QImage("../bd/UBPLogo.png").scaled(130,50));
    painter.drawRect(QRect(esquin_arriba_izq,esquin_abajo_der));
    painter.fillRect(QRect(esquin_arriba_izq,esquin_abajo_der),QColor(0,0,0));
    QFont serifFont("Times", 10, QFont::Bold);
    lapiz.setColor(QColor(255,255,0));
    lapiz.setWidth(5);
    painter.setPen(lapiz);
    painter.drawRect(QRect(ui->teInfo->pos().x(),ui->teInfo->pos().y(),ui->teInfo->width(),ui->teInfo->height()));
    ui->teInfo->setFont(serifFont);
    ui->lCero->setText("<font color='white'>0</font>");

    //Busco el número más grande de contagios/recuperados/muertos para realizar la escala
    int maxCant=0;
    for (int i=0;i<dat_confir.size();i++){
        if (maxCant < dat_confir.at(i).at(1).toInt()){
            maxCant = dat_confir.at(i).at(1).toInt();
        }
    }
    for (int i=0;i<dat_muert.size();i++){
        if (maxCant < dat_muert.at(i).at(1).toInt()){
            maxCant = dat_muert.at(i).at(1).toInt();
        }
    }
    for (int i=0;i<dat_recup.size();i++){
        if (maxCant < dat_recup.at(i).at(1).toInt()){
            maxCant = dat_recup.at(i).at(1).toInt();
        }
    }

    //Calculo los pasos para las distancias de puntos
    float pasoy = float(esquin_arriba_izq.y() - esquin_abajo_der.y()) / float(maxCant);
    float pasox = float(esquin_abajo_der.x() - esquin_arriba_izq.x()) / float(dat_confir.size());
    float x1 = esquin_arriba_izq.x();
    float y1 = esquin_abajo_der.y();
    float x2 = x1;
    float y2 = y1;

    lapiz.setWidth(5);
    if (ui->chkConfir->isChecked()){
        lapiz.setColor(QColor(0,0,255));
        painter.setPen(lapiz);
        for (int i=0;i<dat_confir.size();i++){
            x2 = x1 + pasox;
            y2 = esquin_abajo_der.y() + (dat_confir.at(i).at(1).toFloat() * pasoy);
            painter.drawLine(QLineF(x1,y1,x2,y2));
            x1 = x2;
            y1 = y2;
        }
    }

    x1 = esquin_arriba_izq.x();
    y1 = esquin_abajo_der.y();
    x2 = x1;
    y2 = y1;
    if (ui->chkRecup->isChecked()){
        lapiz.setColor(QColor(0,175,0));
        painter.setPen(lapiz);
        for (int i=0;i<dat_recup.size();i++){
            x2 = x1 + pasox;
            y2 = esquin_abajo_der.y() + (dat_recup.at(i).at(1).toFloat() * pasoy);
            painter.drawLine(QLineF(x1,y1,x2,y2));
            x1 = x2;
            y1 = y2;
        }
    }

    x1 = esquin_arriba_izq.x();
    y1 = esquin_abajo_der.y();
    x2 = x1;
    y2 = y1;
    if (ui->chkMuert->isChecked()){
        lapiz.setColor(QColor(250,0,0));
        painter.setPen(lapiz);
        for (int i=0;i<dat_muert.size();i++){
            x2 = x1 + pasox;
            y2 = esquin_abajo_der.y() + (dat_muert.at(i).at(1).toFloat() * pasoy);
            painter.drawLine(QLineF(x1,y1,x2,y2));
            x1 = x2;
            y1 = y2;
        }
    }

    if (!netcsv->getForzar_actualizacion()){
        ui->listPaises->setEnabled(true);
        ui->listRegiones->setEnabled(true);
        ui->pbCalcular->setEnabled(true);
        ui->pbComparar->setEnabled(true);
        ui->chkMuert->setEnabled(true);
        ui->chkRecup->setEnabled(true);
        ui->chkConfir->setEnabled(true);
        ui->pbComparar->setToolTip("Aún no disponible");
        ui->listPaises->setToolTip("Listado de países");
        ui->listRegiones->setToolTip("Listado de regiones del país seleccionado.");
        ui->pbCalcular->setToolTip("Calcular los datos a graficar");
        ui->chkMuert->setToolTip("Mostrar gráfica de Muertes");
        ui->chkRecup->setToolTip("Mostrar gráfica de Recuperados");
        ui->chkConfir->setToolTip("Mostrar gráfica de Confirmados");
        ui->pbActualizar->setDefault(false);
    }
}

void Interfaz::listar_regiones(QString pais)
{
    QStringList reg = netcsv->getRegiones(pais);
    ui->listRegiones->clear();
    if (reg.size()!=0){
        ui->listRegiones->addItems(reg);
    }
    ui->listRegiones->addItem("Sin región/Total país");
}

void Interfaz::calcular_datos()
{
    ui->teInfo->clear();
    this->dat_muert.clear();
    this->dat_recup.clear();
    this->dat_confir.clear();
    this->pais = ui->listPaises->currentText();
    this->region = ui->listRegiones->currentText();

    QString id_pais = netcsv->get_id_pais(pais);
    QString id_region = netcsv->get_id_region(region,id_pais);

    if (id_region!="0"){
        dat_muert = netcsv->obtener_datos("SELECT fecha,cant FROM muertes WHERE id_pais = '"
                                            +id_pais+"' AND id_region = '"+id_region+"'");
        dat_recup = netcsv->obtener_datos("SELECT fecha,cant FROM recuperados WHERE id_pais = '"
                                            +id_pais+"' AND id_region = '"+id_region+"'");
        dat_confir = netcsv->obtener_datos("SELECT fecha,cant FROM confirmados WHERE id_pais = '"
                                           +id_pais+"' AND id_region = '"+id_region+"'");
    }
    else {
        dat_muert = netcsv->obtener_datos("SELECT fecha,cant FROM muertes WHERE id_pais = '"
                                            +id_pais+"'");
        dat_recup = netcsv->obtener_datos("SELECT fecha,cant FROM recuperados WHERE id_pais = '"
                                            +id_pais+"'");
        dat_confir = netcsv->obtener_datos("SELECT fecha,cant FROM confirmados WHERE id_pais = '"
                                           +id_pais+"'");
    }
    dat_confir = netcsv->acumular_datos(dat_confir);
    dat_muert = netcsv->acumular_datos(dat_muert);
    dat_recup = netcsv->acumular_datos(dat_recup);

    int maxCant=0;
    for (int i=0;i<dat_confir.size();i++){
        if (maxCant < dat_confir.at(i).at(1).toInt()){
            maxCant = dat_confir.at(i).at(1).toInt();
        }
    }
    for (int i=0;i<dat_muert.size();i++){
        if (maxCant < dat_muert.at(i).at(1).toInt()){
            maxCant = dat_muert.at(i).at(1).toInt();
        }
    }
    for (int i=0;i<dat_recup.size();i++){
        if (maxCant < dat_recup.at(i).at(1).toInt()){
            maxCant = dat_recup.at(i).at(1).toInt();
        }
    }
    ui->lTotalCant->setText("<font color='white'>Total:\n"+QString::number(maxCant)+"</font>");
    ui->lTotalCant->setAlignment(Qt::AlignRight);
    ui->lPriFecha->setText("<font color='white'>Día 0: "+dat_confir.at(0).at(0)+"</font>");
    ui->lUltFecha->setText("<font color='white'>Día "+QString::number(dat_confir.size())+": "+dat_confir.last().at(0)+"</font>");


    ui->teInfo->setAlignment(Qt::AlignCenter);
    ui->teInfo->setTextColor(QColor(255,255,0));
    ui->teInfo->append("País:");
    ui->teInfo->append(pais+"\n");
    ui->teInfo->append("Región/Provincia:");
    ui->teInfo->append(region+"\n");
    ui->teInfo->append("Última fecha informada:");
    ui->teInfo->append(dat_confir.last().at(0)+"\n");
    ui->teInfo->append("Casos confirmados a la fecha:");
    ui->teInfo->setTextColor(QColor(0,0,255));
    ui->teInfo->append(dat_confir.last().at(1)+"\n");
    ui->teInfo->setTextColor(QColor(255,255,0));
    ui->teInfo->append("Casos recuperados a la fecha:");
    ui->teInfo->setTextColor(QColor(0,175,0));
    ui->teInfo->append(dat_recup.last().at(1)+"\n");
    ui->teInfo->setTextColor(QColor(255,255,0));
    ui->teInfo->append("Muertos acumulados hasta la fecha:");
    ui->teInfo->setTextColor(QColor(250,0,0));
    ui->teInfo->append(dat_muert.last().at(1));
    ui->teInfo->setTextColor(QColor(255,255,0));
}

void Interfaz::actualizar_bd()
{
    ui->prbProgreso->setTextVisible(true);
    connect(netcsv,SIGNAL(progreso(QString,int,int)),this,SLOT(mostrarProgreso(QString,int,int)));
    connect(this,SIGNAL(sTexto(QString)),ui->lActBD,SLOT(setText(QString)));
    ui->lActBD->setText("Procesando ...");
    if (netcsv->actualizar_tabla("https://raw.githubusercontent.com/CSSEGISandData/COVID-19/master/"
                                 "csse_covid_19_data/csse_covid_19_time_series/"
                                 "time_series_covid19_confirmed_global.csv","confirmados")){
        ui->lActBD->setText("Tabla 'Confirmados' actualizada");
    }
    if (netcsv->actualizar_tabla("https://raw.githubusercontent.com/CSSEGISandData/COVID-19/master/"
                                 "csse_covid_19_data/csse_covid_19_time_series/"
                                 "time_series_covid19_deaths_global.csv","muertes")){
        ui->lActBD->setText("Tabla 'Muertes' actualizada");
    }
    if (netcsv->actualizar_tabla("https://raw.githubusercontent.com/CSSEGISandData/COVID-19/master/"
                                 "csse_covid_19_data/csse_covid_19_time_series/"
                                 "time_series_covid19_recovered_global.csv","recuperados")){
        ui->lActBD->setText("Tabla 'Recuperados' actualizada");
    }

    QTimer::singleShot(3500,ui->lActBD,SLOT(clear()));
    ui->prbProgreso->setValue(0);
    ui->prbProgreso->setTextVisible(false);
    ui->listPaises->addItems(netcsv->getPaises());
}

void Interfaz::proximamente()
{
    QMessageBox::information(this,"Proximamente..","Esta utilidad se encuentra aún en etapa de "
                                                   "desarrollo.\nEstará disponible en próximas versiones");
}

void Interfaz::mostrarProgreso(QString strTabla, int maxV, int actV)
{
    emit sRango(0,maxV);
    emit sValor(actV);
    emit sTexto("Procesando '"+strTabla+"'");
}

void Interfaz::forzarAct()
{
    QMessageBox::critical(this,"Actualización necesaria","Se de realizar una actualización "
                                                         "de la base de datos para evitar problemas de ejecución.");
    ui->listPaises->setDisabled(true);
    ui->listRegiones->setDisabled(true);
    ui->pbCalcular->setDisabled(true);
    ui->pbComparar->setDisabled(true);
    ui->chkMuert->setDisabled(true);
    ui->chkRecup->setDisabled(true);
    ui->chkConfir->setDisabled(true);
    ui->pbActualizar->setDefault(true);
    ui->pbActualizar->setFocus();
    ui->pbComparar->setToolTip("Actualice primero la base de datos!");
    ui->listPaises->setToolTip("Actualice primero la base de datos!");
    ui->listRegiones->setToolTip("Actualice primero la base de datos!");
    ui->pbCalcular->setToolTip("Actualice primero la base de datos!");
    ui->chkMuert->setToolTip("Actualice primero la base de datos!");
    ui->chkRecup->setToolTip("Actualice primero la base de datos!");
    ui->chkConfir->setToolTip("Actualice primero la base de datos!");
}
