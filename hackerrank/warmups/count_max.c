#include<stdio.h>
int main()
{
int i;
int n;
scanf("%d",&n);
int a[n];
for(i=0;i<n;i++) scanf("%d",&a[i]);
int max=1;
for(i=0;i<n;i++)
{
if(max<a[i]) max=a[i];
}
printf("%d",max);
int count=0;
for(i=0;i<n;i++)
{
if(a[i]==max) count++;
}
printf("%d",count);
return 0;
}
