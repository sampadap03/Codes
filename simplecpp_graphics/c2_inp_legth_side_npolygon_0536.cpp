//Purpose: program of nsided polygon with input sie and length
//Date:6:49 PM 8/22/2017


#include<simplecpp>
main_program
{
int side;
int length;
cout<<"Enter number of sides:";
cin>>side;
cout<<"Enter length of sides:";
cin>>length;

turtleSim();
repeat(side)
	{
	forward(length);
	right(360/side);
	}
wait(10);
}