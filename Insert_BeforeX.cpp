#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct node{
	int data;
	struct node *next;
};
typedef struct node point;
point *head;

void insert_x(int x,int t){
	point *q=(point *)malloc(sizeof(point));
	q->data=t;
	q->next=NULL;
	if(head==NULL){
		head=q;
		return ;
	}
	point *tmp=head,*p=head->next;
	if(tmp->data==x){
		q->next=head;
		head=q;
		return ;
	}
	while(p!=NULL){
		if(p->data==x) break;
		tmp=p;
		p=p->next;
	}
	tmp->next=q;
	q->next=p;
	return ;
}
void print(){
	point *p=head;
	while(p!=NULL){
		printf("%d\n",p->data);
		p=p->next;
	}
	return ;
}

int main(int argc, char const *argv[])
{
	int n,i,t,x;
	head=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&x,&t);
		insert_x(x,t);
	}
	print();
	return 0;
}
