#include<stdio.h>
int main()
{
long long int a[5],b[5];
int i,j;
for(i=0;i<5;i++) scanf("%lld",&a[i]);

for(i=0;i<5;i++)
{
long long int sum=0;
for(j=0;j<5;j++)
{
if(j!=i) sum+=a[j];

}
b[i]=sum;
}
for(i=0;i<5;i++)
{
for(j=i;j<5;j++)
{

if(b[i]>b[j])
{

 long long int t;
t=b[i];
b[i]=b[j];
b[j]=t;
}
}
}

printf("%lld %lld",b[0],b[4]);
return 0;
}
