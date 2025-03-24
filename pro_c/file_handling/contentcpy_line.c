/*program to copy content of one file to another line by line*/

#include<stdiio.h>

int main()
{
FILE *fp1,*fp2,*fp3;
fp1=fopen("test.txt","a");
fputs("\n this is the new line");
fclose(fp1);

fp2=fopen("abc.txt","w");
fp3=fopen("test.txt","r");
char c;

while(c)
{
c=getc(fp1);

}



return 0;
} 
