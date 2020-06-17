//#######################################################################
// File: cpp_deSolve.cpp
// Utilities for solving the differential equations of compartmental
// epidemic models using the 4th order Runge-Kutta method
//
// Author: Sherry Towers
//         smtowers@asu.edu
// Created: Feb 21st, 2013
//
// Copyright Sherry Towers, 2013
//
// This program is not guaranteed to be free of bugs and/or errors.
//
// This program can be freely used and shared, as long as the author information
// and copyright in the header remains intact.
//########################################################################
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include "cpp_desolve.h"

using namespace std;

//########################################################################
//########################################################################
//########################################################################
// constructor
// InitialValues are the initial starting values for the compartments
//               given in the order that the model compartment differential
//               equations will be given in the ModelEquations method.
// Parameters    is the vector of parameters for the model.  You need to
//               pay attention to ensuring you remember what vector element
//               corresponds to which parameter of the model.
// ModelType     1 is a standard SIR model
//               2 is a standard SEIR model
//               3 is an SIR model with harmonic transmission
//               4 and up are whatever you code them up to be in
//                 the ModelEquations method below
//########################################################################
   cpp_deSolve::cpp_deSolve(vector<double> InitialValues
                           ,vector<double> Parameters
                           ,int            ModelType)
                           :_InitialValues(InitialValues)
                           ,_Parameters(Parameters)
                           ,_ModelType(ModelType){
     //cout << _InitialValues.size() << endl;
     //cout << _Parameters.size() << endl;
     //cout << _ModelType << endl;
   }

//########################################################################
//########################################################################
// Here is the method where you supply the equations for your
// derivatives for your model compartments (and store them in a vector
// called Derivatives)
//
// For _ModelType==1 (SIR model)
//    Compartments are (in order) S I R
//    and the parameters in _Parameters are (in order) beta gamma
// For _ModelType==2 (SEIR model)
//    Compartments are (in order) S E I R
//    and the parameters in _Parameters are (in order) beta kappa gamma
// For _ModelType==3 (harmonic SIR model)
//    Compartments are (in order) S I R
//    and the parameters in _Parameters are (in order) beta0 epsilon phi gamma
//
// if you are using a different model than one of those three, you need to
// define the equations below and then use ModelType==4 in your analysis
//########################################################################
   void cpp_deSolve::ModelEquations(double          mytime
                                   ,vector<double>  Compartments
                                   ,vector<double>& Derivatives){
     Derivatives.clear();

     //###################################################################
     // sum up the compartments
     //###################################################################
     double N = accumulate(Compartments.begin()
                          ,Compartments.end()
                          ,0.0
                          ,plus<double>());

     //###################################################################
     // Example equations for derivatives of compartments of an SIR model
     // for the SIR model
     //   Compartments[0] = S
     //   Compartments[1] = I
     //   Compartments[2] = R
     //
     //   _Parameters[0] = beta
     //   _Parameters[1] = gamma
     //###################################################################
     if (_ModelType==1){
       double S = Compartments[0];
       double I = Compartments[1];
       double R = Compartments[2];
       double beta  = _Parameters[0];
       double gamma = _Parameters[1];

       Derivatives.push_back(-beta*S*I/N);
       Derivatives.push_back(+beta*S*I/N - gamma*I);
       Derivatives.push_back(+gamma*I);

     //###################################################################
     // Example equations for derivatives of compartments of an SEIR model
     //   Compartments[0] = S
     //   Compartments[1] = E
     //   Compartments[2] = I
     //   Compartments[3] = R
     //
     //   _Parameters[0] = beta
     //   _Parameters[1] = kappa
     //   _Parameters[2] = gamma
     //###################################################################
     }else if (_ModelType==2){
       double S = Compartments[0];
       double E = Compartments[1];
       double I = Compartments[2];
       double R = Compartments[3];
       double beta  = _Parameters[0];
       double kappa = _Parameters[1];
       double gamma = _Parameters[2];

       Derivatives.push_back(-beta*S*I/N);
       Derivatives.push_back(-beta*S*I/N);
       Derivatives.push_back(+beta*S*I/N-kappa*E);
       Derivatives.push_back(+kappa*E-gamma*I);
       Derivatives.push_back(+gamma*I);

     //###################################################################
     // Example equations for derivatives of compartments of a harmonic
     // SIR model
     //   Compartments[0] = S
     //   Compartments[1] = I
     //   Compartments[2] = R
     //
     //   _Parameters[0] = beta0
     //   _Parameters[1] = epsilon
     //   _Parameters[2] = phi
     //   _Parameters[3] = gamma
     //###################################################################
     }else if (_ModelType==3){
       double S = Compartments[0];
       double I = Compartments[1];
       double R = Compartments[2];
       double beta0   = _Parameters[0];
       double epsilon = _Parameters[1];
       double phi     = _Parameters[2];
       double gamma   = _Parameters[3];

       double beta = beta0*(1.0+epsilon*cos(2.0*acos(-1.0)*(mytime-phi)/365.25));

       Derivatives.push_back(-beta*S*I/N);
       Derivatives.push_back(+beta*S*I/N - gamma*I);
       Derivatives.push_back(+gamma*I);

     //###################################################################
     // here is where you would put the equations for the derivatives
     // of your model, if you aren't using an SIR, SEIR, or harmonic
     // SIR model in your analysis
     //###################################################################
     }else{
     }

     if (Derivatives.size()!=Compartments.size()){
       cout << "cpp_deSolve(Compartments): Number of derivatives must match number of compartments!\n";
       cout << "                       Number of derivatives  = " << Derivatives.size() << endl;
       cout << "                       Number of compartments = " << Compartments.size() << endl;
     }
   }

