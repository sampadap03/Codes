#include<stdio.h>

int farenheit(float c);
int celsius(float c);
void main()
{


float c;
int n;
printf("\n Enter the temperature:");
scanf("%f",&c);

printf("Enter 1 if you have to convert to celsius else enter 2 to convert to farenheit\n\n");
scanf("%d",&n);

switch (n)
{
case 1:
farenheit(c);
break;

case 2: celsius(c);
break;

default: printf("Wrong output\n\n");
}
}

int farenheit(float c)
{

float f=0.0;
f=c*4.5+32;
printf("Converted temperature is %f\n\n",f);
return 0;
}

int celsius(float c)
{

float f=0.0;
f=(c-32)*(5/9);
printf("Converted temperature is %f\n\n",f);
return 0;
}




