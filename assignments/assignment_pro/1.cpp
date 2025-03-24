#include<simplecpp>
main_program

{
int i,s;
float a[10], t;

cout<<"Enter 10 numbers which you have to compare:";


for(i=0;i<5;i++)
{
	cin>>a[i];
}

for(i=0;i<4;i++)
	{

	if(a[i]>a[i+1])
		{
		t=a[i];
		a[i+1]=a[i];
		a[i+1]=t;
		}
	else if(a[i+1]>a[i])
		{
		s=a[i];
		a[i+1]=a[i];
		a[i+1]=s;
		}
	}
cout<<"greatest is"<<t;
cout<<"\nsmallest is"<<s;

}
