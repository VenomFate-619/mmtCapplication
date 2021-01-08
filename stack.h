#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int top;
    int size;
    int *a;
};
* create(struct stack *p,int seats)
{
    p->size=seats;
    p->top=-1;
    p->a=malloc(sizeof(int) * seats);
    for(int i=0;i<seats;i++)
    {
        p->a[i]=i+1;
    }
    return p->a;

}
void display(struct stack p)
{
    for(int i=p.top;i>=0;i--)
    {
        printf("%d ",p.a[i]);
    }
    printf('\n');
}
void push(struct stack *p,int x)
{
    if(p->top!=p->size-1)
    {
        p->top++;
        p->a[p->top]=x;
    }
    else
    {
        printf("overflow\n");
    }
}
int  pop(struct stack *p)
{
    int x=-1;
    if(p->top!=-1)
    {
        x=p->a[p->top--];
    }
    else
    {
        printf("underflow\n");
    }
    return x;
}


