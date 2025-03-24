#include<stdio.h>

void fact(int);

void main()
{

int n;
printf("Enter num: ");
scanf("%d",&n);

printf("Factors are:  ");
fact(n);
printf("\n");
}

void fact(int n)
{
int a=2;
while(a<=n)
{

	while(n%a==0)
	{
	
	
	printf("%d  ",a);
	n=n/a;
	}

a++;
}
}
