#include<stdio.h>
#include<math.h>

struct point
{
float x;
float y;

};

void main()
{
float dist;
struct point p1,p2;

printf("Enter x and y coordinate of first point:  ");
scanf("%f%f",&p1.x,&p1.y);
printf("Enter x and y coordinate of second point:  ");
scanf("%f%f",&p2.x,&p2.y);

dist=sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
printf("Distance between two points is  %f",dist);
}
