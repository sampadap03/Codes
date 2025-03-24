//Purpose: Program of forming triangle with input sides
//Date: 12:33 PM 8/27/2017

#include<simplecpp>
main_program
{

float a, b, c;

cout<<"Enter length of three sides of triangle:";
cin>>a>>b>>c;

turtleSim();

forward(c);
left(180-arccosine((a^2+c^2-b^2)/2ac))

forward(a);
left(180-arccosine((a^2-c^2+b^2)/2ab))

forward(b);

wait(8)
}
