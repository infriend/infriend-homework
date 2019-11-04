#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

double f(double x)
{
    return 1/(exp(x) + x * x * x);
}

double Trap(double a, double b, int n)
{
    double h = (b - a)/n;
    double res = 0;
    for (int i = 0; i < n; i++)
    {
        double xi = a + i * h;
        res += f(xi) + f(xi + h);
    }
    
    return res * h / 2;
}

int main()
{
    double a, b, e;
    cout << "Input a b e: ";
    cin >> a >> b >> e;
    double r1, r2;
    int n = 4;
    r1 = Trap(a, b, 2);
    r2 = Trap(a, b, 4);
    printf("T(2) = %f\n", r1);
    printf("T(4) = %f\n", r2);
    while (fabs(r2 - r1) / 3 > e)
    {
        n *= 2;
        r1 = r2;
        r2 = Trap(a, b, n);
        printf("T(%d) = %f\n", n, r2);
    }
    printf("Result: %f\n", r2 + (r2 - r1) / 3);

    return 0;
}