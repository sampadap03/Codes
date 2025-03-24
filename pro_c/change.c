#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void change(char *t);
main()
{char str1[100];
printf("enter word\t");
gets(str1);
change(str1);
printf("\n\n New word is  %s \n",str1);
}
void change(char *s)
{
while(*s!='\0')
{if((*s>='A')&&(*s<='Z'))
*s=*s+32;
else if((*s>='a')&&(*s<='z'))
*s=*s-32;

s++;
}}
