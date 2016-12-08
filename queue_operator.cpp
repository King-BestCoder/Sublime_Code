#include <bits/stdc++.h>
using namespace std;
const int maxn=505;
typedef struct Node{
	int x,y;
}node;
bool operator <(const Node a,const Node b){
	return a.x>b.x;
};
int main(int argc, char const *argv[])
{
	int a,b;
	priority_queue<node>que;
	while(cin>>a>>b){
		node p;
		p.x=a,p.y=b;
	}
	while(que.size()){
		node p=que.top();
		que.pop();
		cout<<p.x<<"    "<<p.y<<endl;
	}
	return 0;
}