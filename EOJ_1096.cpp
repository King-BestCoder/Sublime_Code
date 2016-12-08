#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int num[9][9];
int n;
double dp[9][9][9][9][18];
const int inf=0x3f3f3f3f;
const double inff=0x3f3f3f-1;
double ave;
//状态转移方程式  
//dp[r1][r2][c1][c2][n]=min(dp[r1][r2][c1][c2][n],min(dfs(r1,i,c1,c2)+sum(i+1,r2,c1,c2),dfs(i,r2,c1,c2)+sum(r1,i-1,c1,c2));
// 对于列的dp与上式同理，数组保存状态值用以记忆化搜索
double sum(int r1,int r2,int c1,int c2){
	double tmp=0;
	for(int i=r1;i<=r2;i++)
		for(int j=c1;j<=c2;j++)
			tmp+=num[i][j];
	double temp=(tmp-ave)*(tmp-ave);
	return temp;
}

double dfs(int r1,int r2,int c1,int c2,int n){
	if(dp[r1][r2][c1][c2][n]<inf)
		return dp[r1][r2][c1][c2][n];
	if(n==1){
		return sum(r1,r2,c1,c2);
	}
	for(int i=r1;i<r2;i++){
		dp[r1][r2][c1][c2][n]=min(dp[r1][r2][c1][c2][n],
			min(dfs(r1,i,c1,c2,n-1)+sum(i+1,r2,c1,c2),dfs(i,r2,c1,c2,n-1)+sum(r1,i-1,c1,c2)));
	}
	for(int i=c1;i<c2;i++){
		dp[r1][r2][c1][c2][n]=min(dp[r1][r2][c1][c2][n],
			min(dfs(r1,r2,c1,i,n-1)+sum(r1,r2,i+1,c2),dfs(r1,r2,i,c2,n-1)+sum(r1,r2,c1,i-1)));
	}
	return dp[r1][r2][c1][c2][n];
}

int main()
{
	scanf("%d",&n);
	int sum=0;
	for(int i=1;i<=8;i++){
		for(int j=1;j<=8;j++){
			scanf("%d",&num[i][j]);
			sum+=num[i][j];
		}
	}
	ave=(double)(sum/(0.0+n));
	for(int a=1;a<=8;a++)
		for(int b=1;b<=8;b++)
			for(int c=1;c<=8;c++)
				for(int d=1;d<=8;d++)
					for(int e=1;e<=15;e++)
						dp[a][b][c][d][e]=inf;
	double tmp;
	tmp=dfs(1,8,1,8,n);
	printf("%.3f\n",sqrt(tmp/(n+0.0)));
	// double ans=sqrt(dp[1][8][1][8][n])/(n+0.0);
	// printf("%.3f\n",ans);
	return 0;
}
