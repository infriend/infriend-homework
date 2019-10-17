#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    double n, x[5], y[5];
    double up, down, result = 0, temp;
    cin >> n;
    for (int i = 0; i < 5; i++)
    {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < 5; i++)
    {
        up = 1;
        down = 1;
        temp = 0;
        for (int j = 0; j < 5; j++)
        {
            if (j == i) continue;
            up *= n - x[j];
            down *= x[i] - x[j];
        }
        temp = up/down * y[i];
        result += temp;
    }
    printf("%f", result);

    return 0;
}
