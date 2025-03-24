#include<stdio.h>
#include<stdlib.h>

void xstrcat(char *t, char *s);

main()
{

char str1[30], str2[30];

printf("Enter first string:  ");
gets(str1);


printf("Enter second string:  ");
gets(str2);

xstrcat(str1, str2);

printf("String after caternation is: %s", str1);
printf("\n\n");

}

void xstrcat(char *t, char *s)
{

while(*t)
t++;

while(*s)
*t++=*s++;

*t='\0';

}
