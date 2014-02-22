#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include "exp_curve_fitter.h"
#define MAX 10 //to remove if not needed

using namespace std;

void expCurveFitter::importData(string filename)
{
  fstream f;
  double value;
  f.open( filename.c_str() );
  //  vector<double> x_data;
  //  vector<double> y_data;

  while (! f.eof() )
  {
    f >> value;
    x_data.push_back(value);
    f >> value;
    y_data.push_back(value);
  }

}

// Testing for printing the vector data correctly
// To be removed
void expCurveFitter::Print(vector<double> s){
    for (int i =0; i < s.size(); i++){
        cout << s[i] << endl;
    }
}

void expCurveFitter::fit()
{
    int i, number;
    // Make copies of each vector data
    // To-do: Consider if we only need to make a copy of y-data for arbitrary A.
    vector<double> new_x_data(x_data);
    vector<double> new_y_data(y_data);
    float sumx=0,sumlogy=0;
    number = new_x_data.size(); //assigns x-vector size to an int. this breaks if data is invalid. :/

    // this should provide a better chance at not blowing all over, i think.
    float productxlogy[number],sumxlogy=0,square[number],sumx2=0;
    //float productxlogy[MAX],sumxlogy=0,square[MAX],sumx2=0;
    float denominator,a,b,c;

    for(i=0;i<number;i++)
    {
        sumx=sumx+new_x_data[i];
    }

    for(i=0;i<number;i++)
    {
        sumlogy=sumlogy+log(new_y_data[i]);
    }

    cout << "\nsumlogy = " << sumlogy;

    for(i=0;i<number;i++)
    {
        productxlogy[i]=new_x_data[i]*log(new_y_data[i]);
        sumxlogy=sumxlogy+productxlogy[i];
    }
    cout << "\n " << sumxlogy;

    for(i=0;i<number;i++)
    {
        square[i]=new_x_data[i]*new_x_data[i];
        sumx2=sumx2+square[i];
    }

    system("cls");

    cout << "\n\n" << "Exponential Curve Method" << "\n\n";
    cout << "  x        y              Ex2             Exlogy  " << "\n\n";
    for(i=0;i<number;i++)
    {
        // Find a way to standardize output(?)
        // This seems more convenient.
        printf( "%0.2f     %0.2f        %.2f         %.2f  ",new_x_data[i],new_y_data[i],square[i],productxlogy[i]);
        printf("\n");
    }

    denominator=(number*sumx2)-(sumx*sumx);
    c=((sumlogy*sumx2)-(sumx*sumxlogy))/denominator;
    b=((number*sumxlogy)-(sumx*sumlogy))/denominator;
    a=exp(c);
    cout << "\n\n" << "The equation is : ";
    // Find a way to standardize output(?)
    // This seems more convenient.
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
