#ifndef util.h
#define util.h
#include<time.h>
#include <string.h>
#include "stack.h"
#define pf printf
#define sf scanf

extern struct Train;



void trainReservation()
{
    struct Train *p;
    int trainfound=0;
    p=headTrain;
    if(p==NULL)
    {
        exit(1);
    }
    char source[30];
    char destination[30];
    char day[30];
    int trainNo,noOfSeats;
    pf("\nenter the source ");
    sf("%s",source);
    pf("\nenter the destination ");
    sf("%s",destination);
    pf("\nenter the day ");
    sf("%s",day);
    while(p!=NULL)
    {
        if(  strcasecmp(p->source,source)==0 && strcasecmp(p->destination,destination)==0  &&  strcasecmp(p->day,day)==0)
        {
            trainfound=1;
            pf("\n=============================================\n");
            pf("%d %s to %s on %s available seats are %d time is %s\n",p->trainNo,p->source,p->destination,p->day,p->noOfAvailableSeats,p->time);
            pf("=============================================\n");
        }
        p=p->next;
    }

    if(trainfound==0)
    {
        pf("Train not found");
        fordelay(2);
        menu();
    }
    p=headTrain;
    pf("\nEnter the train number: ");
    sf("%d",&trainNo);
    pf("\nEnter the no of seats required: ");
    sf("%d",&noOfSeats);
    while(p!=NULL)
    {
        if(p->trainNo==trainNo)
        {
            p->noOfAvailableSeats-=noOfSeats;
            int reserved[noOfSeats];
            int i=0;
            for(; i<noOfSeats; i++)
            {
                reserved[i]=pop(p);
                pf(" %d ",reserved[i]);
            }
            break;
        }
        p=p->next;
    }

}

int emailVerify(char *email)
{
    int count1=0;
    int count2=0;
    for(int i=0; i<strlen(email); i++)
    {
        if(email[i]=='@')
        {
            count1++;
        }
        else if(email[i]=='.')
        {
            count2++;
        }
    }

    if(count1==1 && count2==1)
    {
        return 1;
    }
    else
    {
        printf("Email is invalid!\n");
        return 0;
    }
}
int numberVerify(char *num)
{

    if(strlen(num)!=10)
    {
        printf("Mobile number is invalid!\n");
        return 0;
    }

    return 1;
}
int passwordVerify(char *p)
{

    if(strlen(p)<6)
    {
        printf("\nPassword is invalid!\n");
        return 0;
    }

    return 1;
}
int passwordMatch(char *p,char *c)
{
    if(strcasecmp(p,c)!=0)
    {
        printf("\nPassword not not matched!\n");
        return 0;
    }
    return 1;
};

void copyItem(char to[100],char from[100])
{
    int i;
    for(i=0; i<strlen(from); i++)
    {
        to[i]=from[i];
    }
    to[i]='\0';
}

void entryOfPassword(char *p)
{
    int i=0;
    pf("\nEnter the password(min 6 characters): ");
    while( 1 )
    {
        char ch=getch();
        if( ch == 13)
        {
            p[i]='\0';
            break;
        }
        else if( ch == 8)
        {
            i--;
            printf("\b \b");
        }
        else if( ch == 9 || ch== 32 )
        {
            continue;
        }
        else
        {
            p[i]=ch;
            i++;
            printf("*");
        }
    }
}

void fordelay(int j)
{
    int milli_sec=1000 * j;
    clock_t start_time=clock();
    while(clock() < start_time + milli_sec);
}

#endif // util




