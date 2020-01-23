#include<stdio.h>
#include<stdlib.h>
struct node
{
int d;
struct node* n;
};
void print(struct node* a)
{
 while(a!=NULL)
 {
  printf("%d",a->d);
  a=a->n;
 }
}
int main()
{
struct node* h=NULL;
struct node* s=NULL;
struct node* t=NULL;
h=(struct node*)malloc(sizeof(struct node));
s=(struct node*)malloc(sizeof(struct node));
t=(struct node*)malloc(sizeof(struct node));
h->d=1;
h->n=s;
s->d=2;
s->n=t;
t->d=3;
t->n=NULL;
print(h);
return 0;
}
