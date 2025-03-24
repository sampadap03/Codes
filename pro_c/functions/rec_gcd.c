#include<stdio.h>

int gcd(int m, int n);

void main()
{
int n,m;
scanf("%d",&n);
scanf("%d",&m);

int t=0;
t=gcd(m,n);
printf("%d",t);
}

int gcd(int m, int n)
{
int r=0;
r=m%n;
if(r==0)
return n;

return(gcd(n,r));
}
