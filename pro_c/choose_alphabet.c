#include<stdio.h>
main()
{

int x, i;
char ch;

printf("Enter the character:\t");
scanf("%c",&ch);

x=ch;

if(65<=x<=90)
{

	for(i=65;i<=90;i++)
	{
	
		if(x==i)
		{
		printf("\n\n It is a alphabet and You have entered %c alphabet.\n\n",i);
		break;
		}
	}
}

if(97<=x<=122)
{

	for(i=97;i<=122;i++)
	{
	
		if(x==i)
		{
		printf("\n\n it is a alphabet and You have entered %c alphabet.\n\n",i);
		break;
		}
	
		
	}

	
}


else
			{
			printf("\n\n Entered character is not the alphabet.\n\n");
			}


}
