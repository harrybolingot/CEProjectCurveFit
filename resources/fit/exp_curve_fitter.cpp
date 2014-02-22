#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include "exp_curve_fitter.h"

using namespace std;

void expCurveFitter::importData(string filename )
{
  fstream f;
  double valueX;
  double valueY;
  f.open( filename.c_str() );    
  //  vector<double> x_data;         
  //  vector<double> y_data;      
  
  int i=0;
  while (! f.eof() )
  {
    cout << i <<endl; i++; 
       
    if ( f >> valueX )
      if (f >> valueY )
      {
        x_data.push_back( valueX);
        y_data.push_back( valueY);
      }
  }  
  
}

void expCurveFitter::fit()
{
    
   paramA = 2.5;
   paramB = -3.5;
   paramC = 1.5;     
}

int expCurveFitter::numPoints()
{
  return x_data.size();
}

void expCurveFitter::showData()
{
  for (int i=0; i<x_data.size(); i++)
  {
    cout << x_data.at(i)  << "\t\t" << y_data.at(i)  << endl; 
  }    
}

double expCurveFitter::squareDiff()
{
  double meanSquareDiff=0;  
  double diff;
   
  for (int i=0; i<x_data.size(); i++ )
  {
    diff = paramA  + paramB* exp( paramC* x_data.at(i) ) - y_data.at(i);
         
    meanSquareDiff += diff*diff;       
  }  
  meanSquareDiff /= x_data.size();  
  return  meanSquareDiff;   
}

double expCurveFitter::getA()
{
  return paramA;    
}

double expCurveFitter::getB()
{
  return paramB;    
}

double expCurveFitter::getC()
{
  return paramC;    
}
