/*Given an array of integers, can you find the sum of its elements?

Input Format

The first line contains an integer, , denoting the size of the array.
The second line contains space-separated integers representing the array's elements.

Output Format

Print the sum of the array's elements as a single integer. */

#include<stdio.h>

void main()
{

int n,i,sum=0;
scanf("%d",&n);
int a[n];
for(i=0;i<n;i++)
{
scanf("%d[^ ]",&a[i]);
sum=sum+a[i];
}
printf("%d",sum);
}
