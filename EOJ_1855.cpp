#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>

using namespace std;

const int maxn=10005;
struct node{
	int x,y;
}num[maxn];

int n,l,p;
bool cmp(struct node a,struct node b){
	return a.x<b.x;
}

int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d %d",&num[i].x,&num[i].y);
	scanf("%d %d",&l,&p);
	for(int i=0;i<n;i++){
		num[i].x=l-num[i].x;
	}
	sort(num,num+n,cmp);
	num[n].x=l,num[n].y=0;
	int flag=0;
	int cnt=0;
	int x=0;
	int sum=p;
	priority_queue<int>que;
	n++;
	// for(int i=0;i<n;i++)
	// 	printf("%d %d\n",num[i].x,num[i].y);
	for(int i=0;i<n;i++){
		while(sum+x<num[i].x){
			if(que.empty()){
				flag=1;
				break;
			}
			sum+=que.top();
			que.pop();
			// printf("%d\n",i);
			cnt++;
		}
		if(flag) break;
		sum=sum-(num[i].x-x);
		x=num[i].x;
		que.push(num[i].y);
		// printf("%d %d\n",i,sum);
	}
	if(flag)
		puts("-1");
	else
		printf("%d\n",cnt);
	return 0;
}
