#include <bits/stdc++.h>
using namespace std;

/*
最长回文子序列
如果一个字符串正序与逆序都相同，那么这个字符串是回文字符串
回文子序列是指一个字符串中不一定连续的字符构成的回文字符串
现给出一个字符串，找出其中长度最长的回文子序列
我们假设lps[i][j]代表原字符串中从下标为i的地方开始，下标为j的地方结束的最长公共子序列长度
对于每个回文子序列，首尾两端的字符必定是相同的
因此，可以大致推出状态转移方程：
	lps[i][j]=lps[i+1][j-1]+2   			(s[i]==s[j])
	lps[i][j]=max(lps[i+1][j],lps[i][j-1])  (s[i]!=s[j])

算法复杂度为O(n^2)
*/

const int maxn=105;
int lps[maxn][maxn];

int main(int argc, char const *argv[])
{
	string s;
	while(cin>>s){
		int n=s.length();
		for(int i=0;i<n;i++)	
			lps[i][i]=1;
		for(int i=n-1;i>=0;i--){
			for(int j=0;j<n;j++){
				if(i<j){
					if(s[i]==s[j])
						lps[i][j]=lps[i+1][j-1]+2;
					else
						lps[i][j]=max(lps[i+1][j],lps[i][j-1]);
				}
			}
		}
		int ans=0,a,b;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(lps[i][j]>ans){
					ans=lps[i][j];
					a=i,b=j;
				}
			}
		}
		string str;
		while(a<=b){
			if(s[a]==s[b]){
				str+=s[a];
				a++,b--;
			}
			else{
				a++;
			}
		}
		printf("Length = %d\n",ans);
		cout<<str;
		for(int i=str.length()-2;i>=0;i--)
			cout<<str[i];
		cout<<endl;
	}
	return 0;
}