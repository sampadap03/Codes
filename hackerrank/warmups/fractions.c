#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int i,a[n],cn=0,cp=0,cz=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
	
    }
for(i=0;i<n;i++)
{

if(a[i]==0) cz++;        
	if(a[i]<0) cn++;
       
        if (a[i]>0)cp++;
}    
printf("%f\n%f\n%f",(float)cp/n,(float)cn/n,(float)cz/n);
    return 0;
}
