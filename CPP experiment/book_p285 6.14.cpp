#include <iostream>
using namespace std;

template <typename t>
class threenum
{
public:
    threenum (t a, t b, t c);
    t sumnum()
    {
        return e1 + e2 + e3;
    }
private:
    t e1, e2, e3;
};
template <typename t>
threenum<t>::threenum(t a, t b, t c): e1(a), e2(b), e3(c)
{};

int main()
{
    int a, b, c;
    cout << "Enter the num: ";
    cin >> a >> b >> c;
    threenum<int> t(a, b, c);
    cout << "sum = " << t.sumnum();

    return 0;
}
