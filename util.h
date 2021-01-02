//#include "struct.h"
#define pf printf
#define sf scanf

//extern struct User;

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





