#include <iostream>
using namespace std;

void swap(char &a, char &b)
{
    char t;
    if (a < b)
    {
        t = a;
        a = b;
        b = t;
    }
}

int main()
{
    char a, b;
    cout << "input 2 char: ";
    cin >> a >> b;
    swap(a, b);
    cout << a <<"   " << b;

    return 0;
}
