#include<stdio.h>
#include<stdlib.h>
struct node
{
int d;
struct node* n;
};
struct node* h=NULL;
struct node* l=NULL;
void ins_end(int dt) 
{
 struct node* nn =(struct node*)malloc(sizeof(struct node));  
 nn->d=dt;
 nn->n=NULL;
    if(h==NULL) 
    { 
    h=nn;
    l=nn;
    return;
    }
    l->n=nn;
    l=l->n;
} 

void print()
{
if(h==NULL)
return;
struct node* curr=h;
while(curr)
{
printf("%d\n",curr->d);
curr=curr->n;
 }
}
int main()
{
struct node* h=NULL;
h=(struct node*)malloc(sizeof(struct node));
h=NULL;
for(int i=0;i<5;i++)
{
 int a;
 scanf("%d",&a);
 ins_end(a);
}
print();
return 0;
}
