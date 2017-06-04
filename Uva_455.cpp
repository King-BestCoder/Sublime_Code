#include <bits/stdc++.h>
#include <string.h>

using namespace std;
const int maxn=85;
char s[maxn];
char str[maxn];
int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	while(T--){	
		scanf("%s",s);
		int n=strlen(s);
		int k=1;
		for(k=1;k<=n;k++){
			if(n%k) continue;
			memset(str,0,sizeof(str));
			for(int j=0;j<k;j++)
				str[j]=s[j];
			// printf("%s\n",str);
			int flag=1;
			for(int j=0;j<n;j+=k){
				for(int z=0;z<k;z++){
					if(s[j+z]!=str[z]){
						// printf("%d %d\n",j+z,z);
						flag=0;
						break;
					}
				}
			}
			if(flag) break;
		}
		printf("%d\n",k);
		if(T) printf("\n");
	}
	return 0;
}