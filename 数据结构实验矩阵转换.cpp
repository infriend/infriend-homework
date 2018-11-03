#include <stdio.h>

typedef struct
{
    int i, j;
    int e;
} triple;

typedef struct
{
    triple data[101];
    int mu, nu, tu;
} tsmatrix;

void printlist(tsmatrix a)
{
    int i, j, k, p;
    for (i=1;i<=a.mu;++i)
    {
        for (j=1;j<=a.nu;++j)
        {
            k = 0;
            for (p=1;p<=a.tu;++p)
            {
                if (i==a.data[p].i&&j==a.data[p].j)
                {
                    printf("%3d", a.data[p].e);
                    k++;
                    continue;
                }
            }
            if (k) continue;
            printf("  0");
        }
        if (j==a.nu||j==a.nu+1) printf("\n");
    }
}

void printta(tsmatrix a)
{
    int i = 1;
    printf("i   j   e\n");
    while (a.data[i].i)
    {
        printf("%-4d%-4d%-4d", a.data[i].i, a.data[i].j, a.data[i].e);
        printf("\n");
        i++;
    }
}

int main()
{
    int i, j, p, q, col;
    tsmatrix t, m, s;
    int cpot[100], num[100];
    t.tu = 0;

//initialize the t
    printf("Enter the size(<=10): \n");
    printf("m= ");
    scanf("%d", &t.mu);
    printf("n= ");
    scanf("%d", &t.nu);
    printf("Enter the coordinate:\n");
    for (i=1;i<t.mu*t.nu;i++)
    {
        printf("i= ");
        scanf("%d", &t.data[i].i);
        if (!t.data[i].i) break;//exit requirement
        printf("j= ");
        scanf("%d", &t.data[i].j);
        printf("value= ");
        scanf("%d", &t.data[i].e);
        t.tu++;
    }
    printf("Raw list:\n");
    //printta(t);
    printlist(t);


//approach 01
    m.mu = t.nu;
    m.nu = t.mu;
    m.tu = t.tu;
    if (m.tu)
    {
        for (col=1;col<=t.nu;++col)//column
        {
            for (p=1;p<=t.tu;++p)//search every element in the t.data
            {
                if (t.data[p].j==col)
                {
                    m.data[p].i = t.data[p].j;
                    m.data[p].j = t.data[p].i;
                    m.data[p].e = t.data[p].e;
                }
            }
            m.data[p].i = 0;
        }
    }
    printf("Transformed list01\n");
    //printta(m);
    printlist(m);

//qpproach 02
    s.mu = t.nu;
    s.nu = t.mu;
    s.tu = t.tu;
    if (s.tu)
    {
        for (col=1;col<=t.nu;col++) num[col] = 0;
        for (j=1;j<=t.tu;j++) ++num[t.data[j].j];//calculate every column has how many valid numbers
        cpot[1] = 1;
        for (col=2;col<=s.nu;col++) cpot[col] = cpot[col-1] + num[col-1];
        for (p=1;p<=t.tu;p++)
        {
            col = t.data[p].j;
            q = cpot[col]++;
            s.data[q].i = t.data[p].j;
            s.data[q].j = t.data[p].i;
            s.data[q].e = t.data[p].e;
        }
    }
    printf("Transformed list02\n");
    printlist(s);

    return 0;
}
