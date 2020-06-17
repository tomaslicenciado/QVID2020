#include "basicsir.h"
#include <QMessageBox>
#include <QDebug>
#include "cpp_desolve.h"

BasicSIR::BasicSIR(QObject *parent) : QObject(parent)
{
    S=0;
    I=0;
    R=0;
    M=0;
    N=0;
    E=0;
    K=0;
    G=0;
    B=0;
    datosSEIR=false;
    perSIR=0;
}


void BasicSIR::setear_datos(const int n, const int s, const int i, const int r, const double gama, const double beta)
{
    N=n;
    S=s;
    I=i;
    R=r;
    G=gama;
    B=beta;
    datosSEIR=true;
}



QVector<QVector<double> > BasicSIR::calSIR(int periodo)
{
    //Devuelve vector de tantas columnas como días de predicción
    // y las filas corresponden a SEIRM (Suceptibles, Expuestos, Infectados, Recuperados, Muertos)
    QVector<QVector<double>>r;
    perSIR=periodo;
    if (datosSEIR){
        //##############################################################################
          // Let's solve the model for times t=0 to 100 in steps of 1/100th of a day
          // Note that you need to make the time step quite small in order for this
          // method to work!
          //##############################################################################
          double mytime = 0.0;
          double delta_t = (double)10/(double)perSIR;
          //double delta_t = (double)perSIR;
          vector<double> vtime;
          while (mytime<=(100.0+delta_t)){
             vtime.push_back(mytime);
             mytime = mytime + delta_t;
          }

          //##############################################################################
          // fill vectors with the parameters and the initial values
          //##############################################################################
          double beta = B;
          double gamma = G;
          vector<double> Parameters;
          Parameters.push_back(beta);
          Parameters.push_back(gamma);

          double npop = N;
          double I_0 = I;
          double S_0 = npop-I_0;
          double R_0 = R;
          vector<double> InitialValues;
          InitialValues.push_back(S_0);
          InitialValues.push_back(I_0);
          InitialValues.push_back(R_0);

          //##############################################################################
          // ModelType==1 is an SIR model
          //##############################################################################
          int ModelType = 1;
          cpp_deSolve mysir(InitialValues
                           ,Parameters
                           ,ModelType);

          //##############################################################################
          // now solve the model using the Runge Kutta method
          //##############################################################################
          vector<vector<double> > ModelEstimates;
          mysir.SimulateModel(vtime
                             ,ModelEstimates);

          for (int i=0;i<(int)ModelEstimates.size();i++){
              QVector<double> aux;
              for (int j=0;j<(int)ModelEstimates.at(i).size();j++){
                  if (j==2){
                      aux.append(ModelEstimates.at(i).at(j) * 0.85);
                      aux.append(ModelEstimates.at(i).at(j) * 0.15);
                  }
                  else {
                      aux.append(ModelEstimates.at(i).at(j));
                  }
              }
              r.append(aux);
          }
    }
    return r;
}

void BasicSIR::limpiarDatos()
{
    S=0;
    I=0;
    R=0;
    M=0;
    N=0;
    E=0;
    K=0;
    G=0;
    B=0;
    datosSEIR=false;
    perSIR=0;
}
