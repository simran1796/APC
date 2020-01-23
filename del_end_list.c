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
void  del_end(struct node** h)
{
struct node* temp;
struct node* curr;
temp=(*h);
while(temp->n->n)
temp=temp->n;
curr=temp->n;
free(curr);
temp->n=NULL;
curr=NULL;
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
del_end(&h);
print(h);
return 0;
}
