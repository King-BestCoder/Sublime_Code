#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL w,m;
int main(int argc, char const *argv[])
{
	cin>>w>>m;
	while(m){
		if(m%w==0||m%w==1){
			m/=w;
		}
		else if(m%w==w-1){
			m=m/w+1;
		}
		else{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}
