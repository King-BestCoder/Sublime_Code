#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
typedef long long LL;
int n,m;
int num[50][50];
bool ok(int x, int y) {
    if (x < n && x >= 0 && y < m &&  y >= 0) return true;
    return false;
}
int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		memset(num,0,sizeof(num));
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf("%d",&num[i][j]);
        bool fg = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {

                if (ok(i, j+1) && num[i][j] == num[i][j+1]) fg = true;

                if (ok(i+1, j) && num[i][j] == num[i+1][j]) fg = true;

            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = i+1; j < m; ++j) {
                if (num[0][i] == num[0][j] || num[n-1][i] == num[n-1][j]) fg = true;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (num[i][0] == num[j][0] || num[i][m-1] == num[j][m-1]) fg = true;
            }
        }

        if (fg) printf("Case #%d: Yes\n",t);
        else printf("Case #%d: No\n",t);
	}
	return 0;
}
