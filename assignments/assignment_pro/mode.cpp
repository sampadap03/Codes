#include<simplecpp>
main_program
{
int i,j, n=10, c=1, k=0,max=0, mode, a[20],b[20];
float temp, s;

cout<<"Enter 10 numbers which you have to compare:\n";


for(i=0;i<10;i++)
{
	cin>>a[i];
}

for(j=0;j<10;j++)
{
for(i=0;i<9;i++)
	{

	if(a[i]<a[i+1])
		{
		temp=a[i+1];
		a[i+1]=a[i];
		a[i]=temp;
		}

	}
}

cout<<"Array of given numbers in descending order is:\n";
for(j=0;j<=9;j++)
{
cout<<a[j]<<"\t";
}

cout<<"\n\nGreatest number is: "<<a[0]<<"\n";
cout<<"Smallest number is: "<<a[9]<<"\n";

s=(a[4]+a[5])/2;

cout<<"Median of given numbers is: "<<s<<"\n";


for(i=0;i<9;i++)
{
mode=0;
for(j=i+1;j<10;j++)
	{
	if(a[i]==a[j])
	mode++;	
	}

if((mode>max)&&(mode!=0))
	{
	k=0;
	max=mode;
	b[k]=a[i];
	k++;
	}

else if(mode==max)
	{
	b[k]=a[i];
	k++;
	}
}

for(i=0;i<n;i++)
{
	if(a[i]==b[i])
	c++;
}
if(c==n)
	cout<<"\n There is no mode";
else
	{
	cout<<"\nMode\t= ";
	for(i=0;i<k;i++)
	cout<<b[i];
	}
cout<<"\nProgram ends here.\n\n";



}













