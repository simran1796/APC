#include<stdio.h>
#include<stdlib.h>
struct node 
{ 
int data; 
struct node *left; 
struct node *right; 
};
 
typedef struct stack 
{ 
struct node* d; 
struct stack* n; 
}S;

S* h=NULL;

void push(struct node* dt)
{
S* nn=(S*)malloc(sizeof(S));
nn->d=dt;
nn->n=h;
h=nn;
} 

void pop()
{
S* t=h;
h=h->n;
free(t);
}

struct node* top()
{
return h->d;
}

int empty()
{
return !h;
}

struct node* newNode(int data) 
{ 
struct node* node = (struct node*)malloc(sizeof(struct node)); 
node->data = data; 
node->left = NULL; 
node->right = NULL; 
return(node); 
} 

void Inorder(struct node* curr)
{
while(!empty()||curr)
{
while(curr)
{
push(curr);
curr=curr->left;
}
printf("%d ",top()->data);
curr=top()->right;
pop();
}
printf("\n");
}

void Preorder(struct node* curr)
{
while(!empty()||curr)
{
while(curr)
{
printf("%d ",curr->data);
push(curr);
curr=curr->left;
}
curr=top()->right;
pop();
}
printf("\n");
}

int main() 
{ 
struct node *root = newNode(1); 
root->left = newNode(2); 
root->right = newNode(3); 
root->left->left = newNode(4); 
root->left->right=newNode(5);
root->right->left=newNode(6);
root->right->right=newNode(7);
printf("Inorder: ");
Inorder(root);
printf("Preorder: ");
Preorder(root);
return 0; 
}


