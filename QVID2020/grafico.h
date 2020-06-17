#ifndef GRAFICO_H
#define GRAFICO_H

#include <QWidget>
#include <QPen>
#include <QPolygonF>
#include <QVector>
#include <QLabel>

class Grafico : public QWidget
{
    Q_OBJECT
public:
    explicit Grafico(QWidget *parent = nullptr);

    QVector<QPen> getLapices() const;
    void setLapices(const QVector<QPen> &value);

    QVector<QPainterPath> getPoligonos() const;
    void setPoligonos(const QVector<QPainterPath> &value);

    QVector<QVector<double> > getDatos() const;
    void setDatos(const QVector<QVector<double> > &value);

private:
    QVector<QPen> lapices;
    QVector<QPainterPath> poligonos;
    QVector<QVector<double>> datos;
    QLabel miToolTip;
    void paintEvent(QPaintEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

signals:

};

#endif // GRAFICO_H
