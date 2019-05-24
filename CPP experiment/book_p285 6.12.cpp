#include <iostream>
using namespace std;

template<typename t>
t outputmax(t *array, int len)
{
    t maxe;
    maxe = array[0];
    for (int i = 0; i < len; ++i)
    {
        if (maxe < array[i]) maxe = array[i];
    }

    return maxe;
}

int main()
{
    int array1[5];
    double array2[6];

    cout << "Input int array: ";
    for (int i = 0; i < 5; ++i)
    {
        cin >> array1[i];
    }
    cout << "max element = " << outputmax(array1, 5) << endl;
    cout << "Input double array: ";
    for (int i = 0; i < 6; ++i)
    {
        cin >> array2[i];
    }
    cout << "max element = " << outputmax(array2, 6) << endl;

    return 0;
}
