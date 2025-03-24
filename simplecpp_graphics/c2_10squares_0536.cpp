//Purpose: program of constructing 10 squares besides each other
//Date:9:12 AM 8/13/2017

#include<simplecpp>
main_program
{
int length;
cout<<"Type in the length of side of square:";
cin>>length;
turtleSim();
 repeat(3)
	{
	forward(length);
	left(90);
	}
forward(length);
right(90);
repeat(9)
	{
	repeat(3)
		{
		forward(length);
		right(90);
		}
	penUp();
	forward(length);
	right(90);
	forward(length);
	penDown();
	}
wait(20);
}
