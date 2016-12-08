#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=1005;
int a[maxn],b[maxn];
bool cmp(int a,int b){
	return a>b;
}
int main(int argc, char const *argv[])
{
	int n;
	while(~scanf("%d",&n)&&n){
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<n;i++)
			scanf("%d",&b[i]);
		sort(a,a+n,cmp);
		sort(b,b+n,cmp);
		int ans=0,tk=0,tm=n-1,kk=0,km=n-1;
		for(int i=0;i<n;i++){
			if(a[tk]>b[kk]){
				ans+=200;
				tk++,kk++;
			}
			else if(a[tk]<b[kk]){
				ans-=200;
				tm--,kk++;
			}
			else{
				if(a[tm]>b[km]){
					ans+=200,tm--,km--;
				}
				else if(a[tm]<b[km]){
					ans-=200,tm--,kk++;
				}
				else{
					if(a[tm]<b[kk]){
						ans-=200,tm--,kk++;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
