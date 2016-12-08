#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
 
const int INF = 9999999;
int m[102][102];
map<string, int>my;
int n;
 
void floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
}
 
int main()
{
    int T;
    while (cin >> n >> T)
    {
        my.clear();
        int cnt = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                m[i][j] = INF;
        string a, b;
        int t;
        while (T--)
        {
            cin >> a >> b >> t;
            if (my[a] == 0)
                my[a] = cnt++;
            if (my[b] == 0)
                my[b] = cnt++;
            m[my[a]][my[b]] = t;
            m[my[b]][my[a]] = t;
            printf("%d %d %d\n",my[a],my[b],t);
        }
        floyd();
        cin >> t;
        while (t--)
        {
            cin >> a >> b;
            int ans;
            if (!my[a] || !my[b])
                ans = -1;
            else
            {
                if (m[my[a]][my[b]] == INF)
                    ans = -1;
                else
                    ans = m[my[a]][my[b]];
            }
            cout << ans << endl;
        }
    }    
}