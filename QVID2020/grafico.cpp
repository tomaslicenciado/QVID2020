#include "grafico.h"
#include <QPainter>
#include <QPaintDevice>
#include <QDebug>
#include <QTimer>
#include <QMouseEvent>
#include <QToolTip>

Grafico::Grafico(QWidget *parent) : QWidget(parent)
{
    this->setMouseTracking(true);
    miToolTip.setVisible(false);
}

QVector<QPen> Grafico::getLapices() const
{
    return lapices;
}

void Grafico::setLapices(const QVector<QPen> &value)
{
    lapices = value;
}

QVector<QPainterPath> Grafico::getPoligonos() const
{
    return poligonos;
}

void Grafico::setPoligonos(const QVector<QPainterPath> &value)
{
    poligonos = value;
}

QVector<QVector<double> > Grafico::getDatos() const
{
    return datos;
}

void Grafico::setDatos(const QVector<QVector<double> > &value)
{
    datos = value;
}

void Grafico::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    for (int i=0;i<poligonos.size();i++){
        painter.setPen(lapices.at(i));
        painter.drawPath(poligonos.at(i));
    }
}

void Grafico::mouseMoveEvent(QMouseEvent *event)
{
    QPointF posm = event->globalPos();
    for (int i=0;i<poligonos.size();i++){
        if (poligonos.at(i).contains(posm)){
            int indice = (posm.x() - ((float)this->width()*0.02))/(((float)this->width()*0.96) / (float)datos.size());
            if (poligonos.size() < datos.at(0).size()){
                miToolTip.setText(QString::number(datos.at(indice).at(i+1)));
            }
            else {
                miToolTip.setText(QString::number(datos.at(indice).at(i)));
            }
            miToolTip.setVisible(true);
            miToolTip.move(posm.toPoint());
        }
        else {
            miToolTip.setVisible(false);
        }
    }
}
