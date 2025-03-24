#include<stdio.h>

void main()
{

int n,m,i,j;
int a[20][20];

printf("Enter maximum rows in the array: ");
scanf("%d",&n);

printf("\nEnter maximum no of columns in array: ");
scanf("%d",&m);

for(i=0;i<m;i++)
{

for(j=0;j<n;j++)
	{
	printf("Enter number in %d column %d row:  ",i+1,j+1);
	scanf("%d",&a[i][j]);
	}
}


for(i=0;i<m;i++)
{

for(j=0;j<n;j++)
	{
	//printf("\nnumber in %d column %d row:  %d",i+1,j+1,a[i][j]);

	printf("%d\t",a[i][j]);
	}
printf("\n");
}

printf("\n");
}
