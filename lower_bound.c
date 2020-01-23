#include<stdio.h>
#include<stdlib.h>
int lower(int *a,int n,int i)
{
int l=0,h=n-1;
int an=-1;
while(l<=h)
{
 int m=(l+h)/2;
 if(a[m]==i)
 {
  an=m;
  h=m-1;
 }
 else if(a[m]<i)
 l=m+1;
 else if(a[m]>i)
 h=m-1;
}
return an;
}
int main()
{
int n,ii,p;
scanf("%d",&n);
int *a=(int*) malloc(n*sizeof(int));
for(int i=0;i<n;i++)
scanf("%d",&a[i]);
scanf("%d",&ii);
printf("%d",lower(a,n,ii));
return 0;
}
