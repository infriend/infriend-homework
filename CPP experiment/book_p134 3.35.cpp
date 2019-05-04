#include <iostream>
#include <cstring>
using namespace std;

class Stock
{
public:
    Stock(char stockcode[], int q = 1000, double p = 8.98);
    void print()
    {
        cout << "stockcode: " << this->stockcode << endl;
        cout << "quan: " << this->quan << endl;
        cout << "price: " << this->price << endl;
    }

private:
    char stockcode[10];
    int quan;
    double price;
};

Stock::Stock(char na[], int q, double p): quan(q), price(p)
{
    strcpy(stockcode, na);
}

int main()
{
    char sn1[10] = {"60001"}, sn2[10] = {"60001"};
    Stock s1(sn1, 3000, 5.67), s2(sn2);
    s1.print();
    s2.print();

    return 0;
}
