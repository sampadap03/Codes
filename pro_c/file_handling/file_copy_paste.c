#include<stdio.h>
#include<stdlib.h>

void main()
{

FILE *fp1,*fp2,*fp3;

char c;
int str1[10];

fp1=fopen("abc.txt","w");

fputs("Hello!! This is home assignment 6",fp1);
fputs("\nIt is the program to copy paste file content from file abc.txt to cde.txt!!",fp1);
fclose(fp1);

fp3=fopen("abc.txt","r");
fp2=fopen("cde.txt","w");

while(1)
{

c=fgetc(fp3);


if(c==EOF)
	break;

fputc(c,fp2);

}

fclose(fp3);
fclose(fp2);




}
