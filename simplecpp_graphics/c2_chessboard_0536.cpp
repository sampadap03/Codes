//Purpose: program of chessboard
//Date:9:41 AM 8/13/2017

#include<simplecpp>
main_program
{
turtleSim();
repeat(4)
{
forward(160);
left(90);
}
repeat(4)
	{
	penUp();
	forward(20);
	left(90);
	penDown();
	forward(160);
	right(90);
	penUp();
	forward(20);
	right(90);
	penDown();
	forward(160);
	left(90);
	}
repeat(4)
	{
	penUp();
	left(90);
	forward(20);
	penDown();
	left(90);
	forward(160);
	right(90);
	penUp();
	forward(20);
	right(90);
	penDown();
	forward(160);
	}
wait(10);
}
