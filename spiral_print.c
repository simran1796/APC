#include<stdio.h>
int main()
{
int s;
scanf("%d",&s);
int k=0,m=s,n=s,l=0;
int ar[10][10];
for(int i=0;i<s;i++)
{
for(int j=0;j<s;j++)
scanf("%d",&ar[i][j]);
}
while(k<m&&l<n)
{
for(int i=l;i<n;i++)
printf("%d ",ar[k][i]);
k++;
for(int i=k;i<m;i++)
printf("%d ",ar[i][n-1]);
n--;
if(k<m)
{
for(int i=n-1;i>=l;i--)
printf("%d ",ar[m-1][i]);
m--;
}
if(l<n)
{
for(int i=m-1;i>=k;i--)
printf("%d ",ar[i][l]);
l++;
}
}
}
