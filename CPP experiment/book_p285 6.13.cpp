#include <iostream>
using namespace std;

template<typename t>
void sortarray(t *array, int len)
{
    t temp;
    for (int i = 0; i < len; ++i)
    {
        for (int j = 0; j < len - i - 1; ++j)
        {
            if (array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
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
    cout << "sorted int array: " << endl;
    sortarray(array1, 5);
    for (int i = 0; i < 5; ++i)
    {
        cout << array1[i] << "  " ;
    }
    cout << endl << "Input double array: ";
    for (int i = 0; i < 6; ++i)
    {
        cin >> array2[i];
    }
    cout << "sorted double array: " << endl;
    sortarray(array2, 6);
    for (int i = 0; i < 6; ++i)
    {
        cout << array2[i] << "  ";
    }

    return 0;
}
