#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
typedef struct Node{
	int from,to,cost;
}node;
node edge[maxn];//储存边的信息
int d[maxn];//保存源点到别的点的距离
const int inf=0x3f3f3f3f;

bool negativeloop(const int &n,const int &m){
	memset(d,0,sizeof(d));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			node temp=edge[j];
			if(d[temp.to]>d[temp.from]+temp.cost){
				d[temp.to]=d[temp.from]+temp.cost;
				if(i==n-1) return true;
			}
		}
	}
	return false;
}

void bellmanford(const int &s,const int &n,const int &m){
	for(int i=0;i<n;i++){
		d[i]=inf;
	}
	d[s]=0;
	while(1){
		bool update=false;
		for(int i=0;i<m;i++){
			node temp=edge[i];
			if(d[temp.from]!=inf&&d[temp.to]>d[temp.from]+temp.cost){
				d[temp.to]=d[temp.from]+temp.cost;
				update=true;
			}
		}
		if(!update) break;
	}
}

int main(int argc, char const *argv[])
{
	int n,m,s;
	scanf("%d %d",&n,&m);//输入点的个数和边的条数
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&edge[i].from,&edge[i].to,&edge[i].cost);
	}
	scanf("%d",&s);//输入源点s
	if(!negativeloop(n,m)){
		bellmanford(s,n,m);
	}
	else{
		printf("存在负环\n");
	}
	//此处以下可以进行输出等操作，不赘述
	return 0;
}