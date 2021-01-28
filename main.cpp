#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  int n; //number of steps

  cout << "Number of Steps: ";
  cin >> n;

  int x[n+1]; //x-values
  int y[n+1]; //y-values
  int deltaX; //change in x
  int deltaY[n+1]; //change in y
  int m[n+1]; //slope
  int yNew[n+1]; //new y-value

  cout << "Initial x-value: ";
  cin >> x[0];
  cout << "Desired x-value: ";
  cin >> x[n];

  deltaX = (x[n] - x[0])/n; //sets step
  

  return 0;
}
