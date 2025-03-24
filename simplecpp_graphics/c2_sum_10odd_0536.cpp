//Purpose: Program of finding sum of 10odd numbers
//Date: 8:33 PM 8/22/2017

#include<simplecpp>
main_program
{

int n=0;
int sum=0;

repeat(10)
	{
	cout<<"n="<<n<<"\t";
	sum=sum+n;
	n=n+2;
	cout<<"sum"<<sum<<"\n";
	}

cout<<"\n Final sum is:"<<sum;
cout<<"\n";
}
