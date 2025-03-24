#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct shopping
{

char name[30];
int accno;
float amt;
int pid;

};

void main()
{

struct shopping s1;

int a;

a=sizeof(s1);
printf("\nSize of whole structure is: %d",a);
printf("\n\nSize of s1.name is  :%d",sizeof(s1.name));
printf("\n\nSize of s1.accno is  :%d",sizeof(s1.accno));
printf("\n\nSize of s1.amt is  :%d",sizeof(s1.amt));
printf("\n\nSize of s1.pid is  :%d",sizeof(s1.pid));

printf("\n\nEnter your name: ");
gets(s1.name);
fflush(stdin);
printf("\nEnter your account number:");
scanf("%d",&s1.accno);
fflush(stdin);
printf("\nEnter amount to be paid:");
scanf("%f",&s1.amt);
fflush(stdin);
printf("\nEnter the product code of your choice:");
scanf("%d",&s1.pid);
fflush(stdin);

printf("\n\naddress of entered name is:  %2u and name is %s",s1.name,s1.name);
printf("\n Address of entered account number is:  %u and account number is:  %d",&s1.accno, s1.accno);
printf("\n Address of entered amount to be paid is :  %u  and value is:  %f",&s1.amt, s1.amt);
printf("\n Address of entered product code is :  %u and  value is  %d\n\n",&s1.pid, s1.pid);




















}
