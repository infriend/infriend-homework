#include <iostream>
using namespace std;

class book
{
public:
    book(int iqu);
    void disp()
    {
        cout << "qu * price = " << qu * price << endl;
    }
private:
    int qu;
    int price;
};

book::book(int iqu)
{
    qu = iqu;
    price = 10 * iqu;
}

int main()
{
    book b1[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; ++i)
    {
        cout << "b1[" << i << "] = ";
        b1[i].disp();
    }

    return 0;
}
