/*Purpose: To display sum of odd values stored in an array

Date: 6:01 PM 10/10/2017*/



#include<stdio.h>
main()
{

int n, i, a[1000],sum=0;

printf("Enter the maximum elements you want in the array:\t");
scanf("%d",&n);


printf("\nEnter %d array elements:\t",&n);

for(i=0;i<n;i++)
	{
	
	scanf("%d\t",&a[i]);
	}

for(i=0;i<n;i++)
	{
	
	if(a[i]%2!=0)
		{
	
		sum=sum+a[i];
		}
	}


printf("\n\nSum of all odd numbers entered in the array is %d\n\n",&sum);



}