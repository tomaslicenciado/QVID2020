#ifndef BASICSIR_H
#define BASICSIR_H

//            COPIRIGTH DEL CÓDIGO UTILIZADO EN LA FUNCIÓN calSEIR
//#######################################################################
// A C++ program to provide examples of use of methods
// in the deSolve class to numerically
// solve an SIR model
//
// Author: Sherry Towers
//         smtowers@asu.edu
// Created: Mar 22nd, 2013
//
// Copyright Sherry Towers, 2013
//
// This program is not guaranteed to be free of bugs and/or errors.
//
// This program can be freely used and shared, as long as the author information
// and copyright in the header remains intact.
//#######################################################################


#include <QObject>

class BasicSIR : public QObject
{
    Q_OBJECT
public:
    explicit BasicSIR(QObject *parent = nullptr);

    void setear_datos(const int n,const int s,const int i, const int r,const double gama,const double beta);

    QVector<QVector<double>> calSIR(int periodo);
    void limpiarDatos();

private:
    int S;                  //Suceptibles
    int I;                  //Infectados
    int R;                  //Recuperados
    int M;                  //Muertos
    int N;                  //Población total: S + I + R = N0 - M
    int E;                  //Expuestos
    double K;               //Kappa. 1/Kappa tiempo promedio de incubación. se suele usar 1/7
    double G;               //Gamma. 1/Gamma tiempo promedio de infección. Se suele usar 1/5
    double B;               //Beta. Se suele usar
    bool datosSEIR;
    int perSIR;

    bool datos_cargados();


private slots:

public slots:

signals:

};

#endif // BASICSIR_H
