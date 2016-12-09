#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
typedef long long LL;
LL num[55];
int n;
const LL inf=(((LL)1)<<63)-1;
LL dp[55][55];
LL s[55][55];

void Matrix_Chain(LL *num){
	LL q;
	for(int i=1;i<=n;i++)
		dp[i][i]=0;
	for(int l=2;l<=n;l++){
		for(int i=1;i<=n-l+1;i++){
			int j=i+l-1;
			dp[i][j]=inf;
			for(int k=i;k<=j-1;k++){
				q=dp[i][k]+dp[k+1][j]+num[i-1]*num[k]*num[j];
				// cout<<q<<endl;
				if(q<dp[i][j]) {
					dp[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
	// printf("%I64d\n",dp[1][n]);
}

void Print_Optimal_Parens(LL i,LL j)
{
   	if(i==j) printf("A%I64d",i);
   	else
    {   printf("(");
        Print_Optimal_Parens(i,s[i][j]);
        Print_Optimal_Parens(s[i][j]+1,j);
        printf(")");
    }
}      

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	while(T--){
		memset(num,0,sizeof(num));
		memset(s,0,sizeof(s));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%I64d %I64d",&num[i-1],&num[i]);
		}
		Matrix_Chain(num);
		// for(int i=1;i<=n;i++){
		// 	int j;
		// 	for(j=1;j<n;j++)
		// 		printf("%I64d ",dp[i][j]);
		// 	printf("%I64d\n",dp[i][j]);
		// }
		//打印序列
		// Print_Optimal_Parens(1,n);
		// printf("\n");
		printf("%I64d\n",dp[1][n]);
	}
	return 0;
}
