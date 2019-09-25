#include <iostream>
using namespace std;
int f[10010];

int find_set(int x)
{
    if (x != f[x]) f[x] = find_set(f[x]);
    return f[x];
}

int main()
{
    int n, m, op, x, y, z;
    cin >> n >> m;
    for (int i = 0; i < n; i++) f[i] = i;
    for (int i = 0; i < m; i++)
    {
        cin >> op >> x >> y;
        if (op == 1)
        {
            f[find_set(x)] = find_set(y);
        }
        else
        {
            if (find_set(x) == find_set(y)) cout << "Y" << endl;
            else cout << "N" << endl;
        }
    }

    return 0;
}