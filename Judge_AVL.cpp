#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
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
int judge(node *p){
	//返回1代表是AVL，如果返回是0 的话代表不是AVL
	if(p==NULL) return 1;
	else{
		int tmp1=height(p->left);
		int tmp2=height(p->right);
		if(abs(tmp1-tmp2)>1) return 0;
		return judge(p->left)&&judge(p->right);
	}
}
int main(int argc, char const *argv[])
{
	node *root=NULL;

	return 0;
}