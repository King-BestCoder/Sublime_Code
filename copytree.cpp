#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stack>
#include <time.h>
using namespace std;

#define maxn 1005
typedef struct Node{
	int data;
	struct Node *left,*right;
	Node(int t){
		data=t;
		left=right=NULL;
	}
}node;

node *root;
node *copy(node *p){
	node *q;
	if(p==NULL) return NULL;
	else {
		q=new node(p->data);
		q->left=copy(p->left);
		q->right=copy(p->right);
		return q;
	}
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
void s_midorder(node *p){
	if(p==NULL) return ;
	int top=-1;
	node *s[maxn];
	while(p||top>=0){
		while(p){
			s[++top]=p;
			p=p->left;
		}
		p=s[top--];
		printf("%d\n",p->data);
		p=p->right;
	}
}
void postorder(node *p){
	if(p!=NULL){
		postorder(p->left);
		postorder(p->right);
		printf("%d\n",p->data);
	}
}
void s_postorder(node *p){
    if(p == NULL) return ;
    //     if((cur->left == NULL && cur->right == NULL)                     //  左右还是均为NULL, 可以被输出
    //     || (pre != NULL && ((pre == cur->left && cur->right == NULL) || pre == cur->right)))     //  左右还是被输出了, 递归返回
    //     //  其实当前节点要是想被输出, 要么
    //     //  1--其左右孩子均为NULL
    //     //  2--其左孩子刚被输出，而其右孩子为NULL
    //     //  3--其右孩子刚被输出
    //     //
    //     //  但是这里有一个优化, 入栈时候, 先是根入栈， 然后是右孩子, 然后是左孩子,
    //     //  因此当跟元素位于栈顶的时候, 其左右孩子必然已经弹出，即被输出,
    //     //  也就是说, 当前
    //     // 由于栈是先进后出，因此先如后孩子, 再左孩子可以保证递归返回时先遍历左孩子
    node *s[maxn];
    node *cur,*pre=NULL;
    int top=-1;
    s[++top]=p;
    while(top>=0){
    	cur=s[top];
        if((cur->left == NULL && cur->right == NULL)                     //  左右还是均为NULL, 可以被输出
        || (pre != NULL && ((pre == cur->left && cur->right == NULL) || pre == cur->right)))     //  左右还是被输出了, 递归返回
    	{
    		printf("%d\n",cur->data);
    		top--;
    		pre=cur;
    	}
    	else{
    		if(cur->right!=NULL){
    			s[++top]=cur->right;
    		}
    		if(cur->left!=NULL){
    			s[++top]=cur->left;
    		}
    	}
    }
}
int main(int argc, char const *argv[])
{
	root=NULL;
	// srand(time(0));					//随机数生成
	for(int i=0;i<10;i++){
		int t=rand();
		root=insert(root,t);		//随机数插入
		printf("%d\n",t);
	}
	printf("拷贝树\n");
	node *t=copy(root);				//拷贝树
	printf("原树中序遍历\n");
	midorder(root);					//原树中序遍历
	printf("拷贝后的数的遍历\n");				
	midorder(t);					//拷贝后的数的遍历
	printf("原树的非递归中序遍历\n");
	s_midorder(root);				//原树的非递归中序遍历
	printf("递归后序遍历\n");
	postorder(root);				//递归后序遍历
	printf("非递归后序遍历\n");
	s_postorder(root);				//非递归后序遍历
	return 0;
}