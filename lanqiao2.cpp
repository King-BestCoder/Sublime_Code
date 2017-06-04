#include <bits/stdc++.h>
using namespace std;
const int maxn=25;
typedef long long LL;
int qpow(int a,int n){
	int ans=1;
	while(n){
		if(n&1)
			ans=ans*a;
		a*=a;
		n>>=1;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	string s;
	while(cin>>s){
		char str[1005];
		int p=0;
		int n=s.length();
		int ans=0;
		for(int i=0;i<n;i++){
			if(s[i]=='('){
				str[p++]=s[i];
				int temp=0;
				for(int j=0;j<p;j++){
					if(str[j]=='(') temp++;
				}
				ans=max(ans,temp);
			}
			else{
				if(p>0&&str[p-1]=='('){
					p--;
				}
				else{
					str[p++]=')';
				}
			}
		}
		if(p){
			printf("NO\n");
		}
		else{
			printf("YES %d\n",ans);
		}
	}
	return 0;
}