#include<stdio.h>

void count(int *p,int *e,int *o, int);

void main()
{

int n,i;
int counte=0,counto=0;

int a[300];

printf("Enter maximum numbers: ");
scanf("%d",&n);

for(i=0;i<n;i++)
{

printf("Enter element %d ", i+1);
scanf("%d",&a[i]);

}

count(a,&counte,&counto,n);

printf("\n\nCount of even numbers is: %d",counte);
printf("\n\nCount of odd numbers is: %d",counto);

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
