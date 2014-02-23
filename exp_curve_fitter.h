#ifndef EXPCURVEFITTER
#define EXPCURVEFITTER 1
#include <fstream>
#include <string>
#include <vector>
#include "exp_curve_fitter.h"



using namespace std;

class expCurveFitter  // fits data to A + B exp ( C x)
{
  public:
    void importData(string filename);
    void fit();
    double squareDiff();
    double getA();
    double getB();
    double getC();

    double numPoints();
    double getX(int index);
    double getY(int index);

  private:
    vector<double> x_data;
    vector<double> y_data;
    double paramA;
    double paramB;
    double paramC;

};

#endif
