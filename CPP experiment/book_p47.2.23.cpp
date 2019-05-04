#include<iostream>
#include<cmath>
using namespace std;

double sroot(int a)
{
    return sqrt(a);
}

double sroot(long a)
{
    return sqrt(a);
}

double sroot(double a)
{
    return sqrt(a);
}

int main()
{
    int a;
    long b;
    double c;
    cout << "int a = ";
    cin >> a;
    cout << "sqrt a = " << sroot(a) << endl;
    cout << "long b = ";
    cin >> b;
    cout << "sqrt b = " << sroot(b) << endl;
    cout << "double c = ";
    cin >> c;
    cout << "sqrt c = " << sroot(c) << endl;

    return 0;
}
