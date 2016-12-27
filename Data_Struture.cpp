#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxm 3
#define maxn 100

typedef struct Node{
//	int lev;
	char data;
	struct Node *child[maxm];
//	struct Node * parent;
    Node(char c){
        data=c;
        for(int i=0;i<maxm;i++)
            child[i]=NULL;
    }
}node;
node *root;
node *create(char *str){
    node *s[maxn],*p=NULL,*q;
    char c;
    int i,k=0,top=0;
    c=str[k];
    while(c){
        if(c>='A'&&c<='Z'){
            p=new node(c);
        }
        else{
            switch(c)
            {
                case '(':
                    s[top++]=p;
                    break;
                case ',':
                    q=s[top-1];
                    i=-1;
                    while(q->child[++i]!=NULL);
                    q->child[i]=p;
                    break;
                case ')':
                    q=s[--top];
                    i=-1;
                    while(q->child[++i]!=NULL);
                    q->child[i]=p;
                    p=q;
            }
        }
        c=str[++k];
    }
    return p;
}
void posorder(node *t){
	int i;
	if(t!=NULL){
		for(i=0;i<maxm;i++)
			posorder(t->child[i]);
		printf("%c",t->data);
	}
}
void preorder(node *t){
    int i;
    if(t!=NULL){
        printf("%c",t->data);
        for(i=0;i<maxm;i++){
            preorder(t->child[i]);
        }
    }
}
void r_preorder(node *t){
    node *s[maxn];
    int top,i;
    if(t==NULL) return ;
    s[0]=t,top=1;
    while(top>0){
        t=s[--top];
        printf("%c",t->data);
        for(i=maxm-1;i>=0;i--)
            if(t->child[i]!=NULL)
                s[top++]=t->child[i];
    }
}
int count(node *p){
    int tmp=0;
    if(p!=NULL){
        tmp++;
        for(int i=0;i<maxm;i++)
            tmp+=count(p->child[i]);
    }
    return tmp;
}
//  测试样例
//  A(B(D,E(H,I),F(J)),C(G(K,L)))
//  A(B(E),C(F,G(H)),D)
int main()
{
	char s[maxn];
	while(~scanf("%s",s)){
        root=NULL;
    	root=create(s);         //构造一棵树
    	r_preorder(root);       //非递归用栈实现前序遍历
        printf("\n");          
        preorder(root);         //递归实现前序遍历
        printf("\n");
        int tmp=count(root);    //结算节点个数
        printf("%d\n",tmp);
        memset(s,0,sizeof(s));
    }
	return 0;
}