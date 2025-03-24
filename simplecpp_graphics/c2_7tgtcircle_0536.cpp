//Purpose: Prorgram of seven tangent circles
//Date: 1:50 PM 8/27/2017

#include<simplecpp>
main_program
{
turtleSim();

repeat(360)
{
forward(0.17453);
right(1);
}

right(90);
penUp();
forward(10);
penDown();
left(180);

repeat(6)
	{
	penUp();
	forward(10);
	penDown();
	right(90);
	
	repeat(360)
		{
		forward(0.17453);
		left(1);
		}
	right(90);
	penUp();
	forward(10);
	left(120);
	}

wait(10);

}
