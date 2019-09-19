#include<iostream>
using namespace std;

long calc_pow(long b, long p, long ans, long k)
{
    if (p == 0) return 0;
    if (p == 1) return (b * ans) % k;
    else
    {
        if (p % 2 == 1)
        {
            ans = (ans * b) % k;
            b = (b * b) % k;
            p = (p - 1) / 2;
            calc_pow(b, p, ans, k);
        }
        else
        {
            b = (b * b) % k;
            p = p / 2;
            calc_pow(b, p, ans, k);
        }
    }

}

int main()
{
    long b, p, k, s, temp;
    cin >> b >> p >> k;

    s = calc_pow(b, p, 1, k);
    cout << b << "^" << p << " mod " << k << "="<< s;

    return 0;
}
