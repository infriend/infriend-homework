#include <iostream>
using namespace std;

class array
{
public:
    array operator+(array a);
    array operator-(array a);
    array(int a = 0, int b = 0, int c = 0, int d = 0, int e = 0, int f = 0);
    friend void display(array &a);
private:
    int ar[2][3];
};

array::array(int a, int b, int c, int d, int e, int f)
{
    ar[0][0] = a;
    ar[0][1] = b;
    ar[0][2] = c;
    ar[1][0] = d;
    ar[1][1] = e;
    ar[1][2] = f;
};
void display(array &a)
{
    cout << a.ar[0][0] << "  " << a.ar[0][1] << "  " << a.ar[0][2] << endl;
    cout << a.ar[1][0] << "  " << a.ar[1][1] << "  " << a.ar[1][2] << endl;
}
array array::operator+(array a)
{
    array temp;
    temp.ar[0][0] = ar[0][0] + a.ar[0][0];
    temp.ar[0][1] = ar[0][1] + a.ar[0][1];
    temp.ar[0][2] = ar[0][2] + a.ar[0][2];
    temp.ar[1][0] = ar[1][0] + a.ar[1][0];
    temp.ar[1][1] = ar[1][1] + a.ar[1][1];
    temp.ar[1][2] = ar[1][2] + a.ar[1][2];
    return temp;
}
array array::operator-(array a)
{
    array temp;
    temp.ar[0][0] = ar[0][0] - a.ar[0][0];
    temp.ar[0][1] = ar[0][1] - a.ar[0][1];
    temp.ar[0][2] = ar[0][2] - a.ar[0][2];
    temp.ar[1][0] = ar[1][0] - a.ar[1][0];
    temp.ar[1][1] = ar[1][1] - a.ar[1][1];
    temp.ar[1][2] = ar[1][2] - a.ar[1][2];
    return temp;
}

int main()
{
    int a1, a2, a3, a4, a5, a6;
    array s1(1, 2, 3, 4, 5, 6), temp;
    cout << "Input a1-a6: ";
    cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
    array s2(a1, a2, a3, a4, a5, a6);
    cout << "PLUS" << endl;
    temp = s1 + s2;
    display(temp);
    cout << "MINUS" << endl;
    temp = s1 - s2;
    display(temp);

    return 0;
}
