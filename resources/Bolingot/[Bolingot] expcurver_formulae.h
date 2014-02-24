#ifndef EXPCURVEFITTER
#define EXPCURVEFITTER 1
#define maxLimit 10
#include <fstream>
#include <string>
#include <vector>



using namespace std;

class expCurveFitter  // fits data to A + B exp ( C x)
{
  public:
    void importData(string filename );
    void showData();
    int numPoints();
    void dummify();
    void curvify();
    void displayEquation();
    void leastSqDiff();
    void regressify();

    double getX(int index);
    double getY(int index);

  private:
    vector<double> xData;
    vector<double> yData;
    vector<double> yDataDummified;
    vector<double> yDataRegressified;
    double prodxlny[maxLimit], xsq[maxLimit];
    double sumx, sumlny, sumxlny, sumxsq, limit;
    double denominator, B, C;
    double A;
    double totalYregressified, meanYregressified;
};

#endif

