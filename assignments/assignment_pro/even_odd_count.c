#include<stdio.h>

void count(int *p,int *e,int *o, int *z);

void main()
{

int n,i;
int counte=0,counto=0,countz=0;
int *x=&counte, *y=&counto, *z=&countz;
int a[30];

Printf("Enter maximum numbers: ");
scanf("%d",&n);

for(i=0;i<n;i++)
{

printf("Enter element %d", i+1);
scanf("%d",a[i]);

}

count(a,x,y,z);

printf("\n\nCount of even numbers is: %d",x);
printf("\n\nCount of odd numbers is: %d",y);
printf("\n\nCount of zeros is: %d",z);
}



void count(int *p,int *e,int *o, int *z)
{



if(*p%2==0)
	*e++;
if(*p==0)
	*z++;
else
	*o++;

}
