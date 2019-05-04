#include <iostream>
using namespace std;

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else return b;
}

int max(int a, int b, int c)
{
    int t = a;
    if (t < b) t = b;
    if (t < c) t = c;
    return t;
}

double max(double a, double b)
{
    if (a > b)
    {
        return a;
    }
    else return b;
}

double max(double a, double b, double c)
{
    double t = a;
    if (t < b) t = b;
    if (t < c) t = c;
    return t;
}

int main()
{
    int a1, b1, c1;
    double a2, b2, c2;
    cout<<"int with 2 args:"<<endl;
    cin>>a1>>b1;
    cout<<"max = "<<max(a1, b1)<<endl;
    cout<<"int with 3 args:";
    cin>>a1>>b1>>c1;
    cout<<"max = "<<max(a1, b1, c1)<<endl;
    cout<<"double with 2 args:"<<endl;
    cin>>a2>>b2;
    cout<<"max = "<<max(a2, b2)<<endl;
    cout<<"int with 3 args:";
    cin>>a2>>b2>>c2;
    cout<<"max = "<<max(a2, b2, c2)<<endl;

    return 0;
}
