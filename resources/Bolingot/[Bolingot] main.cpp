#include <fstream>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "expcurver_formulae.h"

using namespace std;

int main(int argc, char *argv[])
{
    string s;
    expCurveFitter fitter;
    cout << "Filename to import data from: ";
    getline(cin, s);

    fitter.importData(s);


    fitter.dummify();
    fitter.curvify();
    fitter.regressify();

    cout << "No. of points read: " << fitter.numPoints() << endl;
    cout << "Data: \n";
    fitter.showData();
    cout << "\n" << endl;
    fitter.displayEquation();
    fitter.leastSqDiff();


}
