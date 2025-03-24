#include<stdio.h>
int main()
{

int n,i,a[20],b;

printf("Enter maximum number of elements to have in the array:\t");
scanf("%d",&n);

for(i=0;i<n;i++)
{

printf("Enter element %d:\t\t",i+1);
scanf("%d",&a[i]);

}

printf("Enter the position of number to delete:\t");
scanf("%d",&b);

for(i=b-1;i<n;i++)
{

a[i]=a[i+1];
}

n=n-1;
printf("New array is:\t");
for(i=0;i<n;i++)
{
printf("%d\t\t",a[i]);
}

printf("\n");
}
