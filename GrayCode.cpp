#include <bits/stdc++.h>
using namespace  std;

typedef long long LL;

LL to_dec(LL x){//产生第x个Gray码
	return x^=(x>>1);
}

LL to_bin(LL x){//返回Gray码x的产生次序
	LL y=x;
	while(x>>=1){
		y^=x;
	}
	return y;
}

LL bin_to_dec(const string &s){
	LL ans=0;
	for(int i=0;i<s.length();i++){
		ans=ans*2+(s[i]-'0');
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int n;
	string a,b;
	while(cin>>n>>a>>b){
		LL numa=bin_to_dec(a);
		LL numb=bin_to_dec(b);
		// vector<LL>num;
		// for(LL i=0;i<(1<<n);i++){//产生Gray码
		// 	LL temp=to_dec(i);
		// 	num.push_back(temp);
		// 	cout<<i<<"  "<<temp<<endl;
		// }
		// for(LL i=0;i<num.size();i++){
		// 	cout<<num[i]<<"   "<<to_bin(num[i])<<endl;
		// }
		LL ans=llabs(to_bin(numa)-to_bin(numb))-1;
		cout<<ans<<endl;
	}
	return 0;
}