#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <iostream>
using namespace std;

struct node{
	int data;
	struct	node *llink,*rlink;
};
typedef struct node point;
point *head,*tail;

void insert(int t){
	if(head==NULL){
		point *q=(point *)malloc(sizeof(point));
		q->data=t;
		q->rlink=NULL;
		head=q;
		tail=head;
		tail->llink=tail->rlink=NULL;
		return ;
	}
	point *p=(point *)malloc(sizeof(point));
	p->data=t;
	p->llink=p->rlink=NULL;
	tail->rlink=p;
	p->llink=tail;
	tail=p;
	return ;
}
void print(){
	if(head==NULL) return ;
	point *tmp=head;
	while(tmp!=NULL){
		printf("%d\n",tmp->data);
		tmp=tmp->rlink;
	}
	return ;
}
void reverse(){
	point *tmp;
	tmp=head;
	point *last,*next;
	while(tmp!=NULL){
		last=tmp->llink,next=tmp->rlink;
		tmp->rlink=last,tmp->llink=next;
		tmp=next;
	}
	tmp=head,head=tail,tail=tmp;
	return ;
}
int main(int argc, char const *argv[])
{
	int i,t,n;
	head=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&t);
		insert(t);
	}	
	print();
	reverse();
	print();
	return 0;
}