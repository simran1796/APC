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

typedef struct stack
{
struct node* d;
struct stack* n;
}S;

void push(S** h,S** r,struct node* dt)
{
S* nn=(S*)malloc(sizeof(S));
nn->d=dt;
if((*h)==NULL)
{
(*h)=nn;
(*r)=nn;
return;
}
(*r)->n=nn;
(*r)=nn;
} 

void pop(S** h)
{
if((*h)==NULL)
return;
S* t=(*h);
(*h)=(*h)->n;
free(t);
}
void pop_r(S** h,S** r)
{
if((*h)==NULL)
return;
S* a=(*h);
while(a->n)
{a=a->n;}
S* t=a->n;
free(t);
a->n=NULL;
(*r)=a;
}

struct node* top(S* h)
{
return h->d;
}

int empty(S* h)
{
return !h;
}
int c=0;
int path(struct node* root,S** h,S** r,int ele)
{
if(!root)
return 0;
push(h,r,root);
if(root->data==ele)
return 1;
if(path(root->left,h,r,ele)||path(root->right,h,r,ele))
return 1;
if(c<8);
{
pop_r(h,r);
c++;
}
return 0;
}

int get_ans(S** h1,S** h2,S** r1,S** r2)
{
int l=0;
while(!empty((*h1))&&!empty((*h2)))
{
if(top((*h1))->data==top((*h2))->data)
{
l=top((*h1))->data;
pop(h1);
pop(h2);
}
else
break;
}
return l;
}

void ancester(struct node* root,int aa,int b)
{
S* h1=NULL;
S* h2=NULL;
S* r1=NULL;
S* r2=NULL;
if(root==NULL)
return ;
int x=path(root,&h1,&r1,aa);
int y=path(root,&h2,&r2,b);
if(x&&y)
printf("%d ",get_ans(&h1,&h2,&r1,&r2));
else
printf("No ancestor");
while(!empty(h1))
{pop(&h1);}
while(!empty(h2))
{pop(&h2);}
}

int main() 
{ 
int a,b;
scanf("%d",&a);
scanf("%d",&b);
struct node *root =newNode(1); 
root->left = newNode(2); 
root->right = newNode(3); 
root->left->left = newNode(4); 
root->left->right=newNode(5);
root->right->left=newNode(6);
root->right->right=newNode(7);
root->left->left->left =newNode(0); 
ancester(root,a,b);
return 0; 
}


