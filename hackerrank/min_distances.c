/*Consider an array of integers n,A=[a0,a1,a2..] . The distance between two indicesi, and j, is denoted by dij=|j-i|.

Given A, find the minimum dij such that ai=aj  and i!=j. In other words, find the minimum distance between any pair of equal elements in the array. If no such value exists, print  -1.

Note: |a|denotes the absolute value of a.

Input Format

The first line contains an integer,n , denoting the size of array A.
The second line contains n space-separated integers describing the respective elements in array A.

Constraints: 1<=n<=1000;  1<=ai<=100000

Output Format

Print a single integer denoting the minimum dij in A; if no such value exists, print -1.*/

#include<stdio.h>
int MAX=1000;
int main(){
int a[MAX],b[MAX],i,j,m,ans,n;
scanf("%d",&n);
int min=1001;
MAX=n;
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
for(i=0;i<MAX;i++)
{
	for(j=i+1;j<MAX;j++)
	{
		if(a[i]==a[j])
		{
		m=j-i;	
		if(m<0)
			m=-m;
		if(min>m) min=m;
		
		}
	}
}
if(min==1001)
	printf("-1");
else{
printf("%d",min);
}
}
