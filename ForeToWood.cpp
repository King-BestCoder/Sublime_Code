#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxm 4
#define maxn 105
typedef struct Node4{
	char data;
	struct Node4 *child[maxm];
	Node4(char t){
		data=t;
		for(int i=0;i<maxm;i++)
			child[i]=NULL;
	}
}node4;
typedef struct Node{
	char data;
	struct Node *left,*right;
	Node(char t){
		data=t;
		left=right=NULL;
	}
}node;
node *beta(node4 *p,node4 *q,node4 *r,node *k){
	node *t;
	if(p==NULL) return NULL;
	t=new node(p->data);
	t->left=beta(p->child[0],p->child[1],p->child[2],p->child[3]);
	t->right=beta(q,r,k,NULL);
	return t;
}
int main(int argc, char const *argv[])
{
	
	return 0;
}