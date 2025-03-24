/*to count spaces,tabs,new lines and characters*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
int cs=0,ct=0,cn=0,cc=0;

FILE *fp1;
char c;

fp1=fopen("test.txt","r");

while(1)
{
c=fgetc(fp1);

if(c==EOF)
	break;

cc++;

if(c==' ')
	cs++;

if(c=='\t')
	ct++;

if(c=='\n')
	cn++;

}
printf("total characters are:  %d\n Total spaces are: %d \n Total tabs are:  %d \n Total new lines are: %d \n",cc,cs,ct,cn);

return 0;
}
