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
    while(curr->n)
    {
    curr=curr->n;
    }
   curr->n=nn;
   }
} 
void del(struct node** h,int pos)
{
struct node* temp;
struct node* curr;
temp=(*h);
int i=0;
if(pos==1)
{
*h=(*h)->n;
free(temp);
temp=NULL;
}
else
{
while(temp->n->n&&i<(pos-1))
{
temp=temp->n;
i++;
}
if(temp==NULL)
printf("Invalid");
else
{
curr=temp->n;
temp->n=temp->n->n;
free(curr);
curr=NULL;
}
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
int p;
scanf("%d",&p);
del(&h,p);
print(h);
return 0;
}
