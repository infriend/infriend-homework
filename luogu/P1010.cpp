#include <iostream>
#include <cmath>
using namespace std;

int bigest_index(int num)
{
    int res;
    res = log(num) / log(2);

    return res;
}

void print_res(int num)
{
    if (num == 1 || num == 2 || num == 4)
    {
        if (num == 1) cout << "2(0)";
        if (num == 2) cout << "2";
        if (num == 4) cout << "2(2)";
    }
    else
    {
        cout << "2";
        int biggest = bigest_index(num);
        if (biggest > 2)
		{
			cout << "(";
			print_res(biggest);
			cout << ")";
		}
        if (biggest == 0) cout << "(0)";
        if (biggest == 1);
        if (biggest == 2) cout << "(2)";
        int rest = num - pow(2, biggest);
        if (rest != 0)
        {
            cout << "+";
            print_res(rest);
        }

    }
}

int main()
{
    int num;
    cin >> num;
    print_res(num);

    return 0;
}
