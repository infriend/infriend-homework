#include <cmath>
#include <iostream>
#define PI 3.14
using namespace std;

int main()
{
    double *p;
    p = new double;
    cout << "input double num: ";
    cin >> *p;
    cout << "area of the circle: " << PI * pow(*p, 2) << endl;
    delete p;

    return 0;
}
