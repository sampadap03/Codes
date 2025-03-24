#include<stdio.h>

void main()
{
int i,j;

int a[3][4]={
		{1,2,3},
		{4,5,6},
		{7,8,9}
		};

for(i=0;i<3;i++)
{

for(j=0;j<4;j++)
	{
	printf("\nnumber in %d column %d row:  %d",i+1,j+1,a[i][j]);

	//printf("%d\t",a[i][j]);
	}
printf("\n");
}		

}
