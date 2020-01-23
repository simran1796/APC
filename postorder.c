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

void push(S **h,struct node* dt)
{
S* nn=(S*)malloc(sizeof(S));
nn->d=dt;
nn->n=(*h);
(*h)=nn;
} 

void pop(S** h)
{
S* t=(*h);
(*h)=(*h)->n;
free(t);
}

struct node* top(S* h)
{
return h->d;
}

int empty(S* h)
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

void Postorder(struct node* curr)
{
S* h1=NULL;
S* h2=NULL;
push(&h1,curr);
while(!empty(h1))
{
curr=top(h1);
pop(&h1);
push(&h2,curr);
if(curr->left)
push(&h1,curr->left);
if(curr->right)
push(&h1,curr->right);
}
while(!empty(h2))
{
printf("%d ",top(h2)->data);
pop(&h2);
}
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
printf("Postorder: ");
Postorder(root);
return 0; 
}


