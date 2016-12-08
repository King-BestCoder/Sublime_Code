#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
int num[55];
int dp1[55],dp2[55];
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	int i,j,flag,tmp;
	tmp=num[1];
	int ans=1;
	for(j=2;j<=n;j++)
		if(num[j]>tmp){
			flag=-1;
			ans++;
			break;
		}
		else if(num[j]<tmp){
			flag=1;
			ans++;
			break;
		}
	for(i=j+1;i<=n;i++){
		if(num[i]>num[i-1]&&flag==1){
			ans++;
			flag=-1;
		}
		else if(num[i]<num[i-1]&&flag==-1){
			ans++;
			flag=1;
		}
	}
	printf("%d\n",ans);
	return 0;
}
