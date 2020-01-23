#include<stdio.h>
#include<stdlib.h>
struct node
{
int d;
struct node* n;
};
void ins_end(struct node** h, int dt) 
{
 struct node* nn=(struct node*) malloc(sizeof(struct node)); 
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
struct node* rev_k(struct node* h,int k)
{
    struct node* curr = h; 
    struct node* next = NULL; 
    struct node* prev = NULL; 
    int c=0;    
    while (curr&&c< k) 
    { 
      next=curr->n;
      curr->n=prev;
      prev=curr;
      curr=next;  
      c++; 
    } 
    if(next) 
    h->n= rev_k(next, k);  
    return prev; 
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
h=rev_k(h,2);
print(h);
return 0;
}
