//Purpose: Program of arithmatic operations on two complex numbers accepting input
//Date: 5/9/2017
//GR No.: 1710536
//


#include<simplecpp>
#include<stdlib.h>
main_program
{

float a, b, x, y, m, n;
int s;

cout<<"Please enter real part of first number:";
cin>>a;

cout<<"Please enter imaginary part of first number:";
cin>>b;

cout<<"Please enter real part of second number:";
cin>>x;

cout<<"Please enter imaginary part of second number:";
cin>>y;

cout<<"Numbers entered by you are:\n";
cout<<a<<"+i"<<b<<"\n";
cout<<x<<"+i"<<y<<"\n";
cout<<"\n";

while(1)
{

cout<<"Please select an operation:\n";
cout<<"1: Addition\n";
cout<<"2: Subtraction\n";
cout<<"3: Multiplication\n";
cout<<"4: Division\n";
cout<<"5: Exit\n";
cin>>s;

switch(s)
{

case 1: m=a+x;
	n=b+y;

cout<<"Addition is: ";
cout<<m<<"+i"<<n<<"\n";
break;

case 2: m=a-x;
	n=b-y;
	
cout<<"Subtraction is: ";
	if(n>=0)
		{
		cout<<m<<"+i"<<n<<"\n\n";
		}
	else
		{
		cout<<m<<"+"<<n<<"i\n\n";
		}
break;

case 3: m=(a*x)-(b*y);
	n=(b*x)+(a*y);

cout<<"Multiplication is: ";
	if(n>=0)
		{
		cout<<m<<"+i"<<n<<"\n\n";
		}
	else
		{
		cout<<m<<"+"<<n<<"i\n\n";
		}
break;

case 4: m=((a*x)+(b*y))/((x*x)+(y*y));
	n=((b*x)-(a*y))/((x*x)+(y*y));

cout<<"Division is: ";	
	if(n>=0)
		{
		cout<<m<<"+i"<<n<<"\n\n";
		}
	else
		{
		cout<<m<<"+"<<n<<"i\n\n";
		}
break;

case 5: exit(1);
break;

default: cout<<"Invalid input.\n\n";


}

}

}
