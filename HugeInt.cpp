#include <bits/stdc++.h>
using namespace std;

string add(const string &a,const string &b)//大数相加
{
    int n,m,i,j,t=0,flag=0;
    string tmp,s;
    n=a.length();
    m=b.length();
    for(i=n-1,j=m-1;i>=0||j>=0;i--,j--)
    {
        t=0;
        if(i>=0)
            t+=a[i]-'0';
        if(j>=0)
            t+=b[j]-'0';
        if(t+flag>=10){
            tmp+=t+'0'+flag-10;
            flag=1;
        }
        else{
            tmp+=t+'0'+flag;
            flag=0;
        }
    }
    if(flag>0)
        tmp+=flag+'0';
    for(i=tmp.length()-1;i>=0;i--)
        s+=tmp[i];
    return s;
}

string mul(const string &a,int bei,int kuo){//大数相乘
    string ans,t;
    int temp,flag=0;
    for(int i=a.length()-1;i>=0;i--){
        temp=(a[i]-'0')*bei;
        t+=(temp+flag)%10+'0';
        flag=(temp+flag)/10;
    }
    if(flag>0) t+=flag+'0';
    int len=t.length();
    for(int i=len-1;i>=0;i--){
        ans+=t[i];
    }
    for(int i=0;i<kuo;i++)
        ans+='0';
    return ans;
}

int main()
{
    freopen("data.in","r",stdin);
    freopen("output.ans","w",stdout);
    string a,b;
    clock_t start,finish;
    start=clock();
    // while(cin>>a>>b){
    	cin>>a>>b;
        string tmp,ans;
        ans="0";
        int n=a.length(),m=b.length();
        for(int i=n-1;i>=0;i--){
            tmp=mul(b,a[i]-'0',n-1-i);
            ans=add(ans,tmp);           //竖式相加操作
        }
        cout<<ans<<endl;
        finish=clock();
        printf("%f\n",(double)(finish-start)/CLOCKS_PER_SEC);
    // }
    return 0;
}