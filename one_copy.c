#include<stdio.h>
int main()
{
int n,j=0,c=0;
scanf("%d",&n);
int a[n];
for(int i=0;i<n;i++)
scanf("%d",&a[i]);
for(int i=0;i<n;i++)
{
if(i<n-1&&a[i]==a[i+1])
continue;
else
a[j++]=a[i];
}
for(int i=0;i<j;i++)
printf("%d",a[i]);
}
