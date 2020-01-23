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
S* r=NULL;
void push(struct node* dt)
{	
S* nn=(S*)malloc(sizeof(S));
nn->d=dt;
if(h==NULL)
{
h=nn;
r=nn;
return;
}
r->n=nn;
r=nn;
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
return (r==h);
}

struct node* newNode(int data) 
{ 
	struct node* node = (struct node*)malloc(sizeof(struct node)); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 
	return(node); 
} 

void Levelorder(struct node* curr)
{
	if(!curr)
		return;
        push(curr);
	push(NULL);
	while(!empty())
	{
		curr=top();
	        pop();
		if(curr==NULL)
                {
		push(NULL);
                }
                else
		{
		if(curr->left)
			{push(curr->left); }
		if(curr->right)
			{push(curr->right);  }
		printf("%d ",curr->data);  
		}   

	}


	printf("\n");
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
        root->left->left->left = newNode(8); 
	printf("Levelorder: ");

	Levelorder(root);
	return 0; 
}


