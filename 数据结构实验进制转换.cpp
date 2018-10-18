#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *top;
    int *base;
    int stacksize;
} SqStack;

void initstack(SqStack *s)
{
    s->base = (int *) malloc(100 * sizeof(int));
    if (!s->base) exit(0);
    s->top = s->base;
    s->stacksize = 100;
}

void push(SqStack *s, int e)
{
    if (s->top - s->base >= s->stacksize)
    {
        s->base = (int *) realloc(s->base, (s->stacksize + 100)*sizeof(int));
        if (!s->base) exit(0);
        s->top = s->base + s->stacksize;
        s->stacksize += 100;
    }
    *(s->top) = e;
	s->top++;
}

int pop(SqStack *s, int *e)
{
    if (s->top == s->base) return 0;
    else
    {
       *e = *--s->top;
       return 1;
    }
}

int main()
{
    int a, d, *e;
    SqStack s;
    initstack(&s);
    printf("Enter an integer: ");
    scanf("%d", &a);
    while (a)
    {
        push(&s, a%2);
        a = a/2;
    }

    d = pop(&s, e);
    printf("transformed number: ");
    while (d!=0)
    {
        printf("%d", *e);
        d = pop(&s, e);
    }
    printf("\n");
    
    return 0;
}
