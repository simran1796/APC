#include<stdio.h>
#include<stdlib.h>
struct tree
{
int data;
struct tree* left;
struct tree* right;
int l;
int d;
};
struct tree* node(int dt)
{
struct tree* nn=(struct tree*)malloc(sizeof(struct tree));
nn->data=dt;
nn->left=NULL;
nn->right=NULL;
return nn;
}

int max=-100;
int min=100;

void print(struct tree* root,int c,int d)
{
if(!root)
{
c--;
return;
}
print(root->left,c+1,d-1);
root->l=c;
root->d=d;
if(max<d)
max=d;
if(min>d)
min=d;
print(root->right,c+1,d+1);
}
int a[9]={0}; 
int b[9]; 
void get(struct tree* root,int m)
{
if(root==NULL)
return;
int i=m+(root->d);
if((a[i]==0)||b[i]>(root->l))
{
a[i]=root->data;
b[i]=root->l;
}
get(root->left,m);
get(root->right,m);
}
void topview(struct tree* root)
{
int n=max-min+1;
int m=n/2;
if(n%2==0)
m-=1;
get(root,m);
for(int i=m+min;i<n;i++)
printf("%d ",a[i]);
}
int main()
{
struct tree* root=node(1);
root->left=node(2);
root->right=node(3);
root->left->left=node(4);
root->left->right=node(5);
root->right->left=node(14);
root->right->right=node(15);
root->left->right->left=node(6);
root->left->right->left->left=node(8);
root->left->right->left->left->left=node(9);
root->left->right->left->left->left->left=node(10);
root->left->right->right=node(7);
root->left->right->right->right=node(11);
root->left->right->right->right->right=node(12);
root->left->right->right->right->right->right=node(13);
        /*struct tree* root = node(1); 
	root->left = node(2); 
	root->right = node(3); 
	root->left->right = node(4); 
	root->left->right->right = node(5); 
	root->left->right->right->right = node(6); */

print(root,1,0);
topview(root);
}
