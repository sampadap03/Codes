//Purpose: program of Dottet square
//Date: 17/08/2017

#include<simplecpp>
main_program
{
turtleSim();
repeat(4)
	{
	repeat(3)
		{
		forward(30);
		penUp();
		forward(30);
		penDown();
		}
	right(90);
	}
wait(10);
}
