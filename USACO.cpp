/*
ID: chenyue4
PROG: ride
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const int mod=47;

int main() 
{
	freopen("ride.in","r",stdin);
	freopen("ride.out","w",stdout);
    int ans1=1,ans2=1;
    string a,b;
    cin>>a>>b;
    for(int i=0;i<a.length();i++){
    	ans1*=(a[i]-'A'+1);
    	ans1=ans1%mod;
    }
    for(int i=0;i<b.length();i++){
    	ans2*=(b[i]-'A'+1);
    	ans2=ans2%mod;
    }
    if(ans1==ans2)
    	cout<<"GO"<<endl;
    else
    	cout<<"STAY"<<endl;
    return 0;
}