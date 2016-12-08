#include <iostream>  
#include <stack>  
using namespace std;  
  
const int _N = 1000;  
int list[_N];  
int n;  
  
void dfs(int i, int n, stack<int> s)  
{  
    if(i == n)  
    {  
        cout<<"{";  
        while(!s.empty())  
        {  
            cout<<" "<<s.top();  
            s.pop();  
        }  
        cout<<"}"<<endl;  
    }else  
    {  
        s.push(list[i]); //取  
        dfs(i + 1, n, s);  
        s.pop(); //舍  
        dfs(i + 1, n, s);  
    }  
}  
int main()  
{  
    int i;  
    while(cin>>n)  
    {  
        stack<int> s;  
        for(i = 0; i < n; i++)  
            list[i] = i + 1; //初始化  
        dfs(0, n, s);  
    }  
    return 0;  
} 