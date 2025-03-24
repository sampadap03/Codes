/*Input and output using pointer of 2D array*/

#include<stdio.h>
void input(int *a);
void output(int *a);

void main()
{

int a[3][3];

for(j=0;j<3;j++)
{
for(i=0;i<3;i++)
{
printf("Enter the %d row and %d th column element:  ",j,i);
scanf("%d",*a[j][i]);
}
}

input(a);
output(a);

}

void input(int *a)
{
int i,j;

for(j=0;j<3;j++)
{
for(i=0;i<3;i++)
{
printf("Enter the %d row and %d th column element:  ",j,i);
scanf("%d",*a[j][i]);
}
}
}

void output(int *a)
{
int i,j;

for(j=0;j<3;j++)
{
for(i=0;i<3;i++)
{
printf("The %d row and %d th column element:  %d",j,i,*a[j][i]);

}
}
}

