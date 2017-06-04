#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string a,b;
	while(cin>>a>>b){
		// int flag=0;
		int n=a.length(),m=b.length();
		int sta=0;
		for(int i=0;i<m;i++){
			if(a[sta]==b[i]){
				sta++;
			}
		}
		if(sta>=n){
			// printf("%d %d\n",sta,n);
			printf("Yes\n");
		}
		else printf("No\n");
	}
	return 0;
}