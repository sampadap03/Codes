//Purpose: Program of finding greatest of 5 numbers
//Date: 3:26 PM 8/26/2017

#include<simplecpp>
main_program
{

int a, b, c, d, e;

cout<<"Enter five numbers amongst which we have to find the greatest:";
cin>>a>>b>>c>>d>>e;

if ((a>b)&&(a>c)&&(a>d)&&(a>e))
	{
	cout<<"Greatest number is:"<<a;
	}

else if ((a<b)&&(b>c)&&(b>d)&&(b>e))
	{
	cout<<"Greatest number is:"<<b;
	}

else if ((a<c)&&(b<c)&&(c>d)&&(c>e))
	{
	cout<<"Greatest number is:"<<c;
	}

else if ((a<d)&&(b<d)&&(c<d)&&(d>e))
	{
	cout<<"Greatest number is:"<<d;
	}

else if ((a<e)&&(b<e)&&(c<e)&&(d<e))
	{
	cout<<"Greatest number is:"<<e;
	}

else
	{
	cout<<"All numbers are equal";
	}


}


