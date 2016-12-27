#include <bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(), x.end()  
#define INS(x) inserter(x, x.begin())  
int T, N, cnt;  
typedef set<int> Set;  
map<Set, int> m;  
vector<Set> v;  
char op[20];  
  
int getID(Set s) {  
    if(m.count(s)) return m[s];  
    v.push_back(s);  
    m[s] = cnt++;  
    return m[s];  
}  
  
int main() {  
    scanf("%d", &T);  
    while(T--) {  
        scanf("%d", &N);  
        stack<int> stk;  
        cnt = 0;  
        v.clear();  
        m.clear();  
        for(int i = 0; i < N; i ++) {  
            scanf("%s", op);  
            int empty = getID(Set());  
  
            if(op[0] == 'P') {  
                stk.push(empty);  
            }  
            else if(op[0] == 'D') {  
                stk.push(stk.top());  
            }  
            else {  
                int a = stk.top(); stk.pop();  
                int b = stk.top(); stk.pop();  
                Set sa = v[a], sb = v[b];  
                int u = 0;  
                Set su = Set();  
                if(op[0] == 'U') {  
                    set_union(ALL(sa), ALL(sb), INS(su));  
                    u = getID(su);  
                }  
                else if(op[0] == 'I') {  
                    set_intersection(ALL(sa), ALL(sb), INS(su));  
                    u = getID(su);  
                }  
                else if(op[0] == 'A') {  
                    sb.insert(getID(sa));  
                    u = getID(sb);  
                }  
                stk.push(u);  
            }  
            cout<<v[stk.top()].size()<<endl;  
        }  
        cout<<"***"<<endl;  
    }  
  
    return 0;  
}  