#include <iostream>
using namespace std;

class base
{
private:
    int i, j;
public:
    base(int ini, int inj);
    int func(int p, int q);
};
base::base(int ini, int inj)
{
    i = ini;
    j = inj;
}
int base::func(int p, int q)
{
    if (q==0) return p;
    else return func(q, p%q);
}
class derived: public base
{
public:
    derived(int ini, int inj);
    int pfunc(int l, int r);
};
derived::derived(int ini, int inj): base(ini, inj)
{};
int derived::pfunc(int l, int r)
{
    return base::func(l, r);
}

int main()
{
    int i, j;
    cout << "input i, j: ";
    cin >> i >> j;
    derived a(i, j);
    cout << "result: " << a.pfunc(i, j) << endl; 


    return 0;
}
