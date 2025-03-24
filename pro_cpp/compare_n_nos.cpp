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

/*for(i=0;i<4;i++)
	{

	if(a[i]>a[i+1])
		{
		t=a[i];
		a[i+1]=a[i];
		a[i+1]=t;
		}

	}

for(i=0;i<4;i++)
{
cout<<a[i]<<"\n";
}

for(i=0;i<4;i++)
cout<<a[i]<<"\t";
*/
s=a[0];
for(i=0;i<=4;i++)
	{	
	cout<<"comparing "<<s<<"and"<<a[i]<<"\n";	
	if(s>a[i])
		{
		
		s=a[i];
		cout<<"value of s"<<s;
		}
	}

cout<<"greatest is"<<"\t";
cout<<"\nsmallest is"<<s;

}
