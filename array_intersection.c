#include<stdio.h>
int main()
{
int b[3];
int a[9];
int res[9];
for(int i=0;i<9;i++)
scanf("%d",&a[i]);
for(int i=0;i<3;i++)
scanf("%d",&b[i]);
int k=0;
int p=0,q=0;
while(p<9&&q<3)
{
if(a[p]<b[q])
p++;
else if(a[p]>b[q])
q++;
else
{
res[k]=a[p];
k++;
p++;
q++;
}
}
for(int i=0;i<k;i++)
printf("%d",res[i]);
}
