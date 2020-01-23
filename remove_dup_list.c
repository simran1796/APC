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
    if (*h == NULL)  
    {  
      (*h)=nn;
    }   
     else
   {
    curr=(*h);
    while(curr->n!=NULL)
    {
    curr=curr->n;
    }
   curr->n=nn;
   }
} 
void rem(struct node** h)
{
struct node* ptr;
ptr=(*h);
while(ptr&&ptr->n)
{
if(ptr->d==ptr->n->d)
{
struct node* t=ptr->n;
ptr->n=ptr->n->n;
free(t);
t=NULL;
}
else
ptr=ptr->n;
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
int main()
{
struct node* h=NULL;
for(int i=0;i<5;i++)
{
 int a;
 scanf("%d",&a);
 ins_end(&h,a);
}
rem(&h);
print(h);
return 0;
}
