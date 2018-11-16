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

typedef struct
{
    triple data[101];
    int rpos[11];
    int mu, nu, tu;
} rlsmatrix;

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

void printlist02(rlsmatrix a)
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

void printta01(tsmatrix a)
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

void printta02(rlsmatrix *a)
{
    int i = 1;
    printf("i   j   e\n");
    while (a->data[i].i)
    {
        printf("%-4d%-4d%-4d", a->data[i].i, a->data[i].j, a->data[i].e);
        printf("\n");
        i++;
    }
}

rlsmatrix calrpos(rlsmatrix a)
{
    int row, j;
    int num[11];

    for (row=1;row<=a.nu;row++) num[row] = 0;
    for (j=1;j<=a.tu;j++) ++num[a.data[j].i];
    a.rpos[1] = 1;
    for (j=2;j<=a.mu;j++)
    {
        a.rpos[j] = a.rpos[j-1] + num[j-1];
        printf("rpos[%d]=%d\n", j, a.rpos[j]);
    }

    return a;
}

void multi(rlsmatrix a, rlsmatrix b, rlsmatrix *z)
{
    int i, p, q;
    int arow, brow, tp, t, ccol;
    int ctemp[11];

    z->mu = a.mu;
    z->nu = b.nu;
    z->tu = 0;
    if (a.tu*b.tu!=0)
    {
        for (arow=1;arow<=a.mu;arow++)
        {
            for (i=1;i<11;i++)
            {
                ctemp[i] = 0;
            }
            z->rpos[arow] = z->tu + 1;
            if (arow<z->mu) tp = a.rpos[arow + 1];
            else tp = a.tu + 1;
            for (p=a.rpos[arow];p<tp;p++)
            {
                brow = a.data[p].j;
                if (brow<b.mu) t = b.rpos[brow+1];
                else t = b.tu + 1;
                for (q=b.rpos[brow];q<t;q++)
                {
                    ccol = b.data[q].j;
                    ctemp[ccol] += a.data[p].e * b.data[q].e;
                }
            }
            for (ccol=1;ccol<=z->nu;ccol++)
            {
                if (ctemp[ccol])
                {
                    if (++z->tu>100) printf("error\n");
                    z->data[z->tu] = {arow, ccol, ctemp[ccol]};
                }
            }
        }
    }
}

int main()
{
    int i, j, p, q, col;
    tsmatrix t, m, s;
    int cpot[100], num[100];
    t.tu = 0;

    rlsmatrix x, y, z, *p1 = &z;
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
    //printta01(t);
    printlist(t);//t is the raw list


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
    //printta01(m);
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
        for (col=2;col<=t.nu;col++) cpot[col] = cpot[col-1] + num[col-1];
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

//multiply
    x.mu = t.mu;
    x.nu = t.nu;
    x.tu = t.tu;
    for (i=1;i<=t.tu;i++)
    {
        x.data[i] = t.data[i];
    }
    y.mu = x.nu;
    printf("Enter the y's col:\n");
    printf("n = ");
    scanf("%d", &y.nu);
    printf("Enter the coordinate:\n");
    y.tu = 0;
    for (i=1;i<y.mu*y.nu;i++)
    {
        printf("i= ");
        scanf("%d", &y.data[i].i);
        if (!y.data[i].i) break;//exit requirement
        printf("j= ");
        scanf("%d", &y.data[i].j);
        printf("value= ");
        scanf("%d", &y.data[i].e);
        y.tu++;
    }
    printf("x\n");
    x = calrpos(x);
    printf("y\n");
    y = calrpos(y);
    printf("x:\n");
    printta02(&x);
    printf("y:\n");
    printta02(&y);
    multi(x, y, p1);
    printf("Result:\n");
    printlist02(z);

    return 0;
}
