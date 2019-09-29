#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct seller
{
    int weight;
    int price;
} seller;
int comp(const seller &s1, const seller &s2)
{
    return s1.price < s2.price;
}


int main()
{
    int n, m, w, x[5010], rest;
    long long result = 0;
    seller s[5010];
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> s[i].price >> s[i].weight;
        x[i] = 0;
    }
    w = n;
    sort(s, s + m, comp);
    int i;
    for (i = 0; i < m; i++)
    {
        if (s[i].weight > w) break;
        x[i] = 1;
        w -= s[i].weight;
    }
    if (i <= m) rest = w;
    for (int j = 0; j < i; j++)
    {
        result += (long long)(s[j].price * s[j].weight);
    }
    result += (long long)(s[i].price * rest);
    printf("%lld", result);

    return 0;
}
