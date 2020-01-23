#include<stdio.h>
#include<stdlib.h>
struct node
{
int d;
struct node* n;
struct node* p;
};
struct node* front=NULL;
struct node* rear=NULL;
/*void insert_at_beg(int dt)
{
struct node* nn=(struct node*)malloc(sizeof(struct node));
nn->d=dt;
if(front==NULL)
{
nn->n==NULL;
nn->p=NULL;
front=nn;
rear=front;
}
else
{
nn->n=front;
front->p=nn;
front=nn;
nn->p=NULL;
}
}*/

void insert_at_last(int dt)
{
struct node* nn=(struct node*)malloc(sizeof(struct node));
nn->d=dt;
if(front==NULL)
{
nn->n=NULL;
nn->p=NULL;
front=nn;
rear=front;
}
else
{
rear->n=nn;
nn->p=rear;
rear=rear->n;
}
}

void del_at_beg()
{
if(front==NULL)
return;

else
{
struct node* temp=front;
front=front->n;
free(temp);
temp=NULL;
}
}

void del_at_last()
{
if(rear==NULL)
return;
else
{
struct node* temp=rear;
rear=rear->p;
free(temp);
temp=NULL;
}
}
void print()
{
struct node* curr=front;
while(curr)
{
printf("%d\n",curr->d);
curr=curr->n;
}
}
int main()
{
for(int i=0;i<5;i++)
{
int a;
scanf("%d",&a);
insert_at_last(a);
}
del_at_last();
print();
//printf("%d",rear->d);
}
