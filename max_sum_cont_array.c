#include<stdio.h>
int main()
{
int n,j=0,max=0;
scanf("%d",&n);
int a[n];
for(int i=0;i<n;i++)
scanf("%d",&a[i]);
for(int i=0;i<n-1;i++)
{
if(a[i]+a[i+1]>a[i+1])
{
a[i+1]+=a[i];
if(max<a[i+1])
max=a[i+1];
}
}
printf("%d",max);
}
