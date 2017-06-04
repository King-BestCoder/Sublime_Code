#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+6;
int num[maxn];
typedef long long LL;
int n,k;
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
vector<int>vec[maxn];
void init(){//筛法求约数
	for(int i=1;i<maxn;i++){
		for(int j=i;j<maxn;j+=i){
			vec[j].push_back(i);
		}
	}
}

bool cmp(const int &a,const int &b){
	return a>b;
}

int main(int argc, char const *argv[])
{
	int __,_;
	init();
	scanf("%d",&__);
	for(_=1;_<=__;_++){
		scanf("%d %d",&n,&k);
		for(int i=0;i<n;i++){
			scanf("%d",&num[i]);
		}
		int d;
		printf("Case %d: ",_);
		for(int i=0;i<n-1;i++){
			d=gcd(num[i],num[i+1]);
			if(k>vec[d].size()){
				printf("-1%c",i==n-2?'\n':' ');
			}
			else{
				int len=vec[d].size();
				// sort(vec[d].begin(),vec[d].end(),cmp);
				printf("%d%c",vec[d][len-k],i==n-2?'\n':' ');
			}
		}
	}
	return 0;
}