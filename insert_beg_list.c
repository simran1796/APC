#include<stdio.h>
#include<stdlib.h>
struct node
{
int d;
struct node* n;
};
void ins_beg(struct node **h,int dt)
{
struct node* nn=(struct node*)malloc(sizeof(struct node));
nn->d=dt;
if((*h)==NULL)
(*h)=nn;
nn->n=*h;
*h=nn;
}
void print(struct node* a)
{
 while(a->n)
 {
  printf("%d\n",a->d);
  a=a->n;
 }
}
int main()
{
struct node* h=NULL;
h=(struct node*)malloc(sizeof(struct node));
for(int i=0;i<5;i++)
{
 int a;
 scanf("%d",&a);
 ins_beg(&h,a);
}
print(h);
return 0;
}
