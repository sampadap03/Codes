#include<stdio.h>

int main()
{
struct book
{
char name[20];
float price;
int pages;
};

struct book b[100];
int i;

for(i=0;i<5;i++)
{

printf("Enter name price and pages");

scanf("%s%f%d",b[i].name,&b[i].price,&b[i].pages);
}

for(i=0;i<5;i++)
printf("%s%f%d\n",b[i].name,b[i].price,b[i].pages);

return 0;
}

void linkfloat()
{
float a=0,*b;
b=&a;
a=*b;

}
