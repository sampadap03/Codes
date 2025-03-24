/*Program to print array using function*/

#include<stdio.h>

void temp(int *,int n);

void main()
{

int i, n;
int a[100];
printf("Enter maximum limit: ");
scanf("%d",&n);

for(i=0;i<n;i++)
{

printf("Enter %d element:  ",i+1);
scanf("%d",&a[i]);
}

temp(a,n);
}

void temp(int *p, int n)
{
int i;
for(i=0;i<n;i++)
{

printf("\nElement %d is:  %d",i+1,*(p+i));
printf("\nElement %d is:  %d",i+1,*(i+p));
printf("\nElement %d is:  %d",i+1,p[i]);
printf("\nElement %d is:  %d",i+1,i[p]);
printf("\n");
}
}
