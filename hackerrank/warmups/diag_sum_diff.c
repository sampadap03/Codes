/*
program to get difference berween sum of elements of diagonals of array
00 01 02 03 04 05
10 11 12 13 14 15
20 21 22 23 24 25
30 31 32 33 34 35
40 41 42 43 44 45
50 51 52 53 54 55

1 2 3 
4 5 6
7 8 9
date: 17/12/2017
*/

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);
    int i,j;
    int sl=0,sr=0;
    int a[100][100];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            if(i==j) sl+=a[i][j];
		if(j==n-i-1)  sr+=a[i][j];
        }
    }
     /*for(i=0;i<n;i++)
     {
         sr+=a[i][n-i];
     }*/
            printf("%d %d ",sl,sr);
    printf("%d",abs(sl-sr));
    return 0;
    
}
