#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

double matrix[4][5] = {
8, 1, 0, 3, 4,
2, 7, -1, 1, 1,
3, -1, 9, 2, -3,
-1, 2, 3, 10, 4};

double max_difference(double temp[8])
{
    double max_diff, t;
    for (int i = 0; i < 4; i++)
    {
        if(i == 0) max_diff = fabs(temp[i+4] - temp[i]);
        else
        {
            t = fabs(temp[i+4] - temp[i]);
            if (t > max_diff) max_diff = t;
        }
    }
    return max_diff;
}

int Jacobi(double result[8])
{
    int count= 0;
    double e = 0.000001, temp[4];
    memset(result, 0, 8*sizeof(double));
    do
    {
        for (int i = 0; i < 4; i++)
        {
            result[i] = result[i + 4];
        }
        for (int i = 0; i < 4; i++)
        {
            double sum = 0;
            for (int j = 0; j < 4; j++)
            {
                if (j == i) continue;
                sum += -(matrix[i][j] * result[j]);
            }
            result[i + 4] = (sum + matrix[i][4])/matrix[i][i];
        }
        count++;
    } while (max_difference(result) > e);
    
    return count;
}

int Seidel(double result[8])
{
    int count= 0;
    double e = 0.000001, temp[4];
    memset(result, 0, 8*sizeof(double));
    do
    {
        for (int i = 0; i < 4; i++)
        {
            result[i] = result[i + 4];
        }
        for (int i = 0; i < 4; i++)
        {
            double sum = 0;
            for (int j = 0; j < 4; j++)
            {
                if (j == i) continue;
                sum += -(matrix[i][j] * result[j + 4]);
            }
            result[i + 4] = (sum + matrix[i][4])/matrix[i][i];
        }
        count++;
    } while (max_difference(result) > e);
    
    return count;
}

int main()
{
    double r1[8], r2[8];
    memset(r1, 0, 8*sizeof(double));
    cout << "Jacobi: " << Jacobi(r1) << endl;
    for (int i = 0; i < 4; i++)
    {
        printf("X[%d] = %f\n", i, r1[i + 4]);
    }
    cout << "Seidel: " << Seidel(r2) << endl;
    for (int i = 0; i < 4; i++)
    {
        printf("X[%d] = %f\n", i, r2[i + 4]);
    }

    return 0;
}
