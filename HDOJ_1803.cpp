#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=505;
vector<int> G[maxn]；
int level[maxn];
int iter[maxn];

void add_edge(int u,int v){
	G[u].push_back(v);
	G[v].push_back(u);
}

