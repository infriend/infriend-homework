#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s[5];
    cout << "Enter the string: " << endl;
    for (int i = 0; i < 5; ++i)
    {
        cin >> s[i];
    }
    for (int i = 0; i < 5; ++i)
    {
        cout << s[i] << " ";
    }
    cout << endl;
    for (int i = 4; i >= 0; --i)
    {
        cout << s[i] << " ";
    }

    return 0;
}
