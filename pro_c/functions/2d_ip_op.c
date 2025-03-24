#include<stdio.h>
void input(int *a);
void output(int *a,int i,int j);

void main()
{

int a[10][10],i,j;


for(j=0;j<3;j++)
{
for(i=0;i<3;i++)
{
printf("Enter the %d row and %d th column element:  ",j+1,i+1);
input(&a[j][i]);
}
}

for(j=0;j<3;j++)
{
for(i=0;i<3;i++)
{
output(&a[j][i],i+1,j+1);
}
}
printf("\n");
}

void input(int *p)
{//printf("e");
scanf("%d",p);
//printf("f");
}

void output(int *q,int i,int j)
{
printf("\nthe %d row and %d th column element:  %d",j,i,*q);
}


