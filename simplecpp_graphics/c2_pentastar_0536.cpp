//purpose: program of five-pointed-star
//Date: 11:43 AM 8/13/2017

#include<simplecpp>
main_program
{
int sidelength;
cout<<"Type length of side of pentagram:";
cin>>sidelength;
turtleSim();
repeat(5)
{
right(36);
forward(sidelength);
right(108);
}
wait(20);
}
