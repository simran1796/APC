#include<stdio.h>
#include<stdlib.h>
int upper(int *a,int n,int i)
{
int l=0,h=n-1;
while(l<h)
{
 printf("%d\n",l);
 int m=(l+h)/2;
 printf("%d\n",h);
 printf("%d\n",m);
 if(a[m]>i)
 h=m;
 else
 l=m+1;
}
return h;
}
int main()
{
int n,ii,p;
scanf("%d",&n);
int *a=(int*) malloc(n*sizeof(int));
for(int i=0;i<n;i++)
scanf("%d",&a[i]);
scanf("%d",&ii);
printf("%d",upper(a,n,ii));
return 0;
}
