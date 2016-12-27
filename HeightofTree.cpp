#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int maxn=1005;
typedef struct Node{
	int data;
	struct Node *left,*right;
	Node(int t){
		data=t;
		left=right=NULL;
	}
}node;
int max(int a,int b){
	return a>b?a:b;
}
int height(node *p){
	int tmp=0;
	if(p!=NULL){
		int tmp1=height(p->left);
		int tmp2=height(p->right);
		tmp=1+max(tmp1,tmp2);
	}
	return tmp;
}
node *insert(node *p,int t){
	if(p==NULL){
		p=new node(t);
		return p;
	}
	else{
		if(t<p->data){
			p->left=insert(p->left,t);
		}
		else if(t>p->data){
			p->right=insert(p->right,t);
		}
		return p;
	}
}
void midorder(node *p){
	if(p!=NULL){
		midorder(p->left);
		printf("%d\n",p->data);
		midorder(p->right);
	}
}
int main(int argc, char const *argv[])
{
	node *root;
	root=NULL;
	int t;
	for(int i=1;i<=3;i++){
		scanf("%d",&t);
		root=insert(root,t);
	}
	int ans=0;
	ans=height(root);
	printf("%d\n\n",ans);
	// midorder(root);
	return 0;
}