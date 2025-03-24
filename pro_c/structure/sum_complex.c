#include<stdio.h>

struct complex
{
int x;
int y;

};

int main()
{
struct complex p1,p2;
int a,b;
printf("Enter x and y coord of first point :");
scanf("%d%d",&p1.x,&p1.y);
printf("Enter x and y coord of second point :");
scanf("%d%d",&p2.x,&p2.y);

a=p1.x+p2.x;
b=p1.y+p2.y;

printf("answer: X coord is %d and y coord is %d",a,b);
return 0;
}
