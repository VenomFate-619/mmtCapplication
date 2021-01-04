#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include<time.h>
#include "util.h"
#define pf printf
#define sf scanf

struct  User
{
    char email[30];
    char name[30];
    int _id;
    char password[20];
    char mobileNo[12];
    struct User *next;
}*head=NULL;

void menu();
void registerUser();
void login();


void menu()
{
    int choice;
  // system("cls");
    system("color 9");
    printf("\n\n\t\t\tMake my trip fast");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Create new account\n\t\t2.View \n\t\t3.Book a train\n\t\t4.Check the details of existing account\n\t\t5.Removing existing account\n\t\t6.View customer's list\n\t\t7.Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        registerUser();
        system("cls");
        menu();
        break;
    case 2:
        view();
        break;
    default:
        exit(1);
    }
}

void view()
{

    if(head!=NULL)
    {

        struct User *p=head;
        while(p!=NULL)
// TODO (AnyOne#1#): Add remaing items
        {

            pf("\n %s \n",p->name);
//            pf("\n %s \n",p->email);
            //pf("\n %s \n",p->mobileNo);
            p=p->next;
        }
    }
}

void addUser(struct User *newUser)
{
    struct User *q=head;

    if(head==NULL)
    {
        head=newUser;
    }
    else
    {
        while(q->next!=NULL)
        {
            q=q->next;
        }
        q->next=newUser;
    }
}




void extractUsersFromFile()
{
    FILE *user_ptr;
    struct User *user=NULL;
    char userName[100];
    char userEmail[100];
    char userPassword[100];
    char mobileNo[100];
    char read;
    int temp=0;
    user_ptr=fopen("user_info.txt","r");
    if(user_ptr==NULL)
    {
        printf("ERROR! File opening\n");
        exit(1);
    }
    mobileNo[0]='\0';
    userName[0]='\0';
    userEmail[0]='\0';
    userPassword[0]='\0';
    do
    {
        read=fgetc(user_ptr);
        if(read=='=')
        {
            temp++;
        }
        else
        {
            if(read!='\n')
            {

                if(temp==0)
                {
                    userEmail[strlen(userEmail)+1]='\0';
                    userEmail[strlen(userEmail)]=read;

                }
                else if(temp==1)
                {

                    userName[strlen(userName)+1]='\0';
                    userName[strlen(userName)]=read;

                }
                else if(temp==2)
                {
                    userPassword[strlen(userPassword)+1]='\0';
                    userPassword[strlen(userPassword)]=read;

                }
                else
                {
                    mobileNo[strlen(mobileNo)+1]='\0';
                    mobileNo[strlen(mobileNo)]=read;
                }
            }
            else
            {
                pf(" working ");
                user=(struct User*)malloc(sizeof(struct User));
                if(user==NULL)
                {
                    printf("Heap overflow!");
                    exit(1);
                }
                copyItem(user->email,userEmail);
                copyItem(user->name,userName);
                copyItem(user->password,userPassword);
                copyItem(user->mobileNo,mobileNo);
                user->next=NULL;
                addUser(user);
                userName[0]='\0';
                userEmail[0]='\0';
                userPassword[0]='\0';
                mobileNo[0]='\0';
                temp=0;
            }
        }
    }
    while(!feof(user_ptr));
}
void registerUser()
{
    char userName[100];
    char userEmail[100];
    char userPassword[100];
    char confirmPassword[100];
    char mobileNo[10];
    pf("Enter your Details :)\n");
    pf("Enter the name: ");
    sf(" %[^\n]",userName);
//    pf("%s",userName);
//    email
    do
    {
        printf("Enter the email: ");
        scanf(" %[^\n]",userEmail);
    }
    while(!emailVerify(userEmail));
//    Uncomment it,it is necessary
//    mobile number
    do
    {
        printf("Enter the mobile number: ");
        scanf("%s",mobileNo);
    }
    while(!numberVerify(mobileNo));

//    password

    do
    {
        int i=0;
        pf("Enter the password(min 6 characters): ");
        while( 1 )
        {
            char ch=getch();
            if( ch == 13)
            {
                userPassword[i]='\0';
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
                userPassword[i]=ch;
                i++;
                printf("*");
            }
        }
    }
    while(!passwordVerify(userPassword));


// confirm password
// TODO (AnyOne#1#): REFRACTOR  THE PASSWORD ENTRY CODE IN UTIL.H

    do
    {
        int i=0;
        pf("\nConfirm the password: ");
        while( 1 )
        {
            char ch=getch();
            if( ch == 13)
            {
                confirmPassword[i]='\0';
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
                confirmPassword[i]=ch;
                i++;
                printf("*");
            }
        }
    }
    while(!passwordMatch(userPassword,confirmPassword) );


// checking the user already exists
//    FILE *fp;
//    fp=fopen("user_info.txt", "r");

    struct  User *newUser;
    newUser=(struct User*)malloc(sizeof(struct User));
    if(newUser==NULL)
    {
        pf("Heap memory overflow");
        exit(1);
    }

// coping data
    copyItem(newUser->email,userEmail);
    copyItem(newUser->name,userName);
    copyItem(newUser->password,userPassword);
    copyItem(newUser->mobileNo,mobileNo);



// adding to linked list

    addUser(newUser);
// TODO (AnyOne#1#): Add user in file(users.txt)
    FILE *fp;
    fp = fopen("user_info.txt", "a+");
    if(pf==NULL)
    {
        pf("Error in opening the file");
        exit(1);
    }
    else
    {
        fprintf(fp,"%s=%s=%s=%s\n",userEmail,userName,userPassword,mobileNo);
        fclose(fp);

    }
}


int main()
{
    extractUsersFromFile();
    menu();
    return 0;
}
