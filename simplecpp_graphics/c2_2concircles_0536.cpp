//Purpose: Program of two concentric circles
//Date: 17/08/2017

#include<simplecpp>
main_program
{
turtleSim();
repeat(360)
	{
	forward(1);
	right(1);
	}
left(90);
penUp();
forward(59);
penDown();
right(90);
repeat(360)
	{
	forward(2);
	right(1);
	}
wait(10);
}
