/*Program of linear search

Date: 5:50 PM 10/10/2017*/

#include<simplecpp>
main_program()
{

int i,n,a[1000],search,flag=0;

cout<<"Enter maximum number of elements to have in the array:\t";
cin>>n;

cout<<"\nEnterarray elements:\t";
for(i=0;i<n;i++)
	{
	
	cin>>a[i];
	}

cout<<"\nEnter the number to search in given array:\t";
cin>>search;

for(i=0;i<n;i++)
	{
	
	if(a[i]==search)
		{

		cout<<"\n\nEntered number is present in the given array";
		flag=1;
		}

}


if(flag==0)
	{

	cout<<"\n\nEntered number is not present in the given array.\n\n";


}
}
