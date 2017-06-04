#include <bits/stdc++.h>
using namespace std;
typedef struct Node{
	int w,h;
}node;
node num[6];
bool cmp(node a,node b){
	if(a.w!=b.w) return a.w<b.w;
	else return a.h<b.h;
}
bool judge(node a,node b){
	return a.w==b.w&&a.h==b.h;
}
int main(int argc, char const *argv[])
{
	int a,b;
	while(~scanf("%d %d",&a,&b)){
		num[0].w=min(a,b);
		num[0].h=max(a,b);
		for(int i=1;i<6;i++){
			scanf("%d %d",&a,&b);
			num[i].w=min(a,b);
			num[i].h=max(a,b);
		}
		sort(num,num+6,cmp);
		if(judge(num[0],num[1])&&judge(num[2],num[3])&&judge(num[4],num[5])&&num[0].w==num[2].w&&num[0].h==num[4].w&&num[2].h==num[4].h)
			printf("POSSIBLE\n");
		else 
			printf("IMPOSSIBLE\n");
	}
	return 0;
}