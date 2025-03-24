#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct book
{
char title[20];
char publisher[20];
float price;
char author[20];

};

void display(struct book b[5]);

void main()
{
struct book b[5];

int i;

for(i=0;i<5;i++)
{
printf("Enter title of %d book:  ",i+1);
scanf("%s[^\n]",b[i].title);
fflush(stdin);
printf("Enter publisher name of %d book:  ",i+1);
scanf("%s[^\n]",b[i].publisher);
fflush(stdin);
printf("Enter price of %d book:  ",i+1);
scanf("%f",&b[i].price);
fflush(stdin);
printf("Enter the name of author of %d book:  ",i+1);
fflush(stdin);
scanf("%s[^\n]",b[i].author);
//gets(b[i].author);
fflush(stdin);
printf("\n");
}
display(b);
}
void display(struct book b[5])
{

int i;

for(i=0;i<5;i++)
{
	printf("\nName of %d book is:  %s\n",i+1,b[i].title);

	printf("Name of publisher of %d book is:  %s\n",i+1,b[i].publisher);

	printf("Price of the %d book is  %f\n",i+1,(b[i]).price);
	printf("Name of author of %d book is   %s\n\n",i+1,b[i].author);


}

printf("\n");


}

