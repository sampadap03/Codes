/*greatest amongst two numbers*/
#include<stdio.h>

int greatest(int a,int b);

int main()
{
int m,a,b;
printf("Enter two numbers which you have to compare:");
scanf("%d%d",&a,&b);

m=greatest(a,b);
printf("Greatest number is:  %d",m);

return 0;
}

int greatest(int a,int b)
{

if(a==b)
printf("both are equal");

else if(a>b)
	return a;

else
	return b;

return a;
}
