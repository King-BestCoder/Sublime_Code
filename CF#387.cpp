#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
typedef struct Node{
	int t,k,d;
}node;
node num[maxn];
int n,q;
int peo[105];
int main(int argc, char const *argv[])
{
	while(~scanf("%d %d",&n,&q)){
		memset(peo,0,sizeof(peo));
		for(int i=1;i<=q;i++){
			scanf("%d %d %d",&num[i].t,&num[i].k,&num[i].d);
		}
		int hhh[105];
		int head=1;
		for(int i=1;i<=q;i++){
			int sum=0,id=0,flag=0;
			head=1;
			for(int j=1;j<=n;j++){
				if(peo[j]<num[i].t){
					sum++;
					id+=j;
					hhh[head++]=j;
					// printf("%d %d\n",j,sum);
				}
				if(sum>=num[i].k){
					flag=1;
					break;
				}
			}
			if(flag){
				printf("%d\n",id);
				for(int j=1;j<head;j++){
					int x=hhh[j];
					peo[x]=num[i].t+num[i].d-1;
					// printf("%d %d\n",x,peo[x]);
				}
			}
			else{
				printf("-1\n");
			}
		}
	}	
	return 0;
}