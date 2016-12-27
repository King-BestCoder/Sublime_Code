#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Node{
	int data;
	struct Node *left,*right;
	Node(int t){
		data=t;
		left=right=NULL;
	}
}node;
node *insert(node *p,const int *num,int n){
	//num为数组，n表示这个数组内有多少个元素
	for(int i=0;i<n;i++){
		int t=num[i];
		if(p==NULL){
			p=new node(t);
			continue;
		}
		else{
			node *q=p,*father;
			while(q!=NULL){
				father=q;
				if(t<q->data) q=q->left;
				else if(t>q->data) q=q->right;
			}
			if(father==NULL) father=new node(t);
			else if(t<father->data) father->left=new node(t);
			else if(t>father->data) father->right=new node(t);
		}
	}
	return p;
}
void print(node *p){
	if(p!=NULL){
		print(p->left);
		printf("%d\n",p->data);
		print(p->right);
	}
}
const int num[]={10,23,3423,1,3,-1,0,233};
int main(int argc, char const *argv[])
{
	node *root;
	root=NULL;
	root=insert(root,num,8);
	print(root);
	return 0;
}