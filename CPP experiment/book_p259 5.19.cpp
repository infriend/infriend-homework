#include <iostream>
using namespace std;

class complex
{
private:
    double real, imag;
public:
    complex(double r = 0, double i = 0);
    friend complex operator+(complex c1, complex c2);
    void print();
};
complex::complex(double r, double i): real(r), imag(i)
{};
void complex::print()
{
    cout << '(' << real << ',' << imag << ')' << endl;
}

complex operator+(complex c1, complex c2)
{
    complex temp;
    temp.real = c1.real + c2.real;
    temp.imag = c1.imag + c2.imag;
    return temp;
}

int main()
{
    complex c1(2.5, 3.7), c2(4.2, 6.5), total;
    total = c1 + c2;
    total.print();

    return 0;
}
