#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	while(T--){
		LL n;
		cin>>n;
		LL ans=0;
		string s;
		LL m=n;
		while(m){
			int t=m&1;
			s+=t+'0';
			m>>=1;
		}
		string str;
		for(int i=0;i<s.length();i++)
			str+=s[s.length()-1-i];
		LL t=1;
		for(int i=0;i<str.length();i++){
			if(str[i]=='1')
				ans+=t;
			t<<=1;
		}
		cout<<ans<<endl;
	}
	return 0;
}