/*Program of linear search

Date: 5:50 PM 10/10/2017*/

#include<stdio.h>
main()
{

int i,n,a[1000],search,flag=0;

printf("Enter maximum number of elements to have in the array:\t");
scanf("%d",&n);

printf("\nEnter %d array elements:\t",n);
for(i=0;i<n;i++)
	{
	
	scanf("%d\t",&a[i]);
	}

printf("\nEnter the number to search in given array:\t");
scanf("%d",&search);

for(i=0;i<n;i++)
	{
	
	if(a[i]==search)
		{

		printf("\n\nEntered number is present in the given array");
		flag=1;
		}

}


if(flag==0)
	{

	printf("\n\nEntered number is not present in the given array.\n\n");


}
}
