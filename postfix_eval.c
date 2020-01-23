#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct stack
{
int d;
struct stack* n;
}S;
S* h=NULL;
void push(int dt)
{
S* nn=(S*)malloc(sizeof(S));
nn->d=dt;
if(!h)
{
h=nn;
return;
}
nn->n=h;
h=nn;
}
void pop()
{
if(!h)
return;
S* t=h;
if(h->n);
h=h->n;
free(t);
}
int empty()
{
return !h;
}
int top()
{
return h->d;
}

int eval(char ch[])
{
int n=strlen(ch);
for(int i=0;i<n;i++)
{
if(ch[i]>=49&&ch[i]<=58){
push(ch[i]-'0');
//printf("%d",top());
}
else
{
int a=top();
pop();
int b=top();
pop();
if(ch[i]=='*')
push((b*a));
else if(ch[i]=='/')
push((b/a));
else if(ch[i]=='+')
push((b+a));
else if(ch[i]=='-')
push((b-a));
}
}
int res=top();
pop();
return res;
}

int main()
{
char ch[20];
scanf("%s",ch);
printf("%d ",eval(ch));
}
