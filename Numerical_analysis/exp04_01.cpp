#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    double matrix[4][5] = {1, 1, 0, 3, 4,
                           2, 1, -1, 1, 1,
                           3, -1, -1, 2, -3,
                           -1, 2, 3, -1, 4};
    double t1[5], t2[4], result[4];
    memset(result, 0, sizeof(result));
    
    for (int i = 0; i < 4; i++)
    {
        int max = 0;
        for (int j = 0; j < 4; j++)
        {
            t2[j] = matrix[j][i];
            if (fabs(t2[max]) < fabs(t2[j])) max = j;
        }
        memcpy(t1, matrix[max], 5 * sizeof(double));
        memcpy(matrix[max], matrix[i], 5 * sizeof(double));
        memcpy(matrix[i], t1, 5 * sizeof(double));
        double t;
        for (int j = i + 1; j < 4; j++)
        {
            t = matrix[j][i]/matrix[i][i];
            for (int k = i; k < 5; k++)
            {
                matrix[j][k] = matrix[j][k] - matrix[i][k] * t;
            }
        }
    }

    for (int i = 3; i >= 0; i--)
    {
        double right = matrix[i][4];
        for (int k = 3; k > i; k--)
        {
            right -= matrix[i][k] * result[k];
        }
        result[i] = right/matrix[i][i];
    }

    for(int i = 0; i < 4; i++)
    {
        printf("X[%d] = %f\n", i, result[i]);
    }

    return 0;
}
