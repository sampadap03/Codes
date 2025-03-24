//Purpose: Program of withdrawing money from ATM
//Date: 2:39 PM 8/26/2017

#include<simplecpp>
main_program
{
int pin=1123,bal=1000000, amt;
cout<<"\n please insert your ATM card:";


cout<<"\n Please type in your Pin number:";
cin>>pin;

 if(pin==1123)
   {
    cout<<"\n Enter the amount to be withdrawn:";
    cin>>amt;
cout<<"\n";
	
	if(amt%100==0)
		
		{
		  if(amt<=1000000)
			{
			  bal=bal-amt;
			  cout<<"\n Amount is successfully withdrawn.\n";
			  cout<<"\n Balance left is:"<<bal<<"\n";
			}
		  else 
			{
			cout<<"Please enter valid amount less than your balance "<<bal;
			}
		}

	else
	   {
	     cout<<"Please enter the 100 multiple of amount to be withdrawn\n";
	   } 
    }

else
   {
     cout<<"Enter valid pin";
     cin>>pin;
   }

}
