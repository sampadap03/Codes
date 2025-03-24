#include<stdio.h>
#define MAX_SIZE 100
int main()
{
int arr[MAX_SIZE];
int i,n,p;
printf("enter size of array:");
scanf("%d",&n);
printf("enter elements in array");
for(i=0;i<n;i++)
{scanf("%d",&arr[i]);
}
printf("enter the element position to delete");
scanf("%d",&p);
if(p==n+1||p<0)
{printf("invalid position");
}
else
for(i=p-1;i<n;i++)
{arr[i]=arr[i+1];
}
n--;
printf("\nelements of array after deletion are:");
for(i=0;i<n;i++)
{printf("%d\t",arr[i]);
}
return 0;
}
