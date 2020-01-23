#include<stdio.h>
int main()
{
int n,sum;
scanf("%d",&n);
scanf("%d",&sum);
int a[n];
for(int i=0;i<n;i++)
scanf("%d",&a[i]);
for(int i=0;i<n-2;i++)
{
int l=i+1;
int r=n-1;
while(l<r)
{
if(a[i]+a[l]+a[r]==sum)
{
printf("FOUND");
return 0;
}
else if(a[i]+a[l]+a[r]<sum)
l++;
else
r--;
}

}
}
