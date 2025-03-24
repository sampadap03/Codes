#include<stdio.h>
main()
{

int x, i;
char ch;

printf("Enter the character:\t");
scanf("%c",&ch);


x=(int)ch;

//printf("x= %d\n",x);

if(((ch<'A')||(x>'Z'))&&((x<'a')||('z'<x)))
printf("Entered character is not the alphabet.");

else
printf("Entered character is the alphabet.");

printf("\nProgram ends here.");
}
