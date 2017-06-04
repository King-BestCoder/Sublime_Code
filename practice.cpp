#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	map<string,int>mapint;
	mapint["Tetrahedron"]=4;
	mapint["Cube"]=6;
	mapint["Octahedron"]=8;
	mapint["Dodecahedron"]=12;
	mapint["Icosahedron"]=20;
	int n,ans=0;
	while(~scanf("%d",&n)){
		string s;
		ans=0;
		for(int i=0;i<n;i++){
			cin>>s;
			ans+=mapint[s];
		}
		printf("%d\n",ans);
	}
	return 0;
}