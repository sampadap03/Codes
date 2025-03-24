//Purpose: Program of checking which number is greatest amongst 3
//Date: 3:18 PM 8/26/2017

#include<simplecpp>
main_program
{

int a, b, c;

cout<<"Type three numbers of which we have to calculate the greatest number:";
cin>>a>>b>>c;

if ((a>b)&&(a>c))
	{
	cout<<"The greatest number is:"<<a;
	}
else if ((b<c)&&(a<c))
	{
	cout<<"The greatest number is:"<<c;
	}
else if ((b>a)&&(b>c))
	{
	cout<<"The greatest number is:"<<b;
	}
else
	{
	cout<<"All numbers are equal";
	}

}
