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
 struct node* curr; 
 nn->d=dt;
 nn->n=NULL;
    if ((*h) == NULL)  
    {  
      (*h)=nn;
    }   
     else
   {
    curr=(*h);
    while(curr->n)
    {
    curr=curr->n;
    }
   curr->n=nn;
   }
} 
void print(struct node* a)
{
 while(a)
 {
  printf("%d\n",a->d);
  a=a->n;
 }
}
void reorder(struct node** h)
{
struct node* sp;
struct node* fp;
struct node* h1;
struct node* h2;
h1=(*h);
fp=(*h)->n;
sp=(*h);
while(fp&&fp->n)
{
sp=sp->n;
fp=fp->n->n;
}
struct node* pre=NULL;
struct node* curr=sp->n;
sp->n=NULL;
struct node* nn;
while(curr)
{
nn=curr->n;
curr->n=pre;
pre=curr;
curr=nn;
}
h2=pre;
(*h)=h1;
curr=h1;
h1=h1->n;
while(h1||h2)
{
if(h2)
{
curr->n=h2;
h2=h2->n;
curr=curr->n;
}
if(h1)
{
curr->n=h1;
h1=h1->n;
curr=curr->n;
}
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
reorder(&h);
print(h);
return 0;
}
