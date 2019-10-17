#include <iostream>
#include <cstdio>
using namespace std;

double n, x[5], y[5], list[11];

void difference_quotient(double a, double b, int t)
{
    if ((b - a) == 1)
    {
        
    }
    else
    {
        difference_quotient(a, b - 1, t++);
        difference_quotient(a + 1, b, t++);
    }
}


int main()
{
    double up, down, result = 0, temp, t;
    cin >> n;
    for (int i = 0; i < 5; i++)
    {
        cin >> x[i] >> y[i];
    }


    return 0;
}
