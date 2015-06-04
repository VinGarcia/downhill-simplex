/*
 Copyright (C) 2010 Botao Jia

 This file is an testing of the implementation of the 
 downhill simplex optimization algorithm using C++.
 One function object Rosenbrock and two function rosenbrock, polynomial_fun are used.

 You can redistribute it and/or modify it at will.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  
*/

#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <iterator>
#include <cmath>
#include "simplex.h"
using namespace std;

template<class Con>
void printcon(const Con& c){
  std::cout.precision(12);
  copy( c.begin(), c.end(),
    ostream_iterator<typename Con::value_type>(cout, "  ")
  );
  cout<<endl;
}

class Rosenbrock{
public:
  double  operator()(vector<double> x){
    return 100*pow(x[1]-pow(x[0],2),2)+pow(1-x[0],2);
  }
};

double rosenbrock(vector<double> x){
  return 100*pow(x[1]-pow(x[0],2),2)+pow(1-x[0],2);
}

double polynomial_fun(vector<double> x){
  return pow( pow(x[0],2) + pow(x[1],2), 2 ) - pow(x[0]-3*x[1],2);
}

int main(){

  //initial guessing value for Rosenbrock function
  vector<double> init;
  init.push_back(1.23);
  init.push_back(10.96);

  //initial trial simplex
  double a0[]={-1.5, -1}, a1[]={-2, -2}, a2[]={ 2.5, 1.5};
  vector<vector<double> > matrix;
  matrix.push_back( vector<double>(a0,a0+2) );
  matrix.push_back( vector<double>(a1,a1+2) );
  matrix.push_back( vector<double>(a2,a2+2) );

  //optimizating...
  //printcon is a function printing container values

  using BT::Simplex;
  cout<<"Rosenbrock function achieves minimum at:"<<endl;
  printcon( Simplex(Rosenbrock(), init) );  cout<<endl;
  cout<<"Rosenbrock function achieves minimum at:"<<endl;
  printcon( Simplex(rosenbrock, init, 1e-7, matrix, 1E5) ); cout<<endl;
  cout<<"Polynomial function achieves minimum at:"<<endl;
  printcon( Simplex(polynomial_fun, init, 1e-7, matrix) );  cout<<endl;
}
