#define maxLimit 10
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include "expcurver_formulae.h"
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <ctime>
#include <iomanip>

using namespace std;


double dummyFactor;
double yDataMin;

void expCurveFitter::importData(string filename )
{
  fstream f;
  double valueX;
  double valueY;


  f.open( filename.c_str() );

  while (! f.eof() )
  {
    f >> valueX;
    xData.push_back(valueX);

    f >> valueY;
    yData.push_back(valueY);
    yDataDummified.push_back(valueY);
    yDataRegressified.push_back(valueY);
  }

}

int expCurveFitter::numPoints()
{
  return xData.size();
}

void expCurveFitter::showData()
{
    cout << setw(7) << "X-Values"  << setw(15) << "Orig. Y-Values"  << setw(15) << "Dumm. Y-Values" << setw(10) << "X-Squared" << setw(12) << "X * ln(Y)" << setw(15) << "Regr. Y-Values" << endl;
  for (int i = 0; i < xData.size(); i++)
  {
    cout << setw(7) << xData[i]  << setw(15) << yData[i]  << setw(15) << yDataDummified[i] << setw(10) << xsq[i] << setw(12) << prodxlny[i] << setw(15) << yDataRegressified[i] << endl;
  }
}

void expCurveFitter::dummify(){
    //dummyFactor = yData.at(yData.size()-1)/(double)(rand());
    srand(time(0));
    double randomNumber = rand()%10+2;
    dummyFactor = (*min_element(yData.begin(), yData.end()))/randomNumber;
    cout << "Random Number: " << randomNumber << endl << "Dummy Factor: " << dummyFactor << endl << endl;

    for(int i = 0; i < yData.size(); i++){
        yDataDummified[i] = yData[i] - dummyFactor;
        //cout << xData.at(i)  << "\t\t" << yData.at(i)  << endl;
    }

    A = -1*dummyFactor;
}

void expCurveFitter::curvify(){
    sumx = 0;
    sumlny = 0;
    sumxlny = 0;
    sumxsq = 0;
    limit = yData.size();

    for(int i = 0; i < limit; i++){
        sumx += xData[i];
        sumlny += log(yDataDummified[i]);
        prodxlny[i] = xData[i]*log(yDataDummified[i]);
        sumxlny += prodxlny[i];

        xsq[i] = xData[i]*xData[i];
        sumxsq += xsq[i];
    }

    denominator = (limit*sumxsq) - (sumx*sumx);
    B = exp(((sumlny*sumxsq)-(sumx*sumxlny))/denominator);
    C = ((limit*sumxlny)-(sumx*sumlny))/denominator;

    cout << "Denominator: " << denominator << endl;
    cout << "B: " << B << endl;
    cout << "C: " << C << endl;
}

void expCurveFitter::displayEquation(){
    cout << "Equation: " << "y = " << A << " + " << B << "*e^(" << C << "*x)" << endl;
}

void expCurveFitter::regressify(){
    for(int i = 0; i < yData.size(); i++){
        yDataRegressified[i] = A + B*exp(C*xData[i]);
    }

}

void expCurveFitter::leastSqDiff(){
    double meanSquareDiff = 0;
    double diff;
    meanYregressified = 0;

  for (int i=0; i < yData.size(); i++ )
  {
    diff =  yDataRegressified[i] - yData[i];
    meanSquareDiff += diff*diff;

    Yregressified += yDataRegressified[i];
  }
    meanSquareDiff /= xData.size();
    cout << "Mean-square Difference: " << meanSquareDiff << endl;


}
