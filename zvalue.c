#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
char str[10];
char pat[10];
scanf("%s",str);
scanf("%s",pat);
int len=strlen(pat);
strcat(pat,"$");
strcat(pat,str);
int n=strlen(pat);
int m=strlen(str);
int* z=(int*)malloc(sizeof(int)*n);
int l=0,r=0,i=0,flag=0;
z[0]=0;
for(i=1;i<n;i++)
 {
  if(i>=r)
   {
  l=i;
  r=i;
  while(pat[r]==pat[r-l])
   r++;
  z[i]=r-l;
   }
  else
  {
    if(i+z[i-l]<r)
     {
       z[i]=z[i-l];
     }
     else
    {
     l=i;
     while(pat[r]==pat[r-l])
     r++;
     z[i]=r-l;
    }
  }
 if(z[i]==len)
 {
  flag=1;
  printf("Pattern found:%d\n",i-len-1);
 }
}
if(flag==0)
printf("Pattern not found");
}
