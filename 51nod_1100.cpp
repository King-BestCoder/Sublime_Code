#include <bits/stdc++.h>
using namespace std;
typedef struct Node{
	int x,y,id;
}node;
typedef pair<int,int> pii;

bool cmp(node a,node b){
	if(a.x!=b.x)
		return a.x<b.x;
	else 
		return a.y<b.y;
} 

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	node num[10005];
	for(int i=0;i<n;i++){
		scanf("%d %d",&num[i].x,&num[i].y);
		num[i].id=i+1;
	}
	sort(num,num+n,cmp);
	double ans=-0x3f3f3f;
	vector<pii>aa;
	for(int i=0;i<n-1;i++){
		double tmp=(double)((num[i].y-num[i+1].y)/(num[i].x-num[i+1].x));
		if(tmp>ans){
			ans=tmp;
			aa.clear();
			aa.push_back(pii(num[i].id,num[i+1].id));
		}
		else if(tmp==ans){
			aa.push_back(pii(num[i].id,num[i+1].id));
		}
		else continue;
	}
	for (std::vector<pii>::iterator i = aa.begin(); i != aa.end(); ++i)
	{
		printf("%d %d\n",i->first,i->second);
	}
	return 0;
}