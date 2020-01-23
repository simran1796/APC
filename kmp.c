#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
char str[10];
char pat[10];
scanf("%s",str);
scanf("%s",pat);
int n=strlen(pat);
int m=strlen(str);
int* lps=(int*)malloc(sizeof(int)*n);
int i=0,j=1,flag=0;
lps[0]=0;
while(j<n)
{
if(pat[i]==pat[j])
 {
  lps[j]=i+1;
  i++;
  j++;
 }
else
 {
  if(i==0)
  {
   lps[j]=0; j++;
  }
  else
  i=lps[i-1];
 }
}
i=0,j=0;
while(i<m)
{
 if(str[i]==pat[j])
 {
  i++; j++;
 }
 else
 {
  if(j==0)
  i++;
  else
  j=lps[j-1];
 }
 if(j==n)
 {
  printf("Pattern found: %d\n",i-j);
  flag=1;
 }
}
if(flag==0)
printf("Pattern not found");




}
