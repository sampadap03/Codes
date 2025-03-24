/*Game of CRAPS*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define SEED 12345

void play(void);
int throw(void);

void main()
{

char answer='Y';

printf("Welcome to Game of CRAPS\n\n");
printf("To throw the dice press enter\n\n");

srand(SEED);

while(toupper(answer)!='N')
{

play();
printf("do you want to play again (Y/N)  ");
scanf("%c",&answer);
printf("\n");
}

printf("Thanks for playing. Game ends here\n");

}

void play(void)
{

int score1,score2;
char dummy;

printf("Please throw the dice...\n");
scanf("%c",&dummy);
printf("\n");
score1=throw();
printf("\n%2d",score1);

switch(score1)
{
break;

case 2:
case 3:
case 12:
printf("Sorry, You LOSE on thr first throw\n");
break;

case 4:
case 5:
case 6:
case 8:
case 9:
case 10:

do
{

printf("\tThrow the dice again...");
scanf("%c",&dummy);
score2=throw();
printf("\n%2d",score2);

}while(score2!=score1&&score2!=7);

if(score2==score1)
printf("\t- You WIN by mathching your first score\n");
else
printf("\t- You LOSE by failing to match first score\n");
break;
}

return;
}

int throw(void)
{

float x1,x2;
int n1,n2;

x1=rand()/1804289408.000000;
x2=rand()/1804289408.000000;

n1=1+(int)(6*x1);
n2=1+(int)(6*x2);

return(n1+n2);




}
