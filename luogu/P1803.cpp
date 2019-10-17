#include <iostream>
#include <algorithm>
using namespace std;

typedef struct contest
{
    int s;
    int f;
} contest;

bool comp(const contest &c1, const contest &c2)
{
    return c1.f < c2.f;
}

contest c[1000010];

int main()
{
    int n, count = 0, fin;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> c[i].s >> c[i].f;
    }
    sort(c, c + n, comp);
    fin = c[0].f;
    count++;
    for (int i = 1; i < n; i++)
    {
        if (c[i].s >= fin)
        {
            count++;
            fin = c[i].f;
        }
    }
    cout << count;

    return 0;
}