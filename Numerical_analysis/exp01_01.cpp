#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double raw_function(double x)
{
    return (x * exp(x) - x * x -1);
}

int cal_times(double a, double b, double e)
{
    if (a < b) return int(log((b - a)/e) / log(2));
    else return int(log((a - b)/e) / log(2));
}

double biselection(double a, double b, double e)
{
    double res, mid, fmid;
    if (raw_function(a) * raw_function(b) >= 0)
    {
        cout << "Error" << endl;
        return 10000000;
    }
    else
    {
        int times = cal_times(a, b, e);
        cout << "NO    " << " c             " << "f(c)" << endl;
        for(int i = 0; i < times; i++)
        {
            mid = (a + b) / 2;
            fmid = raw_function(mid);
            printf("%-6d %-14f %f\n", i+1, mid, fmid);
            if (raw_function(a) > 0)
            {
                if (fmid > 0)
                {
                    a = mid;
                }
                else
                {
                    b = mid;
                }
            }
            else
            {
                if (fmid > 0)
                {
                    b = mid;
                }
                else
                {
                    a = mid;
                }
            }
        }
    }
    return mid;
}

int main()
{
    double a, b, e;
    cout << "ENTER a, b: ";
    cin >> a >> b;
    cout << "ENTER e: ";
    cin >> e;
    cout << "RESULT: " << endl << biselection(a, b, e) << endl;

    return 0;
}
