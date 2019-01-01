#include <cstdio>
#include <ctime>
#include <cstdlib>

int insertsort(int b[])
{
    int c[20001];
    clock_t start_t, end_t;
    for (int i=1; i<20001; i++)
    {
        c[i] = b[i];
    }
    start_t = clock();
    for (int i=2, j, k; i<20001; i++)
    {
        for (j=1; j<i; j++)
        {
            if (c[j] > c[i]) break;
        }
        if (j!=i)
        {
            c[0] = c[i];
            for (k=i; k!=j-1; k--)
            {
                c[k] = c[k-1];
            }
            c[j] = c[0];
        }
    }
    end_t = clock();

    return (int) (end_t - start_t);
}

int selectionsort(int b[])
{
    int c[20001];
    int min, temp;
    clock_t start_t, end_t;
    for (int i=1; i<20001; i++)
    {
        c[i] = b[i];
    }
    start_t = clock();
    for (int i=1; i<20001; i++)
    {
        min = i;
        for (int j=i+1;j<20001; j++)
        {
            if (c[j]<c[min]) min = j;
        }
        temp = c[i];
        c[i] = c[min];
        c[min] =temp;
    }
    end_t = clock();

    return (int) (end_t - start_t);
}

int bubblesort(int b[])
{
    int c[20001];
    clock_t start_t, end_t;
    int temp;
    for (int i=1; i<20001; i++)
    {
        c[i] = b[i];
    }
    start_t = clock();
    for (int i=1; i<20000; i++)
    {
        for (int j=1;j<20000-i; j++)
        {
            if (c[j]>c[j+1])
            {
                temp = c[j];
                c[j] = c[j+1];
                c[j+1] = temp;
            }
        }
    }
    end_t = clock();

    return (int) (end_t - start_t);
}

int partition(int c[], int low, int high)
{
    c[0] = c[low];
    int pivotkey = c[low];
    while (low < high)
    {
        while (low < high && c[high] >= pivotkey) --high;
        c[low] = c[high];
        while (low < high && c[low] <= pivotkey) ++low;
        c[high] = c[low];
    }
    c[low] = c[0];
    return low;
}
void qsort(int c[], int low, int high)
{
    int pivotloc;
    if (low<high)
    {
        pivotloc = partition(c, low, high);
        qsort(c, low, pivotloc-1);
        qsort(c, pivotloc+1, high);
    }
}
int quicksort(int b[])
{
    int c[20001];
    clock_t start_t, end_t;
    for (int i=1; i<20001; i++)
    {
        c[i] = b[i];
    }
    start_t = clock();
    qsort(c, 1, 20000);
    end_t = clock();

    return (int) (end_t - start_t);
}

int main()
{
    int i, j, t;
    int a[25000], b[25000], percent[101];
    srand((unsigned) time(NULL));
    printf("Generating random number list...(20000)\n");
    for (j=1; j<20001; j++)
    {
        for (i=(rand()+rand()+rand()+rand()+rand()+rand()+rand()+rand()) % 20000; a[i]==1; i=(rand()+rand()+rand()+rand()+rand()+rand()+rand()+rand()) % 20000);
        b[j] = i;
        a[i] = 1;
        if (percent[100*j/(20000)]==0)
        {
            printf("%d%%   ", 100*j/20000);
            percent[100*j/20000]++;
            t++;
            if (t%8==0) printf("\n");
        }
    }
    printf("\n");
    printf("Process over!\n");

    printf("DIRECT INSERT SORT costs time: %dms\n", insertsort(b));
    printf("SIMPLE SELECTION SORT costs time: %dms\n", selectionsort(b));
    printf("BUBBLE SORT costs time: %dms\n", bubblesort(b));
    printf("QUICK SORT costs time: %dms\n", quicksort(b));

    return 0;
}
