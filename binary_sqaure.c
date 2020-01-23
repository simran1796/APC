#include<stdio.h>
#include<stdlib.h>
int square(int n)
{
if(n==0||n==1)
return n;
int l=0,h=n;
int an=-1;
while(l<h)
{
 int m=(l+h)/2;
 if(m*m==n)
 return m;
 else if(m*m<n)
 {
 l=m+1;
 an=m;
 }
 else if(m*m>n)
 h=m-1;
}
return an;
}
int main()
{
int n;
scanf("%d",&n);
printf("%d",square(n));
return 0;
}