//########################################################################
//########################################################################
//########################################################################
// Method to return vector of model estimates over time
// you shouldn't need to change anything in this code
// ModelEstimates[i][j] has i going from 0 to length(vtime)-1
//                      and j going from 0 to # of compartments-1
// ModelEstimatesTranspose[j][i] has i going from 0 to length(vtime)-1
//                               and j going from 0 to # of compartments-1
//########################################################################
   void cpp_deSolve::SimulateModel(vector<double>  vtime
                                  ,vector<vector<double> >& ModelEstimates
                                  ){
     vector<vector<double> > ModelEstimatesTranspose;
     SimulateModel(vtime
                  ,ModelEstimates
                  ,ModelEstimatesTranspose);
   }

   //#####################################################################
   //#####################################################################
   void cpp_deSolve::SimulateModel(vector<double>  vtime
                                  ,vector<vector<double> >& ModelEstimates
                                  ,vector<vector<double> >& ModelEstimatesTranspose
                                  ){
     ModelEstimates.clear();
     ModelEstimatesTranspose.clear();

     //###################################################################
     // calculate the number of new infections per unit time
     // for SIR and SEIR models
     //###################################################################
     double newI;
     vector<double> atemp = _InitialValues;
     vector<double> oldModelEstimates = _InitialValues;
     if (_ModelType==1){ // tack on the number of new infections per unit time beta*S*I/N
       double N = accumulate(atemp.begin()
                            ,atemp.end()
                            ,0.0
                            ,plus<double>());

       newI = _Parameters[0]*atemp[0]*atemp[1]/N;
     }
     if (_ModelType==2){ // tack on the number of new infections per unit time kappa*E
       newI = _Parameters[2]*atemp[1];
     }

     //###################################################################
     // set up the ModelEstimates and ModelEstimatesTranspose vectors
     //###################################################################
     if (_ModelType<=2) atemp.push_back(newI);
     ModelEstimates.push_back(atemp);

     for (int i=0;i<(int)atemp.size();i++){
       vector<double> btemp;
       btemp.push_back(atemp[i]);
       ModelEstimatesTranspose.push_back(btemp);
     }

     //###################################################################
     // now do the simulation over the time steps
     //###################################################################
     for (int i=1;i<(int)vtime.size();i++){
        double delta_t = vtime[i]-vtime[i-1];
        vector<double> newModelEstimates;
        RungeKuttaSolver(delta_t,vtime[i],oldModelEstimates,newModelEstimates);
        oldModelEstimates = newModelEstimates;

        vector<double> newModelEstimatesb = newModelEstimates;
        if (_ModelType==1){ // tack on the number of new infections per unit time beta*S*I/N
          double N = accumulate(newModelEstimates.begin()
                               ,newModelEstimates.end()
                               ,0.0
                               ,plus<double>());

          double newI = _Parameters[0]*newModelEstimates[0]*newModelEstimates[1]/N;
          newModelEstimatesb.push_back(newI);
        }
        if (_ModelType==2){ // tack on the number of new infections per unit time kappa*E
          double newI = _Parameters[2]*newModelEstimates[1];
          newModelEstimatesb.push_back(newI);
        }
        ModelEstimates.push_back(newModelEstimatesb);

        for (int j=0;j<(int)newModelEstimatesb.size();j++){
          ModelEstimatesTranspose[j].push_back(newModelEstimatesb[j]);
        }
     }
   }

//########################################################################
//########################################################################
//########################################################################
// Runge-Kutta method for solving systems of differential equations
// you shouldn't need to change anything in this code
//########################################################################
   void cpp_deSolve::RungeKuttaSolver(double  delta_t
                                     ,double  mytime
                                     ,vector<double>  oldModelEstimates
                                     ,vector<double>& newModelEstimates){
      newModelEstimates.clear();
      vector<double> updatedModelEstimates;
      vector<double> Derivatives;
      vector<double> a1;
      ModelEquations(mytime,oldModelEstimates,Derivatives);
      for (int i=0;i<(int)oldModelEstimates.size();i++){
         a1.push_back(delta_t*Derivatives[i]);
         updatedModelEstimates.push_back(oldModelEstimates[i]+delta_t*Derivatives[i]/2.0);
      }

      ModelEquations(mytime,updatedModelEstimates,Derivatives);
      updatedModelEstimates.clear();
      vector<double> a2;
      for (int i=0;i<(int)oldModelEstimates.size();i++){
         a2.push_back(delta_t*Derivatives[i]);
         updatedModelEstimates.push_back(oldModelEstimates[i]+delta_t*Derivatives[i]/2.0);
      }

      ModelEquations(mytime,updatedModelEstimates,Derivatives);
      updatedModelEstimates.clear();
      vector<double> a3;
      for (int i=0;i<(int)oldModelEstimates.size();i++){
         a3.push_back(delta_t*Derivatives[i]);
         updatedModelEstimates.push_back(oldModelEstimates[i]+delta_t*Derivatives[i]);
      }

      vector<double> a4;
      ModelEquations(mytime,updatedModelEstimates,Derivatives);
      for (int i=0;i<(int)oldModelEstimates.size();i++){
         a4.push_back(delta_t*Derivatives[i]);
      }

      for (int i=0;i<(int)oldModelEstimates.size();i++){
        newModelEstimates.push_back(oldModelEstimates[i]
                                   +(a1[i]
                                    +2.0*a2[i]
                                    +2.0*a3[i]
                                    +a4[i])/6.0);
        if (newModelEstimates[i]<0) newModelEstimates[i] = 0;
      }

   }

//########################################################################
//########################################################################
//########################################################################
// destructor
//########################################################################
   cpp_deSolve::~cpp_deSolve(){
   }
