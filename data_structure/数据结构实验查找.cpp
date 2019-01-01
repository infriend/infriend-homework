#include <cstdio>
#include <ctime>
#include <cstdlib>

int direct_search(int e, int a[])
{
    int i;
    double t;
    clock_t start_t, end_t;
    start_t = clock();
    printf("DS start time %dms\n", (int) start_t);
    a[0] = e;
    for (i=10000; a[i]!=e; --i);
    end_t = clock();
    printf("DS end time %dms\n", (int) end_t);
    t = (int) (end_t - start_t);

    return t;
}

int bi_search(int e, int a[])
{
    int low, high, mid;
    clock_t start_t, end_t;
    start_t = clock();
    low = 1;
    high = 20000;
    while (low <= high)
    {
        mid = (low + high)/2;
        if (e == a[mid])
        {
            end_t = clock();
            printf("BS start time %dms\n", (int) start_t);
            printf("BS end time %dms\n", (int) end_t);
            return (int) (end_t - start_t);
        }
        else
        {
            if (e > a[mid])
            {
                low = mid + 1;
            }
            else high = mid - 1;
        }
    }
    printf("Not found!\n");
    end_t = clock();

    return (int) (end_t - start_t);
}

int main()
{
    int num;
    int a[20001];
    for (int i = 1; i < 20001; ++i)
    {
        a[i] = i;
    }
    printf("Enter the number: ");
    scanf("%d", &num);
    printf("Time cost of direct_search: %dms\n", direct_search(num, a));
    printf("Time cost of bi_search: %dms\n", bi_search(num, a));

    return 0;
}
