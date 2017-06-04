// #include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct Node{
	char data;
	Node *right,*left;
	Node(){}
	Node(char a):data(a),right(NULL),left(NULL){}
}node;
node *root;

void preorder(node *t){
	if(t!=NULL){
		printf("%c",t->data);
		preorder(t->left);
		preorder(t->right);
	}
}

node* insert(node *t,char c){
	if(t==NULL){
		t=new node(c);
		return t;
	}
	else if(c<t->data){
		t->left=insert(t->left,c);
	}
	else{
		t->right=insert(t->right,c);
	}
	return t;
}

vector<string>vec;
int main(int argc, char const *argv[])
{
	string s;
	while(cin>>s){
 		if(s=="*"||s=="$"){
 			root=NULL;
 			for(int i=vec.size()-1;i>=0;i--){
 				for(int j=0;j<vec[i].length();j++){
 					root=insert(root,vec[i][j]);
 				}
 			}
 			preorder(root);
 			printf("\n");
 			if(s=="*"){
	 			vec.clear();
 			}
 			else break;
 		}
 		else{
 			vec.push_back(s);
 		}
 	}
	return 0;
}