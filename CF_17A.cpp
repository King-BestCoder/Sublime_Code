#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int maxn=1005;
int num[maxn];

vector<int>prim;

bool is_prime(int n){
	for(int i=2;i*i<=n;i++)
		if(n%i==0) return false;
	return true;
}

void init(){
	for(int i=2;i<=1000;i++){
		if(is_prime(i)) prim.push_back(i);
	}
	memset(num,0,sizeof(num));
	int n=prim.size();
	for(int i=0;i<n-1;i++){
		int t=prim[i]+prim[i+1]+1;
		if(is_prime(t)) num[t]=1;
	}
}

int main(int argc, char const *argv[])
{
	int n,k;
	init();
	while(~scanf("%d %d",&n,&k)){
		int sum=0;
		for(int i=2;i<=n;i++){
			if(num[i]){
				// cout<<i<<endl;
				sum++;
			}
		}
		if(sum>=k) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
