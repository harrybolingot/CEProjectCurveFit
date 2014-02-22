#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "exp_curve_fitter.h"

using namespace std;

int main(int argc, char *argv[])
{
    string s;
    expCurveFitter fitter;
    cout << "filename to import data from:";
    getline(cin, s);

    fitter.importData(s);

    // Testing for printing vector data
    // To remove
    cout << "x-data: " << endl;
    fitter.Print(fitter.x_data);
    cout << "y-data: " << endl;
    fitter.Print(fitter.y_data);

    fitter.fit();

    /*
    fitter.fit();
    cout <<"\n mean square difference: " << fitter.squareDiff() << endl;
    cout << fitter.getA() << " ";
    cout << fitter.getB() << " ";
    cout << "exp ( " << fitter.getC() << " x) ";
    */
    // // fits data to A + B exp ( C x)
    cout << "Press the enter key to continue ...";
    cin.get();
    return EXIT_SUCCESS;
}
