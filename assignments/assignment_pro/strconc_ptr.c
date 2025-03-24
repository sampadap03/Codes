/*contatenate two strings using pointer*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void conc(char *p, char *q);

void main()
{
char str1[30], str2[30];

printf("Enter first string:\t");
gets(str1);

printf("Enter second string:\t");
gets(str2);

conc(str1,str2);

printf("\nString after concatenation is :   %s \n\n",str1);

}

void conc(char *p, char *q)
{

while(*p!=0)
{
	p++;

	}

while(*q)
{	*p++=*q++;

	}

*p='\0';

}
