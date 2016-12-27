#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node{
	char data;
	int ltag,rtag;
	struct Node *left,*right;
	Node(char t){
		data=t;
		left=right=NULL;
		ltag=rtag=0;
	}
}node;
node *pred(node *p){
	if(p->ltag==1||p->left==NULL){
		return p->left;
	}
	p=p->left;
	while(p->rtag==0)
		p=p->right;
	return p;
}
node *succ(node *p){
	if(p->rtag==1||p->right==NULL){
		return p->right;
	}
	p=p->right;
	while(p->rtag==0){
		p=p->right;
	}
	return p;
}
void midorder(node *head){
	if(head!=NULL){
		printf("%c",head->data);
		head=succ(head);
	}
}
void left_insert(node *p,node *q,node *head){
	node *r;
	if(p->ltag==1||p->left==NULL){
		q->left=p->left;
		q->ltag=p->ltag;
		q->right=p;
		q->rtag=1;
		p->left=q;
		p->ltag=0;
		if(q->left==NULL){
			head=q;
		}
	}
	else{
		r=pred(p);
		q->right=p->right;
		q->rtag=p->rtag;
		q->left=r;
		q->ltag=1;
		r->right=q;
		r->rtag=0;
	}
}
void right_insert(node *p,node *q){
	node *r;
	if(p->rtag==1||p->right==NULL){
		q->right=p->right;
		q->rtag=p->rtag;
		q->left=q;
		q->ltag=1;
		p->right=q;
		p->rtag=0;
	}
	else{
		r=succ(p);
		q->left=r->left;
		q->ltag=r->ltag;
		q->right=r;
		q->rtag=1;
		r->left=0;
		r->rtag=0;
	}
}

node *thread_tree(const char *s,int n){
	node *root,*head,*p,*r;
	int i;
	if(n==0) return NULL;
	root=new node(s[0]);
	head=root;
	for(i=1;i<n;i++){
		r=new node(s[i]);
		p=root;
		while(1){
			if(r->data<=p->data){
				if(p->ltag==0&&p->left!=NULL){
					p=p->left;
				}
				else{
					break;
				}
			}
			else{
				if(p->rtag==0&&p->right!=NULL){
					p=p->right;
				}
				else break;
			}
		}
		if(r->data<p->data){
			r->left=p->left;
			r->ltag=p->ltag;
			r->right=p;
			r->rtag=1;
			p->left=r;
			p->ltag=0;
			if(r->left==NULL){
				head=r;
			}
		}
		else if(r->data>p->data){
			r->right=p->right;
			r->rtag=p->rtag;
			r->left=p;
			r->ltag=1;
			p->left=r;
			p->ltag=0;
		}
	}
	return head;
}
int main(int argc, char const *argv[])
{
	node *root;
	char s[205];
	while(~scanf("%s",s)){
		int n=strlen(s);
		root=NULL;
		root=thread_tree(s,n);
		midorder(root);
	}
	return 0;
}