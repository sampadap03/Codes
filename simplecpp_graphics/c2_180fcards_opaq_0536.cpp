//Purpose: Program of opaque fanned out cards in 180
//Date: 1:08 PM 8/27/2017

#include<simplecpp>
main_program
{

turtleSim();

repeat(52)
	{
	forward(40);
	left(90);
	forward(2.41952);
	left(93.461952);
	penUp();
	forward(40.073);
	penDown();
	right(180);
	}

wait(8);

}