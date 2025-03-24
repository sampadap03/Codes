/*Program to ADD money from rupees and paise using structure*/

#include<stdio.h>

struct money
{
int rs;
int ps;
};

int main()
{
struct money  m1,m2;
printf("Enter 1 amount in rs==ps:");
scanf("%d%d",&m1.rs,&m1.ps);
printf("Enter 2 amount in rs==ps:");
scanf("%d%d",&m2.rs,&m2.ps);
float a,b;
a=100*(m1.rs+m2.rs)+m1.ps+m2.ps;
b=((float)(m1.ps+m2.ps)/100)+m1.rs+m2.rs;
printf("Amount in rupees is:  %f",b);
printf("Amount in paise is :  %f",a);
return 0;
}
