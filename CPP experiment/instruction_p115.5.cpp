#include <iostream>
using namespace std;

int sum = 0;

int main()
{
    int sum = 0;
    int a[6] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++)
    {
        ::sum += a[i];
    }
    cout << "::sum = " << ::sum << endl;
    for (int i = 0; i < 6; i++)
    {
        if (a[i] % 2) sum += a[i];
    }
    cout << "sum = " << sum << endl;

    return 0;
}
