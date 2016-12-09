#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;
typedef long long LL;
LL a,b,ans;
map<LL,int>mapint;
LL num[100],quan[100];
int main(int argc, char const *argv[])
{
	while(~scanf("%I64d %I64d",&a,&b)){
		ans=0;
		for(int i=0;i<=63;i++){
			for(int j=0;j<i;j++){
				LL t=((LL)2<<i)-((LL)1<<j)-1;
				// cout<<((LL)2<<i)<<"  "<<((LL)1<<j)<<endl;
				if(t>=a&&t<=b)
					ans++;
			}
		}
		cout<<ans<<endl;

	}
	return 0;
}