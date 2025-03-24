#include<stdio.h>

int lcm(int a,int b);

void main()
{

int ans;
int a, b;
printf("Enter first number:  ");
scanf("%d",&a);

printf("Enter second number:  ");
scanf("%d",&b);

ans=lcm(a,b);

printf("\n\nLcm of given numbers is:  %d\n\n",ans);
}

int lcm(int a,int b)
{

static int c=1;

if(c%a==0 && c%b==0)
	return c;

c++;

lcm(a,b);
//printf("sss");
return c;
}
