#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
char a[20],b[20];
gets(a);
int n;
n=atoi(a);
int m;
m=atoi(&a[3]);
int p;
p=atoi(&a[6]);
    if(01<=n<12&&0<=m<=59&&0<=p<=59)
    {
if(n<10&&m>=10&&p>=10)
{
if(a[8]=='A') printf("0%d:%d:%d",n,m,p);
else printf("%d:%d:%d",n+12,m,p);
}
if(m<10&&n>=10&&p>=10)
{
if(a[8]=='A') printf("%d:0%d:%d",n,m,p);
else printf("%d:0%d:%d",n+12,m,p);
}
if(p<10&&m>=10&&n>=10)
{
if(a[8]=='A') printf("%d:%d:0%d",n,m,p);
else printf("%d:%d:0%d",n+12,m,p);
}
if(n<10&&m<10&&p>=10)
{
if(a[8]=='A') printf("0%d:0%d:%d",n,m,p);
else printf("%d:0%d:%d",n+12,m,p);
}
if(m<10&&p<10&&n>=10)
{
if(a[8]=='A') printf("%d:0%d:0%d",n,m,p);
else printf("%d:0%d:0%d",n+12,m,p);
}
if(n<10&&p<10&&m>=10)
{
if(a[8]=='A') printf("0%d:%d:0%d",n,m,p);
else printf("%d:%d:0%d",n+12,m,p);
}
if(n<10&&m<10&&p<10)
{
if(a[8]=='A') printf("0%d:0%d:0%d",n,m,p);
else printf("%d:0%d:0%d",n+12,m,p);
}
if(m>=10&&n>=10&&p>=10)
{
if(a[8]=='A') printf("%d:%d:%d",n,m,p);
else printf("%d:%d:%d",n+12,m,p);
}}
    if(12<n<=23&&0<=m<=59&&0<=p<=59) 
    {
        if(m<10&&n>=10&&p>=10) printf("%d:0%d:%d",n,m,p);
        if(p<10&&m>=10&&n>=10) printf("%d:%d:0%d",n,m,p);
        if(m<10&&p<10&&n>=10) printf("%d:0%d:0%d",n,m,p);
        if(m>=10&&n>=10&&p>=10) printf("%d:%d:%d",n,m,p);
    }
    if(n==12&&0<=m<=59&&0<=p<=59)
    {
        if(a[8]=='P')
        {
            if(m<10&&p<10) printf("00:0%d:0%d",m,p);
            if(m<10&&p>=10) printf("00:0%d:%d",m,p);
            if(m>=10&&n<10) printf("00:%d:0%d",m,p);
            if(m>=10&&n>=10) printf("00:%d:%d",m,p);
        }
        if(a[8]=='A')
        {
            if(m<10&&p<10) printf("%d:0%d:0%d",n,m,p);
            if(m<10&&p>=10) printf("%d:0%d:%d",n,m,p);
            if(m>=10&&n<10) printf("%d:%d:0%d",n,m,p);
            if(m>=10&&n>=10) printf("%d:%d:%d",n,m,p);
        
        }
    }
return 0;
}
