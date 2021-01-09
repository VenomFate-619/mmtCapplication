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
    int top;
    char source[30];
    char destination[30];
    char day[30];
    char time[30];
    int noOfAvailableSeats;
    char *availableSeatsStack;
    struct Train *next;
}*headTrain=NULL;

void createStack(struct Train *p)
{

  printf(" %d ",p->trainNo);
}
//void push(struct Train *p,char x)
//{
//    if(p->top!=p->noOfAvailableSeats-1)
//    {
//        p->top++;
//        p->a[p->top]=x;
//    }
//    else
//    {
//        printf("overflow\n");
//    }
//}

