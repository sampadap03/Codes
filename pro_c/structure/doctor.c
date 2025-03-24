#include<stdio.h>

struct doctor
{
char name[20];
char specialization[20];
int years;

}d[5];

void main()
{
int i;
struct doctor d[5];
for(i=0;i<5;i++)
{
printf("Enter name: ");
scanf("%s",d[i].name);
printf("Enter specialization:  ");
scanf("%s",d[i].specialization);
printf("Enter year of experiance:");
scanf("%d",&d[i].years);
}

for(i=0;i<5;i++)
{
printf("%s",d[i].name);
printf("%s",d[i].specialization);
printf("%d\n",d[i].years);
}
}
