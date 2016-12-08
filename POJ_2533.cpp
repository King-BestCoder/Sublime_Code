#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
const int maxn=100005;
int n;
int num[maxn];
int dp[maxn];

int search(int t,int low,int high){
	int mid;
	while(low<=high){
		mid=(low+high)/2;
		if(dp[mid]>=t)
			high=mid-1;
		else
			low=mid+1;
	}
	return low;
}
//最长上升子序列
int main(int argc, char const *argv[])
{
	while(~scanf("%d",&n)){
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
			scanf("%d",&num[i]);
		int len=1;
		dp[len]=num[len];
		for(int i=2;i<=n;i++){
			if(num[i]>dp[len])
				dp[++len]=num[i];
			else{
				int pos=search(num[i],1,len);
				dp[pos]=num[i];
			}
		}
		printf("%d\n",len);
	}
	return 0;
}
