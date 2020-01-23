#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
int d;
struct stack* n;
}S;

void push(S** h,int dt)
{
S* nn=(S*)malloc(sizeof(S));
nn->d=dt;
if((*h)==NULL)
(*h)=nn;
else
{
nn->n=(*h);
(*h)=nn;
}
}

void print(S* h)
{
S* curr=h;
while(curr)
{
printf("%d\n",h->d);
curr=curr->n;
}
}

int Empty(S* h)
{
return !h;
}

int pop(S** h)
{
int a=(*h)->d;
S* temp=(*h);
(*h)=(*h)->n;
free(temp);
return a;
}

int top(S *h)
{
return h->d;
}

int area(int* a,int n)
{
S* h=(S*)malloc(sizeof(S));
h=NULL;
int max=0;
int i=0;
for(i=0;i<n;i++)
{
if(Empty(h)||a[i]>=a[top(h)])
push(&h,i);
else
{
while(!Empty(h)&&a[top(h)]>a[i])
{
int x=pop(&h);
int b=(Empty(h)?i:(i-top(h)-1));
int c=a[x]*b;
if(max<c)
max=c;
}
push(&h,i);
}
}
while(!Empty(h))
{
int x=pop(&h);
int b=(Empty(h)?i:(i-top(h)-1));
int c=a[x]*b;
if(max<c)
max=c;
}
return max;
}

int main()
{
int n;
scanf("%d",&n);
int *a=(int*)malloc(sizeof(int)*n);
for(int i=0;i<n;i++)
scanf("%d",&a[i]);
int res=area(a,n);
printf("%d",res);
}






