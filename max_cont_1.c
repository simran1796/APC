#include<stdio.h>
int main()
{
int n;
scanf("%d",&n);
int a[n];
for(int i=0;i<n;i++)
scanf("%d",&a[i]);
int c=0,c1=0,count=0;
scanf("%d",&c);
c1=c;
int l=0,r=0;
for(int i=0;i<n;i++)
{
if(a[i]==1)
{
r++;
}
else if(a[i]==0&&c>0)
{
r++;
c--;
}
else
{
l++;
r=l;
c=c1;
}
if((r-l)>count)
count=r-l;
}
printf("%d",count);
}
