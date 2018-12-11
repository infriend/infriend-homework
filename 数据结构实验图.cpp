/*实验性质：设计性实验
实验内容：最小生成树。
实验目的和要求：理解图的创建方法，懂得利用PRIM算法或克鲁斯卡尔算法实现最小生成树。
懂得拓扑排序算法
注意点：PRIM算法和克鲁斯卡尔算法的区别*/

#include <cstdio>
#include <cstdlib>
#include <stack>
#define infinite 10000
using namespace std;

//邻接矩阵表示法，该图顶点不存储信息
typedef struct
{
    int vexs[20];//最多20个顶点
    int arc[20][20];//最多400条弧
    int vexnum, arcnum;//存储该图顶点和弧的数量
} mgraph;

//邻接表表示法
typedef struct arcnode//表结点
{
    int adjvex;
    struct arcnode *next;
} arcnode;
typedef struct vnode//头结点
{
    int data;
    arcnode *firstarc;
} vnode;
typedef struct
{
    vnode vex[20];//最多20个顶点
    int vexnum, arcnum;
} algraph;

typedef struct
{
    int adjvex;
    int lowcost;
} closedge;

mgraph mgcreat(void)
{
    mgraph t;
    int i, j, n, k = 0;

    printf("n = ");
    scanf("%d", &n);
    t.vexnum = n;
    for (i = 0; i < t.vexnum; ++i)
    {
        t.vexs[i] = i;
        for (j = 0; j < t.vexnum; ++j)
        {
            t.arc[i][j] = infinite;
        }
    }

    printf("-1 means entering process is over\n");
    while (1)
    {
        printf("Enter i, j: ");
        scanf("%d,%d", &i, &j);
        if (i == -1||j == -1) break;
        printf("Enter the arclength: ");
        scanf("%d", &t.arc[i][j]);
        k++;
        t.arc[j][i] = t.arc[i][j];
    }
    t.arcnum = k;
    printf("\n");
    for (i = 0; i < t.vexnum; ++i)
    {
        for (j = 0; j < t.vexnum; ++j)
        {
            printf("%-6d", t.arc[i][j]);
        }
        printf("\n");
    }


    return t;
}

algraph algcreat(void)
{
    int i, n, k = 0, e = 0;
    arcnode *p, *q;
    algraph t;

    printf("n = ");
    scanf("%d", &n);
    t.vexnum = n;
    for (i = 0; i < t.vexnum; ++i)//邻接表从0开始
    {
        printf("Enter the vex data:");
        scanf("%d", &t.vex[i].data);
        printf("Enter the vexnum:(-1 means the end of the operation)");
        p = (arcnode*) malloc(sizeof(arcnode));
        t.vex[i].firstarc = NULL;
        scanf("%d", &e);
        if (e!=-1)
        {
            t.vex[i].firstarc = p;
            q = p;
        }
        while (e!=-1)
        {
            q->adjvex = e;
            p = q;
            k++;
            q = (arcnode*) malloc(sizeof(arcnode));
            p->next = q;
            scanf("%d", &e);
        }
        p->next = NULL;
        free(q);
    }
    t.arcnum = k;

    return t;
}

int minnum(closedge *c, int vexnum)
{
    int i, min;
    for (i = 0; i < vexnum; ++i)
    {
        if (c[i].lowcost > 0)
        {
            min = i;
            break;
        }
    }
    for (; i < vexnum; ++i)
    {
        if (c[i].lowcost > 0)
        {
            if (c[i].lowcost < c[min].lowcost) min = i;
        }
    }

    return min;
}

void mcst_prim()//从第u个顶点出发
{
    mgraph g;
    int i, j, k, u;
    g = mgcreat();
    closedge clo[20];
    printf("Start from:");
    scanf("%d", &u);
    k = u;
    for (j = 0; j < g.vexnum; ++j)
    {
        if (j!=k) clo[j] = {u, g.arc[k][j]};
    }
    clo[k].lowcost = 0;
    for (i = 1; i < g.vexnum; ++i)
    {
        k = minnum(clo, g.vexnum);
        printf("(%d, %d)\n", clo[k].adjvex, k);
        clo[k].lowcost = 0;
        for (j = 0; j < g.vexnum; ++j)
        {
            if (g.arc[k][j] < clo[j].lowcost)
            {
                clo[j] = {k, g.arc[k][j]};
            }
        }
        printf("\n");
    }
}

void findalg_indegree(algraph* g, int a[])
{
    int i;
    arcnode *p;

    for (i = 0; i < 20; ++i)
    {
        a[i] = 0;
    }
    for (i = 0; i < g->vexnum; ++i)
    {
        p = g->vex[i].firstarc;

        while (p!=NULL)
        {
            ++a[p->adjvex];
            p = p->next;
        }
    }
}

void toposort(void)
{
    int i, count, k;
    int a[20];
    algraph g;
    arcnode *p;
    g = algcreat();
    findalg_indegree(&g, a);
    stack<int> s;

    for (i = 0; i < g.vexnum; ++i)
    {
        if (!a[i]) s.push(i);
    }
    count = 0;
    while (!s.empty())
    {
        printf("%-4d", i = s.top());
        s.pop();
        ++count;
        for (p = g.vex[i].firstarc; p; p = p->next)
        {
            k = p->adjvex;
            if (!(--a[k])) s.push(k);
        }
    }
    if (count < g.vexnum)
    {
        printf("Error\n");
    }
    else
    {
        printf("Success\n");
    }
}

int main()
{
    //printf("Prim:\n");
    //mcst_prim();
    printf("toposort:\n");
    toposort();

    return 0;
}
