//Purpose: Program of transparent fanned out cards(360)
//Date: 12:27 PM 8/27/2017

#include<simplecpp>
main_program
{

turtleSim();

int n=0;

repeat(52)
	{
	left(n);
	
	repeat(2)
		{		
		forward(40);
		left(90);
		forward(30);
		left(90);
		}

	n=n+6.923;
	}

wait(10);
}
