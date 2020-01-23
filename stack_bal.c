#include<stdio.h>
#include<stdlib.h>
struct stack
{
char d;
struct stack* n;
};
void insert(struct stack** h,char c)
{
struct stack* nn=(struct stack*)malloc(sizeof(struct stack));
nn->d=c;
if(h==NULL)
(*h)=nn;
else
{
nn->n=(*h);
(*h)=nn;
}
}
int check(struct stack* h,char c)
{
char dd=h->d;
if((dd=='('&&c==')')||(dd=='['&&c==']')||(dd=='{'&&c=='}'))
return 1;
else
return 0;
}
void pop(struct stack **h)
{
 struct stack* t=(*h);
 if((*h)->n)
 {
 (*h)=(*h)->n; 
 free(t);
 }
 else
 return;
}
int main()
{
struct stack* h=NULL;
int i=0,d=0,a=0,count=0;
char c[20];
scanf("%s",c);
while(c[i]!='\0')
{
if(c[i]=='('||c[i]=='{'||c[i]=='[')
{
insert(&h,c[i]);
d++;
}
else
{
a=check(h,c[i]);
if(a==0||d==0)
break;
else
{pop(&h);
d--;}
}
i++;
}
if(d==0)
printf("Balanced");
else
{
printf("Unbalanced");
while(d)
{pop(&h);
d--;}
}
return 0;
}
