/*Program to print all characters of file test.txt*/

#include<stdio.h>
void main()
{
char c;
int i;
FILE *fp1;

fp1=fopen("test.txt","w");
fputs("Good night you all and\n have nice day!!",fp1);
fclose(fp1);
FILE *fp2;
fp2=fopen("test.txt","r");

//for(i=0;i<15;i++)
while(1)	
{
	
	c=fgetc(fp1);//it's printin' one more extra character than the string 
	if(c==EOF)
	{
	 break;}
	
	printf("%c",c);
	c++;

}

fclose(fp2);
}
