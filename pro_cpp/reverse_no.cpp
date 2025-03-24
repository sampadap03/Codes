#include<simplecpp>
main_program
{

int n,m;

cout<<"This is the program to reverse the digits of number\n";

cout<<"Enter the number:\t";
cin>>n;


cout<<"\n\n\nThe number after reversing the digits will be:\t";

while(1)

{

m=n%10;
cout<<m;
n=n/10;
if(n==0)
break;	
}

cout<<"\n\nProgram ends here.\n\n";
}
