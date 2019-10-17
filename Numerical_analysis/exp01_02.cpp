#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double raw_function(double x)
{
    return x * x * x - exp(x) - 1;
}

double df(double x)
{
    return 3 * x * x - exp(x);
}

double ddf(double x)
{
    return 6 * x - exp(x);
}

double newton_method(double a, double b, double e)
{
    double x0;
    if (raw_function(a) * ddf(a) > 0) x0 = a;
    else x0 = b;
    cout << "x0 = " << x0 << endl;
    double x1 = x0, x2, h;
    int n = 0;
    do
    {
        h = -(raw_function(x1)/df(x1));
        x2 = x1 + h;
        printf("x%d = %f\n", ++n, x2);
        if (abs(x2-x1) < e) break;
        x1 = x2;
    } while (1);
    x1 = x2;

    return x1;
}

int main()
{
    double a, b, e, res;
    cout << "ENTER a, b: ";
    cin >> a >> b;
    cout << "ENTER e: ";
    cin >> e;
    printf("RESULT: %f\n", newton_method(a, b, e));

    return 0;
}
