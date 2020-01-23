#include<stdio.h>
#include<stdlib.h>
struct node
{
int d;
struct node* n;
};
void ins_end(struct node** h, int dt) 
{
 struct node* nn =(struct node*) malloc(sizeof(struct node)); 
 struct node* curr =(struct node*) malloc(sizeof(struct node)); 
 nn->d=dt;
 nn->n=NULL;
    if (*h == NULL)  
    {  
      *h=nn;
    }   
     else
   {
    curr=*h;
    while(curr->n!=NULL)
    {
    curr=curr->n;
    }
   curr->n=nn;
   }
} 
void rev(struct node** h)
{
struct node* pre;
struct node* nn;
struct node* curr;
pre=NULL;
curr=(*h);
nn=curr->n;
while(curr)
{
curr->n=pre;
pre=curr;
curr=nn;
if(curr)
nn=curr->n;
}
*h=pre;
}
void print(struct node* a)
{
 while(a)
 {
  printf("%d\n",a->d);
  a=a->n;
 }
}
int main()
{
struct node* h=NULL;
for(int i=0;i<5;i++)
{
 int a;
 scanf("%d",&a);
 ins_end(&h,a);
}
rev(&h);
print(h);
return 0;
}
