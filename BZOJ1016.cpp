#include <bits/stdc++.h>
using namespace std;

const int mod=31011;
const int maxn=1005;
int fa[maxn];
typedef struct Node{
	int from,to,cost;
}node;
node num[maxn];
node value[maxn];

inline int ReadInt(){
	int n=0,ch=getchar();
	int flag=0;
	while(!isdigit(ch)&&ch!='-'){
		ch=getchar();
	}
	if(ch=='-') flag=1,ch=getchar();
	while(isdigit(ch))
		n=(n<<3)+(n<<1)+(ch-'0'),ch=getchar();
	if(flag) n=-n;
	return n;
}

int find(int a){
	if(a==fa[a]) return a;
	else return fa[a]=find(fa[a]);
}

void merge(int a,int b){
	int aa=find(a),ab=find(b);
	if(aa!=ab){
		fa[aa]=ab;
	}
}

bool cmp(const node &a,const node &b){
	return a.cost<b.cost;
}

int main(int argc, char const *argv[])
{
	int n,m;
	n=ReadInt(),m=ReadInt();
	for(int i=0;i<maxn;i++)
		fa[i]=i;
	for(int i=0;i<m;i++){
		num[i].from=ReadInt();
		num[i].to=ReadInt();
		num[i].cost=ReadInt();
	}
	sort(num,num+n,cmp);
	int cnt=0;
	int cost=0;
	for(int i=0;i<m;i++){
		if(cnt==n-1) break;
		int aa=find(num[i].from),ab=find(num[i].to);
		if(aa!=ab){
			cost+=num[i].cost;
			merge(num[i].from,num[i].to);
			cnt++;
		}
	}
	if(cnt!=n-1){
		printf("0\n");
	}
	else{

	}
	printf("%d\n",cost);
	return 0;
}