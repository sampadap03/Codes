/*Program of addition of 25 natural numbers usin recursion*/

#include<stdio.h>
int sum(int a,int b);

int main()
{

int a=1,s,b=0;
s=sum(a,b);
printf("Sum of 25 natural numbers is:  %d",s);

}

int sum(int a,int b)
{


if(a<=25)
	b=a+sum(a+1,b);

else
	return 0;

return b;

}
