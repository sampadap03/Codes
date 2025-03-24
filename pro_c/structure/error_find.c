#include<stdio.h>
struct virus
{
char signature[25];
char status[20];
int size;
}v[2]={
	"xzc","sad",123,"sdf","cvb",456
	};

int main()
{
int i;
for(i=0;i<=1;i++)
	printf("%s  %s\n",v[i].signature,v[i].status);
return 0;
}
