//purpose: program of nsided polygon
//date: 11/08/2017

#include<simplecpp>
main_program
{
int nsides;
cout<<"Type the no of sides of polygon:";
cin>> nsides;

turtleSim();
 repeat(nsides)
{
forward(100);
right(360/nsides);
}
wait(5);
}
