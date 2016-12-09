#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
using namespace std;
const int maxn=30006;
int num[maxn];
int n,l,r,mid,t;
bool cmp(int a,int b){
	return a>b;
}
int tmp[maxn];
int main(int argc, char const *argv[])
{
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++)
			scanf("%d",&num[i]);
		int ans=0;
		// sort(num,num+n,cmp);
		tmp[ans++]=num[0];
		for(int i=1;i<n;i++){
			t=num[i];
			l=-1,r=ans-1;
			while(l+1<r){
				mid=l+(r-l)/2;
				if(tmp[mid]>=t)
					r=mid;
				else
					l=mid;
			}
			// printf("%d %d\n",tmp[r],t);
			if(tmp[r]>=t)
				tmp[r]=t;
			else 
				tmp[ans++]=t;
		}
		printf("%d\n",ans);
	}
	return 0;
}
