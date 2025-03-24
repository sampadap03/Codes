//Purpose: Program of arithmatic operations on two complex numbers accepting input
//Date: 5/9/2017
//GR No.: 1710536
//Roll No.: C 34


#include<simplecpp>
#include<stdlib.h>
main_program  //Main program starts here
{

float a, b, x, y, m, n; //Variable declaration; those can be fraction as well as real.
int s;

cout<<"Please enter real part of first number:\t"; //output taking real part of first number.
cin>>a; //declaring value of variable 

cout<<"Please enter imaginary part of first number:\t"; //output saying to enter imaginary part of first number.
cin>>b; // placing value to variable 

cout<<"Please enter real part of second number:\t"; //output saying to enter real part of second number.
cin>>x; // putting input value to variable

cout<<"Please enter imaginary part of second number:\t";  //output saying to enter imaginary part of second number.

cin>>y;  // putting input value to variable

cout<<"Numbers entered by you are:\n";  // showing  numbers provided by the user
cout<<a<<"+i"<<b<<"\n";
cout<<x<<"+i"<<y<<"\n";
cout<<"\n";

while(1)  //to run program infinitely we put any true value here; while loop starts here 
{

cout<<"Please select an operation:\n";  // asking to choose any of the following operations
cout<<"1: Addition\n";
cout<<"2: Subtraction\n";
cout<<"3: Multiplication\n";
cout<<"4: Division\n";
cout<<"5: Exit\n";
cin>>s;

switch(s)  // accordingly switches to cases which are entered by user
{

case 1: m=a+x;  
	n=b+y;  //calculation for addition

cout<<"Addition is: ";  // does addition
cout<<m<<"+i"<<n<<"\n";
break;

case 2: m=a-x;  // calculation of subtraction.
	n=b-y;
	
cout<<"Subtraction is: "; // it does subtraction and shows output
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
	n=(b*x)+(a*y);  // calculation for multiplication.

cout<<"Multiplication is: ";  // multiplication done and showing value of multiplication
	if(n>=0)
		{
		cout<<m<<"+i"<<n<<"\n\n";
		}
	else
		{
		cout<<m<<"+"<<n<<"i\n\n";
		}
break;

case 4: m=((a*x)+(b*y))/((x*x)+(y*y)); // operating the calculation of division
	n=((b*x)-(a*y))/((x*x)+(y*y));

cout<<"Division is: ";	// showing the division value as output
	if(n>=0)
		{
		cout<<m<<"+i"<<n<<"\n\n";
		}
	else
		{
		cout<<m<<"+"<<n<<"i\n\n";
		}
break; // break should be given to end the running case there.

case 5: exit(1);  // command to exit nthe program
break;

default: cout<<"Invalid input.\n\n";  // if input entered is invalid i.e. other than the stated cases (from 1 to 5) then gives out invalid output 


}  // switch ends here.

}  // while loop ends here.

}   //  main program ends here.
