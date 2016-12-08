#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
typedef pair<int,int>pii;
map<pii,int>map1,map2;
int num[3];
int main(int argc, char const *argv[])
{
	int n,ok=1,r1,r2,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			scanf("%d",&num[j]);
		}
		sort(num,num+3);
		if(ans<num[0]){
			ans=num[0],ok=1,r1=i;
		}
		pii p(num[1],num[2]);
		if(map1[p]){
			int t=min(map1[p]+num[0],num[1]);
			if(ans<t){
				ans=t;
				ok=2;r1=i;r2=map2[p];
			}
		}
		if(!map1[p]||map1[p]<num[0]){
			map1[p]=num[0];
			map2[p]=i;
		}
	}
	if(ok==1) printf("%d\n%d\n",ok,r1);
	else printf("%d\n%d %d\n",ok,r1,r2);
	return 0;
}