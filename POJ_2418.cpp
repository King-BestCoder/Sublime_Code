#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <string>
#include <iomanip>

using namespace std;
struct node{
	string data;
	int cnt;
	struct node *left,*right;
};
int sum=0;
node* insert(node *p,const string &a){
	if(p==NULL){
		struct node *q=new node;
		q->data=a;
		q->cnt=1;
		q->left=q->right=NULL;
		return q;
	}
	else{
		if(a<p->data) p->left=insert(p->left,a);
		else if(a>p->data) p->right=insert(p->right,a);
		else p->cnt++;
		return p;
	}
}
double ans;
void print(node *p){
	if(p!=NULL){
		print(p->left);
		ans=(double)(p->cnt)/sum;
		ans*=100;
		cout<<p->data<<" ";
		printf("%.4f\n",ans);
		print(p->right);
	}
}
int main(int argc, char const *argv[])
{
	string a;
	struct node *root;
	root=NULL;
	while(getline(cin,a)){
		root=insert(root,a);
		sum++;
	}
	print(root);
	return 0;
}