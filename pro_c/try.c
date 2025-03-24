#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define SEED 12345
void main()
{

float x1,x2;
int n1,n2;
srand(SEED);

x1=rand()/1804289408.000000;
x2=rand()/1804289408.000000;

printf("%f %f",x1,x2);

}
