#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
int data; 
struct tree* l;
struct tree* r;
}T;
T* node(int d)
{
T* nn=(T*)malloc(sizeof(T));
nn->data=d;
nn->l=NULL;
nn->r=NULL;
return nn;
}

void max_min(T* root,int *max,int *min,int h)
{
if(!root)
return;
if(h<*min)
*min=h;
if(h>*max)
*max=h;
max_min(root->l,max,min,h-1);
max_min(root->r,max,min,h+1);
}

void get(T* root,int level,int h)
{
if(!root)
return;
if(level==h)
printf("%d ",root->data);
get(root->l,level,h-1);
get(root->r,level,h+1);
}

void print(T* root)
{
int max=0;
int min=0;
int i=0;
max_min(root,&max,&min,0);
for(i=min;i<=max;i++)
{
get(root,i,0);
printf("\n");
}
}
int main()
{
T* root=node(1);
root->l=node(2);
root->r=node(6);
root->l->l=node(3);
root->l->r=node(4);
root->l->l->r=node(5);
root->r->l=node(7);
root->r->r=node(8);
print(root);
}
