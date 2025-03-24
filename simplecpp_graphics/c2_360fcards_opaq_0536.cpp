//Purpose: Program of opaque fanned out cards in 360
//Date: 1:30 PM 8/27/2017

#include<simplecpp>
main_program
{

turtleSim();

repeat(52)
	{
	forward(40);
	left(90);
	forward(4.85688);
	left(96.92307);
	penUp();
	forward(40.29379);
	penDown();
	right(180);
	}

wait(8);

}