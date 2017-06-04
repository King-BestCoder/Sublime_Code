#include <bits/stdc++.h>
using namespace std;
const int maxn=10005;
int num[maxn];

int main(int argc, char const *argv[])
{
	int n,q;
	int kase=1;
	while(~scanf("%d %d",&n,&q)){
		if(n==0&&q==0) break;
		for(int i=0;i<n;i++)
			scanf("%d",&num[i]);
		sort(num,num+n);
		printf("CASE# %d:\n",kase++);
		int temp;
		for(int i=0;i<q;i++){
			scanf("%d",&temp);
			int p=lower_bound(num,num+n,temp)-num;
			if(num[p]==temp) printf("%d found at %d\n",temp,p+1);
			else printf("%d not found\n",temp); 
		}
	}
	return 0;
}