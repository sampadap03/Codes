//Purpose: Program of factorial
//Date: 8:42 PM 8/22/2017

#include<simplecpp>
main_program
{

int n;
int fact=1;

cout<<"Enter a number of factorial to be calculated:";
cin>>n;
{
repeat(n)
	{
	fact=fact*n;
	n=n-1;
	}

cout<<"Factorial is"<<fact<<"\n";
}
}
