#include <bits/stdc++.h>
using namespace std;
const int maxn=505;
string a[510],ep;
int n,m,i,j,l,r,fl;
int main(){
	cin>>n>>m;
	for (i=1;i<=m;i++) ep=ep+'.';
	for (i=1;i<=n;i++) cin>>a[i];
	for (l=1;a[l]==ep;l++);
	for (r=n;a[r]==ep;r--);
	for (fl=1,i=l+1;i<=r;i++)
		if (a[i]!=a[l]) fl=0;
	puts(fl?"YES":"NO");
	return 0;
}