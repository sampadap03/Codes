#include<stdio.h>

void func(int a);
int fact(int a);

void main()
{

int i,n=1;

printf("sin(x)=  ");

for(i=1;i<=5;i++)
{
func(n);
n=n+1;

}
printf("\n");
}

void func(int n)
{

int q,denom;

q=2*n-1;
denom=fact(q);

if(n%2==0)
printf("-x^%d/%d",q,denom);
else
printf("+x^%d/%d",q,denom);

}

int fact(int q)
{
int fact=1;
while(q!=0)
	{
	
	fact=fact*q;
	q=q-1;
	}
//printf("\nfactorial is: %d\n",fact);
return fact;
}













