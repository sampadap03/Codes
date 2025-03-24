/*Program to print first two characters of file test.txt*/

#include<stdio.h>
void main()
{
char c;
int i;
FILE *fp1;

fp1=fopen("test.txt","w");
fputs("Good night!!",fp1);
fclose(fp1);
FILE *fp2;
fp2=fopen("test.txt","r");

for(i=1;i<3;i++)
{
	
	c=fgetc(fp1);
	printf("%c",c);
	c++;
}

fclose(fp2);
}
