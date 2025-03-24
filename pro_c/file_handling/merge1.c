#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
FILE *fp1,*fp2,*fp3,*fp4;
char ch;
fp1=fopen("abc.txt","r");
fp2=fopen("merge.txt","w");
while(1)
{
ch=fgetc(fp1);
if(ch==EOF)
	break;
fputc(ch,fp2);
}
fputs("\n",fp2);
fclose(fp1);
fp3=fopen("def.txt","r");
while(1)
{
ch=fgetc(fp3);
if(ch==EOF)
	break;

fputc(ch,fp2);
}
return 0;
}
