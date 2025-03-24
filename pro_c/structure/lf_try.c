#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void linkfloat();
int main()
{
struct book
{
char name[10];
float price;
int pages;
};

struct book b[100];
int i;

for(i=0;i<5;i++)
{
fflush(stdin);
printf("Enter name of %d th element:",i+1);
gets(b[i].name);
fflush(stdin);

printf("\nEnter price of %d th element:",i+1);
scanf("%f",&b[i].price);
fflush(stdin);

printf("\nEnter pages if %d th element: ",i+1);
scanf("%d",&b[i].pages);
fflush(stdin);

}

for(i=0;i<5;i++)
{
puts(b[i].name);
printf("%f %d\n",b[i].price,b[i].pages);
}
return 0;
}

void linkfloat()
{
float a=0,*b;
b=&a;
a=*b;

}
