#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
struct node{
	char name[55];
	int fenshu=0,sheng=0,shu=0;
}team[55];
bool cmp(struct node a,struct node b){
	if(a.fenshu!=b.fenshu)
		return a.fenshu>b.fenshu;
	else if((a.sheng-a.shu)!=(b.sheng-b.shu))
		return (a.sheng-a.shu)>(b.sheng-b.shu);
	else
		return a.sheng>b.sheng;
}
int main(int argc, char const *argv[])
{
	int n;
	memset(team,0,sizeof(team));
	scanf("%d",&n);
	string tmp;
	map<string,int>num;
	for(int i=0;i<n;i++){
		scanf("%s",team[i].name);
		tmp=team[i].name;
		num[tmp]=i;
	}
	getchar();
	char s[150];
	int b1,b2;
	for(int i=0;i<n*(n-1)/2;i++){
		memset(s,0,sizeof(s));
		gets(s);
		// printf("%s\n",s);
		b1=b2=0;
		int j,k,pace;
		for(j=0;j<strlen(s);j++){
			if(s[j]=='-') break;
		}
		for(pace=j+1;pace<strlen(s);pace++){
			if(s[pace]==' ') break;
		}
		for(k=pace+1;k<strlen(s);k++){
			if(s[k]==':') break;
		}
		string a,b;
		int p;
		for(p=0;p<j;p++)
			a+=s[p];
		for(p=j+1;p<pace;p++)
			b+=s[p];
		for(p=pace+1;p<k;p++)
			b1=b1*10+s[p]-'0';
		for(p=k+1;p<strlen(s);p++)
			b2=b2*10+s[p]-'0';
		int x=num[a],y=num[b];
		if(b1>b2){
			team[x].fenshu+=3,team[x].sheng+=b1,team[x].shu+=b2;
			team[y].sheng+=b2,team[y].shu+=b1;
		}
		else if(b1<b2){
			team[y].fenshu+=3,team[y].sheng+=b2,team[y].shu+=b1;
			team[x].sheng+=b1,team[x].shu+=b2;
		}
		else{
			team[x].fenshu+=1,team[y].fenshu+=1;
			team[y].sheng+=b2,team[y].shu+=b1;
			team[x].sheng+=b1,team[x].shu+=b2;
		}
		// cout<<j<<" "<<pace<<" "<<k<<endl;
		// cout<<a<<" "<<b<<" "<<b1<<" "<<b2<<endl;
	}
	sort(team,team+n,cmp);
	// for(int i=0;i<n;i++){
	// 	printf("%s %d %d %d\n",team[i].name,team[i].fenshu,team[i].sheng,team[i].shu);
	// }
	set<string>prin;
	for(int i=0;i<n/2;i++){
		tmp=team[i].name;
		prin.insert(tmp);
	}
	for (set<string>::iterator i = prin.begin(); i != prin.end(); ++i)
	{
		cout<<*i<<endl;
	}
	return 0;
}
