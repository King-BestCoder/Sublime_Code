#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
const int maxn=1005;
struct node {
	double l,r;
}num[1005];
bool cmp(struct node a,struct node b){
	return a.l<b.l;
}
int main(int argc, char const *argv[])
{
	int n,d;
	int cas=1;
	while(~scanf("%d %d",&n,&d)){
		if(n==0&&d==0) break;
		int flag=0;
		if(d<0) flag=1;
		int x,y;
		for(int i=0;i<n;i++){
			scanf("%d %d",&x,&y);
			if(abs(y)>d) flag=1;
			if(y<0) flag=1;
			num[i].l=(double)x-sqrt(d*d-y*y);
			num[i].r=(double)x+sqrt(d*d-y*y);
		}
		printf("Case #%d: ",cas++);
		if(flag==1)
			printf("-1\n");
		else{
			sort(num,num+n,cmp);
			double now=num[0].r;
			int cnt=1;
	        for(int i=1;i<n;i++)
	        {
	            
	            if(num[i].r<now)//这点很重要 
	               now=num[i].r;
	            else if(now<num[i].l)
	            {
	                now=num[i].r;
	                cnt++;
	            }    
	        }
	        printf("%d\n",cnt);
		}
	}
	return 0;
}
