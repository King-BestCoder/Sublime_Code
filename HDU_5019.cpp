#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

const int maxn=1e5+5;
const int maxnn=1e6+6;
// int num[maxn];
int a[maxn];
vector<int>GCD[maxnn];

bool cmp(const int &a,const int &b){
	return a>b;
}

inline int read(){
	int n=0,ch=getchar(),sign=0;
	while(!isdigit(ch)&&ch!='-')
		ch=getchar();
	if(ch=='-') sign=1,ch=getchar();
	while(isdigit(ch)){
		n=(n<<3)+(n<<1)+(ch-'0');
		ch=getchar();
	}
	if(sign) n=-n;
	return n;
}

void getnum(){
	for(int i=1;i<maxn*5;i++){
		for(int j=1;j*j<=i;j++){
			if(i%j==0)
				GCD[i].push_back(j);
			if(j*j!=i)
				GCD[i].push_back(i/j);
		}
	}
}

int main(int argc, char const *argv[])
{
	int T;
	// getnum();
	return 0;
	T=read();
	for(int t=1;t<=T;t++){
		int n,k;
		n=read(),k=read();
		for(int i=0;i<n;i++)
			a[i]=read();
		int d;
		printf("Case %d: ",t);
		for(int i=0;i<n-1;i++){
			d=gcd(num[i],num[i+1]);
			
		}
	}
	return 0;
}