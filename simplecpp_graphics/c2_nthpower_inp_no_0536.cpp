//Purpose: Program of nth power of input number(<=10)
//Date: 2:09 PM 8/27/2017

#include<simplecpp>
main_program
{

int n=0;
int m=0;

cout<<"Enter the number:";
cin>>n;

cout<<"Enter the power of number to which to be calculated:";
cout<<"It should be less than or equal to 10";
cin>>m;

if (m==0) 
	n=1;
else if (m==1)
	n=n;
else if (m==2)
	n=n*n;
else if (m==3)
	n=n*n*n;
else if (m==4)
	n=n*n*n*n;
else if (m==5)
	n=n*n*n*n*n;
else if (m==6)
	n=n*n*n*n*n*n;
else if (m==7)
	n=n*n*n*n*n*n*n;
else if (m==8)
	n=n*n*n*n*n*n*n*n;
else if (m==9)
	n=n*n*n*n*n*n*n*n*n;
else if (m==10)
	n=n*n*n*n*n*n*n*n*n*n;
cout<<n;

}
