/*sum an daverage of 1D array using pointer*/

void func(int *a,int n);

#include<stdio.h>
int main()
{
int i,n;

printf("Enter maximum numbers you want to enter: ");
scanf("%d",&n);
int arr[n];
for(i=0;i<n;i++)
	scanf("%d",&arr[i]);

func(arr,n);

return 0;
}

void func(int *a,int n)
{
int i,sum=0;

for(i=0;i<n;i++)
{
sum=sum+a[i];

}

printf("Sum of entered numbers is:  %d",sum);
printf("\n average of entered numbers is:  %f",(float)sum/n);

}
