#include<stdio.h>

struct distance
{
float feet;
float inch;
};

void main()
{
struct distance b;
float sum1,sum2,n,m;

printf("\nEnter value of a number in feet:  ");
scanf("%f",&b.feet);
printf("Enter value in inch:  ");
scanf("%f",&b.inch);

n=12*b.feet;
sum1=n+b.inch;
m=b.inch/12;
sum2=m+b.feet;

printf("\nSum of given values in inch is  %f\n",sum1);
printf("\nSum of given values in feet is  %f\n\n",sum2);

}
