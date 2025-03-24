#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
FILE *fp1,*fp2,*fp3;
char ch[30];

fp1=fopen("poem.txt","w");

if(fp1==NULL){
	puts("cannot open the file.");
	exit(1);}

while(strlen (gets(ch))>0)
{
fputs(ch,fp1);
fputs("\n",fp1);
}

fclose(fp1);

return 0;
}
