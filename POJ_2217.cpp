#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
string s,t;
const int maxn=100500;
int sa[maxn],lcp[maxn];
int ranks[maxn+1],tmp[maxn+1];
int n,k;

bool compare_sa(int i,int j){
	if(ranks[i]!=ranks[j]) return ranks[i]<ranks[j];
	else{
		int ri=i+k<=n?ranks[i+k]:-1;
		int rj=j+k<=n?ranks[j+k]:-1;
		return ri<rj;
	}
}

// void construct_sa()
// {
//     n = s.size();
//     for (int i = 0; i <= n; i++){
//         sa[i] = i;
//         ranks[i] = i < n ? s[i] : -1;
//     }
//     for (k = 1; k <= n; k <<= 1)
//     {
//         sort(sa, sa + n + 1, compare_sa);
//         tmp[sa[0]] = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             tmp[sa[i]] = tmp[sa[i - 1]] + compare_sa(sa[i - 1], sa[i]) ;
//         }
//         for (int i = 0; i <= n; i++){
//             ranks[i] = tmp[i];
//         }
//     }
// }

void construct_sa(){
	n=s.length();

	for(int i=0;i<=n;i++){
		sa[i]=i;
		ranks[i]=i<n?s[i]:-1;
	}
	for(k=1;k<=n;k*=2){
		sort(sa,sa+n,compare_sa);
		tmp[sa[0]]=0;
		for(int i=1;i<=n;i++){
			tmp[sa[i]]=tmp[sa[i-1]]+compare_sa(sa[i-1],sa[i]);
		}
		for(int i=0;i<=n;i++)
			ranks[i]=tmp[i];
	}
}

void construct_lcp(){
	int n=s.length();
	for(int i=0;i<=n;i++)
		ranks[sa[i]]=i;

	int h=0;
	// lcp[0]=0;
	for(int i=0;i<n;i++){
		int j=sa[ranks[i]-1];

		if(h>0) h--;
		for(;j+h<n&&i+h<n;h++){
			if(s[j+h]!=s[i+h]) break;
		}
		lcp[ranks[i]-1]=h;
	}
}

void solve(){
	int s1=s.length();
	s+='\n'+t;
	construct_sa();
	construct_lcp();
	int ans=0;
	for(int i=0;i<s.length();i++){
		if((sa[i]<s1)!=(sa[i+1]<s1)){
			ans=max(ans,lcp[i]);
		}
	}
	// cout<<"Nejdelsi spolecny retezec ma delku "<<ans<<"."<<endl;
	printf("Nejdelsi spolecny retezec ma delku %d.\n",ans);
}

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d\n",&T);
	while(T--){
	   	getline(cin,s);
		getline(cin,t);
	    memset(ranks,0,sizeof(ranks));
	    memset(sa,0,sizeof(sa));
	    memset(lcp,0,sizeof(lcp));
	    memset(tmp,0,sizeof(tmp));
		solve();
	}
	return 0;
}