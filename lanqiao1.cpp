#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
int dp[105];
char s[105];

int main(int argc, char const *argv[])
{
	scanf("%s",s);
	    int n=strlen(s);
	 	memset(dp,0,sizeof(dp));
	    for(int i=0;i<n;i++){
	    	dp[i]=1;
	    	for(int j=i+1;j<n;j++){
	    		if(s[j]==s[i]+1) {
	    			dp[j]=dp[i]+1;
	    			i++;
	    		}
	    		else break;
	    	}
	    }
	    int ans=0;
	    // for(int i=0;i<n;i++)
	    // 	printf("%d ",dp[i]);
	    // printf("\n");
	    for(int i=0;i<n;i++){
	    	ans=max(ans,dp[i]);
	    }
	    if(ans>=26) printf("0\n");
	    else printf("%d\n",abs(26-ans));
	return 0;
}