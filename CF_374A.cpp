#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;
typedef long long LL;

int main(int argc, char const *argv[])
{
	int n,k;
	vector<string>s;
	string str;
	int num[105];
	memset(num,0,sizeof(num));
	while(~scanf("%d %d",&n,&k)){
		memset(num,0,sizeof(num));
		s.clear();
		for(int i=0;i<n;i++){
			cin>>str;
			// cout<<str<<endl;
			s.push_back(str);
			num[str.size()]++;
		}
		string t;
		cin>>t;
		int l=0;
		int x=t.size();
		for(int i=1;i<x;i++){
			l+=num[i];
			// cout<<num[i]<<endl;
		}
		// cout<<x<<endl;
		cout<<l+1+(l/k)*5<<" "<<l+num[x]+((l+num[x]-1)/k)*5<<endl;
	}
	return 0;
}
