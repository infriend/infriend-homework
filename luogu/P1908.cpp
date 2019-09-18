#include <iostream>
#include <algorithm>
using namespace std;
int a[500010], b[500010];


long long mergesort(int p, int q)
{
    if (p == q) return 0LL;
    
    long long countr, countl, res;
    int mid = (p + q)/2;
    countl = mergesort(p, mid);
    countr = mergesort(mid + 1, q);

    for (int i = p; i <= q; i++)
    {
        b[i] = a[i];
    }
    sort(b + p, b + mid + 1);
    sort(b + mid + 1, b + q + 1);
    res = countl + countr;
    int t = mid + 1;
    for (int i = p; i <= mid; i++)
    {
        if(t == mid + 1 && b[t] >= b[i])
            continue;
        while(b[t] < b[i] && t <= q)
            t++;
        res += t - mid - 1;
    }

    return res;
}

int main()
{
    int n;
    long long res = 0;
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    res = mergesort(0, n - 1);

    cout << res;

    return 0;
}