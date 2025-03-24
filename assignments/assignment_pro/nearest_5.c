/*Program to give nearest number divisible by 5*/

#include<stdio.h>

int determine5(int n);

void main()
{

int n,m;

printf("Enter the number:   ");
scanf("%d",&n);

m=determine5(n);

printf("\nNearest number divisible by 5 to the number  %d  is   %d\n\n",n,m);


}

int determine5(int n)
{

int a;

a=n%5;

switch(a)
{
case 0:
	return n;
case 1:
	return n-1;
	
case 2:
	return n-2;
case 3:
	return n+2;

case 4:
	return n+1;
}

}



























