#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
FILE *fp1,*fp2,*fp3,*fp4;
char ch;


fp1=fopen("abc.txt","w");
fputs("All the best for test!",fp1);

fclose(fp1);

fp2=fopen("def.txt","w");
fputs("its last day",fp2);
fclose(fp2);

fp3=fopen("abc.txt","a");
fp4=fopen("merge.txt","r");
if(fp3==NULL)
{
puts("NO information found");
fclose(fp3);
exit(1);
}

while(1)
{
ch=fgetc(fp4);
	if(ch==EOF)
	break;

else
	fputc(ch,fp3);


}

fclose(fp4);
fclose(fp3);


return 0;
}
