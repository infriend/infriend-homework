#include <iostream>
#include <algorithm>
using namespace std;
int heap[10010];
int heapsize = 0;

void put(int x)
{
    heap[++heapsize] = x;
    push_heap(heap + 1, heap + 1 + heapsize, greater<int>());
}

void del()
{
    pop_heap(heap + 1, heap + 1 + heapsize, greater<int>());
    heapsize--;
}

int main()
{
    int n, x, t1, t2;
    long long res = 0, temp;
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        put(x);
    }
    while (heapsize > 1)
    {
        t1 = heap[1];
        del();
        t2 = heap[1];
        del();
        put(t1 + t2);
        res += (long long)(t1 + t2);
    }
    cout << res;

    return 0;
}