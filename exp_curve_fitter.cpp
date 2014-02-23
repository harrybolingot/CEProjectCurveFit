#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "exp_curve_fitter.h"
// #define MAX 10 //to remove if not needed

using namespace std;

void expCurveFitter::importData(string filename)
{
  fstream f;
  double value;
  f.open( filename.c_str() );

  while (! f.eof() )
  {
    f >> value;
    x_data.push_back(value);
    f >> value;
    y_data.push_back(value);
  }
}

void expCurveFitter::fit()
{
    // Uses the Least Squares Method
    // Prioritizes over small y values
    int i, number;
    int iter_check;
    vector<double> new_x_data(x_data);
    vector<double> new_y_data(y_data);
    vector<double> result; // Results of each reiteration are put in here
    float sumx=0,sumlny=0;
    number = new_x_data.size(); //assigns x-vector size to an int. this breaks if data is invalid. :/
    float productxlny[number],sumxlny=0,square[number],sumx2=0; // instead of MAX = 10, I set it to number.
                                                                // not sure if it has any big implications.
    float denominator,a,b,c;
    for(i=0;i<number;i++)
    {
        sumx += new_x_data[i]; // a += b is the same as a = a + b
        sumlny += log(new_y_data[i]);
    }
    for(i=0;i<number;i++)
    {   productxlny[i]=new_x_data[i]*log(new_y_data[i]);
        sumxlny += productxlny[i];
    }
    for(i=0;i<number;i++)
    {
        square[i]=new_x_data[i]*new_x_data[i];
        sumx2 += square[i];
    }
    system("cls");
    cout << "\n\n" << "Exponential Curve Method" << "\n\n";
    // setw is much more convenient to use!
    // http://www.cplusplus.com/reference/iomanip/setw/
    cout << setw(10) << "x" << setw(10) << "y"  << setw(10) << "Ex2" << setw(15) << "Exlogy" << endl << endl;
    for(i=0;i<number;i++)
    {
        cout << setw(10) << new_x_data[i] << setw(10) << new_y_data[i] << setw(10) << square[i] << setw(15) << productxlny[i] << endl;
    }
    denominator=(number*sumx2)-(sumx*sumx);
    c=((sumlny*sumx2)-(sumx*sumxlny))/denominator;
    b=((number*sumxlny)-(sumx*sumlny))/denominator;
    a=exp(c);
    cout << "\n\n" << "The equation is: ";
    // Find a way to standardize output(?)
    // This seems more convenient.
//    cout << "y = " << a << "e^" << b << "x" << endl;
    printf("    y = %.4fe^%.4fx    ",a,b);
    cout << endl;
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
