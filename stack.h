#ifndef stack.h
#define stack.h
#include <stdio.h>
#include <stdlib.h>

struct User{
    char email[30];
    char name[30];
    int _id;
    char password[20];
    char mobileNo[12];
    struct User *next;
}*head=NULL;


struct Train
{
    int trainNo;
    char source[30];
    char destination[30];
    char day[30];
    char time[30];
    int noOfAvailableSeats;
    char *availableSeatsStack;
    struct Train *next;
    int top;
}*headTrain=NULL;


void createStack(struct Train *p)
{
    p->top=-1;
    p->availableSeatsStack=(char *)malloc(sizeof(char)*p->noOfAvailableSeats);
    int i=1;
    for(;i<=p->noOfAvailableSeats;i++)
    {
       push(p,i);
    }
    p->availableSeatsStack[i]='\0';
}
void push(struct Train *p,char x){

   if(p->top!=p->noOfAvailableSeats)
   {
       p->top++;
       p->availableSeatsStack[p->top]=x;
    }
    else
   {
        printf("overflow in push\n");
    }
}
void displayStack(struct Train *p)
{
    for(int i=p->top; i>=0; i--)
    {
        printf("%d ", p->availableSeatsStack[i]);
    }

}

char pop(struct Train *p)
{

    int x=0;
    if(p->top!=-1)
    {
        x=p->availableSeatsStack[p->top--];
    }
    else
    {
        printf("underflow\n");
    }
    return x;
}
#endif // stack

