#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAX=505;
const int INF=1e9+7;
int n,m,tot,a[MAX],b[MAX],ans[MAX][2],ansn;
void del(int x)
{
	n--;
	for(int i=x;i<=n;i++)  a[i]=a[i+1];
}
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	cin>>m;
	for (int i=1;i<=m;i++) cin>>b[i];
	int p=1,q;
	while(p<=m)
	{
		int sum,mx,mxn;
		if(a[1]==b[p])
		{
			del(1),p++,tot++;
			continue;
		}
		
		sum=a[1],mx=-1;

		for(int j=2;j<=n && sum<b[p];sum+=a[j],j++)
			if(a[j]!=a[j-1] && mx<a[j]+a[j-1])  
					mx=a[j]+a[j-1],mxn=j;
		if(mx==-1 || sum!=b[p])
			return cout<<"NO\n",0;
		if(a[mxn]>a[mxn-1])  
			ans[++ansn][0]=mxn+tot,ans[ansn][1]=0;
		else  
			ans[++ansn][0]=mxn-1+tot,ans[ansn][1]=1;
		a[mxn-1]+=a[mxn];
		del(mxn);
	}
	if(n>=1)
		return cout<<"NO\n",0;
	cout<<"YES\n";
	for(int i=1;i<=ansn;i++)
		cout<<ans[i][0]<<" "<<(ans[i][1]==0?'L':'R')<<'\n';
	return 0;
}
