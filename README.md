# CE30 Project: Curve Fitting Exponential Functions
Develop and implement a curve-fitting algorithm that determines the parameters *A*, *B*, *C* from *x-y* data, (x<sub>i</sub>,y<sub>i</sub>), *i* = 1,..., *n*, such that the mean square difference
![alt text](http://i.imgur.com/IuLzT7k.png "Mean Square Difference")
is minimized.

##Objectives
Write an application that extracts *x-y* data, (x<sub>i</sub>,y<sub>i</sub>), *i* = 1,..., *n*, from a text file specified by the user. The data are expected to be exponential, behaving according to a function of the form *A + Be<sup>Cx</sup>*. Hence the application would next use a curve-fitting algorithm to determine the parameters *A, B and  C* of the curve such that the resulting curve best fits the data in the sense of minimizing the mean square difference between the data and the curve.

The application concludes by announcing the required parameters and the value of the mean square difference.

This project must be done in C++

##To-do List
1. Fix data compatibility for program
2. Create variables to store data
  * a 2D array/matrix (nrows, ncols)
  * Others to follow suit
3. Provide a way of limiting number of combinations of (*A,B,C*) we will get to use
  * Value of A is provided by user/dev
4. Implement the Mean Square Difference Algorithm
  * Iterate at each or get data then iterate
  * Store (*A,B,C* and *Mean Square Difference*) in a list/array?
5. Compare and check the MSD.
6. Print out needed stuff.

##Resource Folder
The resource folder is for files which may/may not be necessary for the project, but they are not directly compiled to the program.