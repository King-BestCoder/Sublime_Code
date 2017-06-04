#include <bits/stdc++.h>
using namespace std;
const int maxn=1015;
int num[maxn];

int main(int argc, char const *argv[])
{
	string s;
	int n;
	memset(num,0,sizeof(num));
	cin>>n;
	getchar();
	int flag=0;
	for(int i=0;i<n;i++){
		getline(cin,s);
		stringstream sin(s);
		string str;
		while(sin>>str){
			if(str=="X") continue;
			else if(str==">="){
				flag=1;
			}
			else if(str=="<="){
				flag=2;
			}
			else if(str==">"){
				flag=3;
			}
			else if(str=="<"){
				flag=4;
			}
			else if(str=="="){
				flag=5;
			}
			else{
				int temp=0;
				for(int j=0;j<str.length();j++){
					temp=temp*10+(str[j]-'0');
				}
				if(flag==1){
					for(int j=temp;j<maxn;j++)
						num[j]++;
				}
				else if(flag==2){
					for(int j=temp;j>=0;j--)
						num[j]++;
				}
				else if(flag==3){
					for(int j=temp+1;j<maxn;j++)
						num[j]++;
				}
				else if(flag==4){
					for(int j=temp-1;j>=0;j--){
						num[j]++;
					}
				}
				else if(flag==5){
					num[temp]++;
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<1001;i++)
		ans=max(ans,num[i]);
	cout<<ans<<endl;
	return 0;
}