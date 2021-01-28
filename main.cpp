#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
using namespace std;

void compute1(double x[], double y[], double dY[], double m[], double yNew[], int n, double deltaX);
void compute2(double x[], double y[], double dY[], double m[], double yNew[], int n, double deltaX);
void print(double x[], double y[], double dY[], double m[], double yNew[], int n);
void printT();
int main()
{
  int n; //number of steps
  char ans;

  cout << "Number of Steps: ";
  cin >> n;

  double x[n+1]; //x-values
  double y[n+1]; //y-values
  double deltaX; //change in x
  double deltaY[n+1]; //change in y
  double m[n+1]; //slope
  double yNew[n+1]; //new y-value

  cout << "Initial x-value: ";
  cin >> x[0];
  cout << "Initial y-value: ";
  cin >> y[0];
  cout << "Desired x-value: ";
  cin >> x[n];

  deltaX = (x[n] - x[0])/double(n); //sets step

  cout << "Does the question give you a function?(Y/N) ";
  cin >> ans;

  while(ans != 'y' && ans != 'Y' && ans != 'N' && ans != 'n')
  {
    cout << "Invalid answer! Try again: ";
    cin >> ans;
  }
  if(ans == 'y' || ans == 'Y')
  {
    cout << "Make sure computations are updated in the code to reflect the function!" << endl;

    //cout << "Δx: " << deltaX << endl;

    compute1(x, y, deltaY, m, yNew, n, deltaX);
    printT();
    print(x, y, deltaY, m, yNew, n);
  }
  else
  {
    compute2(x, y, deltaY, m, yNew, n, deltaX);
    printT();
    print(x, y, deltaY, m, yNew, n);
  }

  return 0;
}

void compute1(double x[], double y[], double deltaY[], double m[], double yNew[], int n, double deltaX)
{
  //computes first line
  m[0] = 2*x[0] - y[0]; //change according to given formula
  deltaY[0] = m[0] * deltaX;
  yNew[0] = y[0] + deltaY[0];

  for(int z = 1; z < n; z++)
  {
    x[z] = x[z-1] + deltaX;
    y[z] = yNew[z-1];
    m[z] = 2*x[z] - y[z]; //change according to given formula
    deltaY[z] = m[z] * deltaX;
    yNew[z] = y[z] + deltaY[z];
  }
  y[n] = yNew[n-1];
}
void compute2(double x[], double y[], double deltaY[], double m[], double yNew[], int n, double deltaX)
{
  for(int i = 0; i < n; i++)
  {
    cout << "Enter m" << i+1 << ": ";
    cin >> m[i];
  }
  deltaY[0] = m[0] * deltaX;
  yNew[0] = y[0] + deltaY[0];

  for(int z = 1; z < n; z++)
  {
    x[z] = x[z-1] + deltaX;
    y[z] = yNew[z-1];
    deltaY[z] = m[z] * deltaX;
    yNew[z] = y[z] + deltaY[z];
  }
  y[n] = yNew[n-1];
}
void print(double x[], double y[], double deltaY[], double m[], double yNew[], int n)
{
  //outputs first line
  cout << setw(10) << x[0] << setw(10) << y[0] << setw(10) << m[0] << setw(11)
  << deltaY[0] << setw(10) << yNew[0] << endl;
  for(int i = 1; i < n; i++)
  {
    cout << setw(10) << x[i] << setw(10) << y[i] << setw(10) << m[i] << setw(11)
    << deltaY[i] << setw(10) << yNew[i] << endl;
  }
  cout << setw(10) << x[n] << setw(10) << y[n] << endl;
}

void printT()
{
  //outputs table
  cout << endl << endl << left << setw(10) << "x" << setw(10) << "y"
  << setw(10) << "m" << setw(12) << "Δy"    << setw(10) << "y(new)" << endl;
  cout << setw(52) << setfill('-') << "" << setfill(' ') << endl;
}
