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
 nn->d=dt;
 struct node* curr=(*h);
 nn->n=NULL;
    if (*h == NULL)  
    {  
      *h=nn;
     return;
    }   
     else
   {
    while(curr->n)
    {
    curr=curr->n;
    }
   curr->n=nn;
   }
} 
void add(struct node** h,int dt,int pos)
{
struct node* nn=(struct node*)malloc(sizeof(struct node));
struct node* curr=(*h);
nn->d=dt;
int i=0;
if(pos==1)
{
nn->n=(*h);
(*h)=nn;
}
else
{
while(curr&&i<(pos-1))
{
curr=curr->n;
i++;
}
if(curr==NULL)
printf("Invalid");
else
{
nn->n=curr->n;
curr->n=nn;
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
add(&h,0,5);
print(h);
return 0;
}
