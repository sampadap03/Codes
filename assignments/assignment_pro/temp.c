#include<stdio.h>



float farenheit(float a);

float celsius(float b);


float main()


{


int n;

float t,f,s;


//float farenheit(float a);

//float celsius(float b);



printf("This is the program for conversion of celsius to fahrenheit\n\n");



printf("Enter the temperature:\t\t");


scanf("%f",&t);



printf("Enter what is to convert\n");


printf("1: Celsius to farenheit\n");


printf("2: Farenheit to celsius\n\n");


scanf("%d\n",&n);



switch (n)

{



case 1: 

{

printf("in loop 1");

	s=farenheit(t);

	printf("Converted temperature is %f",s);

	break;

}


case 2:
 
{

s=celsius(t);

	printf("Converted temperature is %f",s);

	break;

}


default: printf("Wrong input");

}


	
printf("ss");



}



float farenheit(float t)


{


float f=0.0;

f=t*4.5+32;

printf("Converted temperature is %f",f);


return f;

}




float celsius(float t)

{


float f=0.0;

f=(t-32)*(5/9);

printf("Converted temperature is %f",f);


return f;

}












