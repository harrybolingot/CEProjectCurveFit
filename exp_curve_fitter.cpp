#include <fstream>
#include <string>
#include <cmath>
#include "exp_curve_fitter.h"

using namespace std;

void expCurveFitter::importData(string filename )
{
  fstream f;
  double value;
  f.open( filename.c_str() );    
  //  vector<double> x_data;         
  //  vector<double> y_data;      
  
  while (! f.eof() )
  {
    f >> value;    
    x_data.push_back( value);
    f >> value;
    y_data.push_back( value);
  }  
  
}

void expCurveFitter::fit()
{
    
   paramA = 2.5;
   paramB = -3.5;
   paramC = 1.5;     
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
