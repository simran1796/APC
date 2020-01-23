#include<stdio.h>
#include<stdlib.h>
typedef struct queue
{
int d;
struct queue* n;
}q;

q* h=NULL;

void push(int dt)
{
q* nn=(q*)malloc(sizeof(q));
nn->d=dt;
if(h==NULL)
h=nn;
else
{
nn->n=h;
h=nn;
}
}

void pop()
{
if(h==NULL)
return;
else
{
q* temp=h;
h=h->n;
free(temp);
temp=NULL;
}
}

int emp()
{
return !h;
}

int top()
{
if(emp())
return -1;
else
return h->d;
}


int main()
{
int n;
scanf("%d",&n);
int *a=(int*)malloc(sizeof(int)*n);
int *b=(int*)malloc(sizeof(int)*n);
for(int i=0;i<n;i++)
{
scanf("%d",&a[i]);
b[i]=-1;
}
for(int i=n-1;i>=0;i--)
{
if((emp())||a[i]>a[top()])
push(i);
else
{
while((!emp())&&a[i]<a[top()])
{
b[top()]=a[i];
pop();
}
push(i);
}
}
for(int i=0;i<n;i++)
printf("%d\t",b[i]);
return 0;
}
