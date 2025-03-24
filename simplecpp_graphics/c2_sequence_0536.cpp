//Purpose: Program of generation of sequence
//Date: 8:29 PM 8/22/2017

#include<simplecpp>
main_program
{
int s;
int n=1;
cout<<"Enter how many numbers you want in the sequence:";
cin>>s;
repeat(s)
	{
	cout<<n;
	cout<<"\t";
	n=n+1;
	}
cout<<"\n";
}
