#include<stdio.h>

int gcd(int n1,int n2);

void main()
{
int n1,n2,GCD;
printf("Enter first number: ");
scanf("%d",&n1);
printf("Enter second number: ");
scanf("%d",&n2);

GCD=gcd(n1,n2);

printf("\nGCD is: %d\n",GCD);



}

int gcd(int n1,int n2)
{

int x,r;

while(r!=0)
{
x=n1/n2;
//printf("\nx is %d",x);
r=n1%n2;
if(r==0)
	return n2;

//printf("\nr is%d",r);
n1=n2;
n2=r;
//printf("\nn2 is %d\n",n2);
}
return n2;
}
