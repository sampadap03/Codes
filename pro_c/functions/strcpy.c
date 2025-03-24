/*copy content of one string to another*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void xstrcpy(char *ptr1,char *ptr2);
 
int main()
{
char str1[10],str2[10];
printf("Enter a string: ");
gets(str1);

printf("String you entered is :");
puts(str1);

xstrcpy(str1,str2);

printf("\nString 2 after copying from string 1 is: ");
puts(str2);

return 0;
}

void xstrcpy(char *ptr1,char *ptr2)
{

while(*ptr1!='\0')
{
*ptr2++=*ptr1++;

}
*ptr2='\0';
//printf("\nString 2 after copying from string 1 is: ");
//puts(str2);
}
