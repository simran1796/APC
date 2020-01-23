#include<stdio.h> 
#include<stdlib.h>
typedef struct stack
{
char d;
struct stack* n;
}S;

void insert(S** h,char c)
{
S* nn=(S*)malloc(sizeof(S));
nn->d=c;
if((*h)==NULL)
(*h)=nn;
else
{
nn->n=(*h);
(*h)=nn;
}
}

int prec(char c)
{
switch(c)
{
case '^':
return 3;
case '*':
case '/':
return 2;
case '+':
case '-':
return 1;
default:
return -1;
}
}

void print(S* h)
{
S* curr=h;
while(curr)
{
printf("%c",curr->d);
curr=curr->n;
}
}

void pop(S** h)
{
if((*h)==NULL)
return;
S* t=(*h);
(*h)=(*h)->n;
free(t);
}

int emp(S *h)
{
return !h;
}
int main()
{
char ch[20];
char s[20];
scanf("%s",ch);
S* h=NULL;
int i=0,k=-1;
insert(&h2,'(');
while(ch[i]!='\0')
{
if((ch[i]>=65&&ch[i]<=90)||(ch[i]>=97&&ch[i]<=122)||(ch[i]>=48&&ch[i]<=57))
s[++k]=ch[i];
else if(ch[i]==')')
{
while((h2->d)!='('&&(!emp(h2)))
{
s[++k]=(h2->d);
pop(&h2);
}
pop(&h2);
}
else if(ch[i]=='(')
{
insert(&h2,ch[i]);
}
else
{
if(prec(ch[i])>prec(h2->d))
insert(&h2,ch[i]);
else
{
while(prec(ch[i])<=prec(h2->d))
{
s[++k]=h2->d;
pop(&h2);
}
insert(&h2,ch[i]);
}
}
i++;
}
while(!emp(h2))
{
if(h2->d!='(')
s[++k]=(h2->d);
pop(&h2);}
printf("%s",s);
return 0;
}
















