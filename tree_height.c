#include<stdio.h>
#include<stdlib.h>
struct node 
{ 
int data; 
struct node *left; 
struct node *right; 
};

struct node* newNode(int data) 
{ 
struct node* node = (struct node*)malloc(sizeof(struct node)); 
node->data = data; 
node->left = NULL; 
node->right = NULL; 
return(node); 
} 
int Height(struct node* root)
{
if(root==NULL)
return 0;
int l=Height(root->left);
int r=Height(root->right);
if(l>r)
return(l+1);
else
return(r+1);
}

int main() 
{ 
struct node *root =newNode(1); 
root->left = newNode(2); 
root->right = newNode(3); 
root->left->left = newNode(4); 
root->left->right=newNode(5);
root->right->left=newNode(6);
root->right->right=newNode(7);
root->left->left->left =newNode(8); 
printf("Height:%d",Height(root));
return 0; 
}


