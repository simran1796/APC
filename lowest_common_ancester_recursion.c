#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node* left;
struct node* right;
};

struct node* newNode(int data) 
{ 
struct node* node = (struct node*)malloc(sizeof(struct node)); 
node->data = data; 
node->left = NULL; 
node->right = NULL; 
return(node); 
} 

struct node* ancestor(struct node* root,int a,int b)
{
if(root==NULL)
return NULL;

if(root->data>a&&root->data>b)
return ancestor(root->left,a,b);

else if(root->data<a&&root->data<b)
return ancestor(root->right,a,b);

return root;
}

int main() 
{ 
int a,b;
scanf("%d",&a);
scanf("%d",&b);
struct node *root =newNode(11); 
root->left = newNode(9); 
root->right = newNode(12); 
root->left->left = newNode(7); 
root->left->right=newNode(10);
root->right->left=newNode(8);
root->right->right=newNode(13);
root->left->left->left =newNode(5); 
struct node* h=ancestor(root,a,b);
printf("%d",h->data);
return 0; 
}
