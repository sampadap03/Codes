#include<simplecpp>
main_program
   {
      int b=0,i=0;
      float a,r,n;
      cout<<"geometric prog: \n";
      cout<<"Enter first term of sequence:";
      cin>>a;
      cout<<"Enter common ratio:";
      cin>>r;
      cout<<"Enter number of terms:";
      cin>>b;
      cout<<a<<"\t";
      n=a*r;
	cout<<n<<",\t";
      for(i=3;i<=b;i=i+1)
         {
            n=n*r;
            cout<<n<<","<<"\t";



        }

cout<<"\n"; 







   }
