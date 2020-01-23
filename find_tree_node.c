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
int find(struct node* root,int ele)
{
if(root==NULL)
return 0;
if(root->data==ele)
return 1;
int a=find(root->left,ele);
int b=find(root->right,ele);
return a|b;
}

int main() 
{ 
int ele;
scanf("%d",&ele);
struct node *root =newNode(1); 
root->left = newNode(2); 
root->right = newNode(3); 
root->left->left = newNode(4); 
root->left->right=newNode(5);
root->right->left=newNode(6);
root->right->right=newNode(7);
root->left->left->left =newNode(8); 
printf("Find:%d",find(root,ele));
return 0; 
}


