//Purpose: To declare an array globally
//Date: 28/10/2017


#include<stdio.h>

int a[10];

void func();

void main()
{

int i;

for(i=0;i<10;i++)
	{

	printf("\nEnter %d number:",i+1);
	scanf("%d",&a[i]);
	}

func();
}

extern int a[10];  // It does not depend on the name of variable whether it is a[] or arr[], it works with both

void func()
{

int i;

for(i=0;i<10;i++)
printf("\na[%d] = %d",i,a[i]);
}
