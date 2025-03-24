//Purpose: Reversing the number
//Date: 8:25 PM 8/22/2017

#include<simplecpp>
main_program
{
int n, r;
cout<<"Enter the number:";
cin>>n;

repeat(3)
	{
	r=n%10;
	cout<<r;
	n=n/10;
	}
cout<<"\n";
}

