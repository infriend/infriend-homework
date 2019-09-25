#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int heap[1000011];
int heaplength = 0;
//min heap without STL

//delete part
void down(int p) //adjust the heap after delete
{
    int q = 2 * p; //child node
    int temp = heap[p];
    while (q < heaplength)
    {
        if (q < heaplength && heap[q] > heap[q + 1]) q++; //choose the smaller one
        if (heap[q] >= temp) break; //if child is bigger than the father
        else //else exchange
        {
            heap[p] = heap[q];
            p = q;
            q = 2 * p;
        }
    }
    heap[p] = temp;
}

int deleteMin()
{
    int temp = heap[1];
    heap[1] = heap[heaplength--];
    down(1);

    return temp;
}

//insert part
void up(int p)
{
    int q = p / 2; //father
    int temp = heap[p];
    while (q >= 1 && temp < heap[q]) //before the root node
    {
        heap[p] = heap[q];
        p = q;
        q = p / 2;
    }
    heap[p] = temp;
}

void insert(int a)
{
    heap[++heaplength] = a;
    up(heaplength);
}


int main()
{
    int n;
    int op, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> x;
            insert(x);
        }
        else
        {
            if (op == 2) cout << heap[1] << endl;
            else
            {
                deleteMin();
            }
        }
    }
    return 0;
}