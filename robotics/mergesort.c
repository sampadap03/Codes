#include<stdio.h>

mergesort(int a[],int n)
{
    printf("\n$$$\n");

    int i=0,j=0,k=0;
    int mid=n/2;
    int l[mid+1], r[mid+1];
    printf("%d\n%d\n",n,mid);
    for(j=0;j<(mid-1);j++)
    {
        l[j]=a[j];
    }
    for(i=mid;i<n-1;i++)
    {
        r[k]=a[j];
        j++;
        k++;

    }
    i=0;j=0;k=0;
    int nl=sizeof(l)/4;
    int nr=sizeof(r)/4;

    while(i<nl&&j<nr)
    {
        if(l[i]<r[j])
        {
            a[k]=l[i];
            i++;
            k++;
        }
        else
        {
            a[k]=r[j];
            j++;
            k++;
        }
    }
    while(i<nl)
    {
        a[k]=l[i];
        i++;
        k++;
    }
    while(i<nr)
    {
        a[k]=r[j];
        j++;
        k++;
    }
}

void main()
{
    int n,i;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    mergesort(a,n);
    printf("  \n\n");
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
        printf("\n");
    }
}
