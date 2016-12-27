#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int maxn=105;
char pre[maxn],mid[maxn];

typedef struct Node{
	char data;
	struct Node *left,*right;
	Node(char c){
		data=c;
		left=right=NULL;
	}
}node;
void postorder(node *p){
	if(p!=NULL){
		postorder(p->left);
		postorder(p->right);
		printf("%c",p->data);
	}
}
node *PreMidtoPost(int l1,int r1,int l2,int r2,node *p){
	int m;
	// printf("%d %d %d %d\n",l1,r1,l2,r2);
	p=new node(pre[l1]);
	if(l1!=r1){
		for(m=0;m+l2<=r2;m++){
			if(mid[m+l1]==pre[l1]) break;
		}
		p->left=PreMidtoPost(l1+1,l1+m,l2,l2+m-1,p->left);
		p->right=PreMidtoPost(l1+1+m,r1,l2+m+1,r2,p->right);
	}
	return p;
}

int main(int argc, char const *argv[])
{
	while(~scanf("%s %s",pre,mid)){
		node *root;
		root=PreMidtoPost(0,strlen(pre)-1,0,strlen(mid)-1,root);
		postorder(root);
		printf("\n");
	}
	return 0;
}