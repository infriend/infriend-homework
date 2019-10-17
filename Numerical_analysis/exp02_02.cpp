#include <iostream>
#include <cstdio>
using namespace std;

double x[5], y[5], list[16];
int p = 0;

double difference_quotient(int a, int b, int t)
{
    int temp = t;
    if ((b - a) == 1)
    {
        list[t] = (y[b] - y[a])/(x[b] - x[a]);
        return list[t];
    }
    else
    {
        double right = difference_quotient(a, b - 1, p++);
        double left = difference_quotient(a + 1, b, p++);
        list[temp] = (left - right)/(x[b] - x[a]);
        return list[temp];
    }
}

int main()
{
    double up, down, result = 0, temp = 1, n;
    int j = 3;
    cin >> n;
    for (int i = 0; i < 5; i++)
    {
        cin >> x[i] >> y[i];
    }
    difference_quotient(0, 4, p++);
    for (int i = 0; i < 5; i++)
    {
        if (i == 0) result += y[0];
        else
        {
            temp *= n - x[i-1];
            result += temp * list[j--];
        }
    }
    cout << result;

    return 0;
}
