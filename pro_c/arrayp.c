

/*ASSIGNMENT 6
Program to print counters of even and odd numbers in given array
NAME:MANASI MORE
ROLL NO:C36
---------------------------------------------------------------------------------------------------------------------------------*/


#include<stdio.h>

void count(int *p,int *e,int *o, int);

void main()
{

int n,i;
int ce=0,co=0;

int a[200];

printf("Enter maximum numbers: ");
scanf("%d",&n);

for(i=0;i<n;i++)
{

printf("Enter element %d ", i+1);
scanf("%d",&a[i]);

}

count(a,&ce,&co,n);

printf("\n\nnumber of even numbers is: %d",ce);
printf("\n\nnumberof odd numbers is: %d",co);

printf("\n\n");
}

void count(int *p,int *e,int *o,int n)
{
int i;
for(i=0;i<n;i++)
{

if(*(p+i)%2==0)
	*e=*e+1;

if(*(p+i)%2==1)
	*o=*o+1;

}
}
