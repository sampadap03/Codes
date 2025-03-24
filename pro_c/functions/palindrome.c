/*Palindrome using pointer*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int palindrome(char *a);

int main()
{
char a[20];
int i;
printf("enter the string:  ");
scanf("%[^\n]s",a);

int s;

s=palindrome(a);
if(s==0)
	printf("String is not palindrome.");
else if(s==1)
	printf("String is the palindrome.");
return 0;
}

int palindrome(char *a)
{
int l,count=0, i;
l=strlen(a);
for(i=0;i<l/2;i++)
{
if(a[i]==a[l-i-1])
	count++;

}
if(count==l/2)
	return 1;
else 
	return 0;
}

