#include<stdio.h>

struct date
{
int day;
int month;
int year;
};

struct student
{
int rollno;
int marks;
char name[20];
struct date d;

};


void main()
{
struct student s;
struct date d;

printf("Enter roll no:");
scanf("%d",&s.rollno);
printf("enter marks:");
scanf("%d",&s.marks);
printf("Enter your name:");
scanf("%s",s.name);
printf("Enter birth date in the order: Day/Month/Year");
scanf("%d%d%d",&s.d.day,&s.d.month,&s.d.year);

printf("\n\nYou are: %s\nYour roll number is: %d\n Your marks are: %d\n,Your birth date is: %d/%d/%d\n\n",s.name,s.rollno,s.marks,s.d.day,s.d.month,s.d.year);

}
