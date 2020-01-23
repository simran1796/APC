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
void mirror(T* root)
{
if(!root)
return;
mirror(root->l);
mirror(root->r);
T* t=root->l;
root->l=root->r;
root->r=t;
}
void print(T* root)
{
if(!root)
return;
print(root->l);
printf("%d ",root->data);
print(root->r);
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
printf("\n");
mirror(root);
print(root);
}
