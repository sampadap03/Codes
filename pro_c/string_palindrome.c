/*palindrome of string using pointer*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int palindrome(int n,char *p);

void main()
{

char str1[30];
int value;
printf("Enter the string:  ");
gets(str1);

value=palindrome(strlen(str1),str1);

if(value==0)
	printf("\nEntered string is palindrome.\n\n");

else if(value==1)
	printf("\nEntered string is not palindrome.\n\n");


}

int palindrome(int n,char *p)
{

int count=0, i;
for(i=0;i<n/2;i++)
{

if(*(p+i)==*(p+(n-i-1)) )
	count++;
}

if(count==(n/2))
	return 0;
else
	return 1;

}
