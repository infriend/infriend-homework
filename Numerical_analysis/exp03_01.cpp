#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

double f(double x)
{
    return 1/(exp(x) + x * x * x);
}

double Simpson(double a, double b, int n)
{
    double h = (b - a)/n;
    double res = 0;
    for (int i = 0; i < n; i++)
    {
        double xi = a + i * h;
        res += f(xi) + 4 * f(xi + h / 2) + f(xi + h);
    }
    
    return res * h / 6;
}

int main()
{
    double a, b, e;
    cout << "Input a b e: ";
    cin >> a >> b >> e;
    double r1, r2;
    int n = 4;
    r1 = Simpson(a, b, 2);
    r2 = Simpson(a, b, 4);
    printf("S(2) = %f\n", r1);
    printf("S(4) = %f\n", r2);
    while (fabs(r2 - r1) > e)
    {
        n += 2;
        r1 = r2;
        r2 = Simpson(a, b, n);
        printf("S(%d) = %f\n", n, r2);   
    }
    printf("Result: S(%d) = %f\n", n, r2);

    return 0;
}