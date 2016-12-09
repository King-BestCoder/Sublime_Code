#include <bits/stdc++.h>
using namespace std;
typedef struct Node{
	int x;
	struct Node *left,*right;
	Node(int t){
		x=t;
		left=right=NULL;
	}
}node;
node *root=NULL;
node *reverse(node *p){
	if(p!=NULL){
		p->left=reverse(p->left);
		p->right=reverse(p->right);
		node *tmp=p->left;
		p->left=p->right;
		p->right=tmp;
		return p;
	}
}
node *insert(node *p,int t){
	if(p==NULL){
		p=new node(t);
	}
	else if(t<p->x){
		p->left=insert(p->left,t);
	}
	else if(t>p->x){
		p->right=insert(p->right,t);
	}
	return p;
}
void print(node *p){
	if(p!=NULL){
		print(p->left);
		printf("%d\n",p->x);
		print(p->right);
	}
}

void postOrder3(node *root)     //非递归后序遍历
{
    stack<node*> s;
    node *cur;                      //当前结点 
    node *pre=NULL;                 //前一次访问的结点 
    s.push(root);
    while(!s.empty())
    {
        cur=s.top();
        if((cur->left==NULL&&cur->right==NULL)||
           (pre!=NULL&&(pre==cur->left||pre==cur->right)))
        {
            cout<<cur->x<<" ";  //如果当前结点没有孩子结点或者孩子节点都已被访问过 
              s.pop();
            pre=cur; 
        }
        else
        {
            if(cur->right!=NULL)
                s.push(cur->right);
            if(cur->left!=NULL)    
                s.push(cur->left);
        }
    }    
}

int main(int argc, char const *argv[])
{
	for(int i=1;i<=10;i++){
		root=insert(root,i);
	}
	print(root);
	printf("\n");
	root=reverse(root);
	print(root);
	postOrder3(root);
	return 0;
}