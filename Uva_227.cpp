#include <bits/stdc++.h>
using namespace std;
const int maxn=6;
char s[maxn][maxn];
char str[100];
int main(int argc, char const *argv[])
{
	int cas=0;
	while(true){
		int flag=0;
		memset(s,0,sizeof(s));
		for(int i=1;i<=5;i++){
			scanf("%s",s[i]+1);
			if(strlen(s[i]+1)<5){
				s[i][strlen(s[i]+1)+1]=' ';
				if(strlen(s[i]+1)+1<5){
					scanf("%s",s[i]+strlen(s[i]+1)+1);
				}
			}
			if(s[1][1]=='Z'){
				flag=1;
				break;
			}
		}
		if(flag) break;
		// for(int i=1;i<=5;i++)
		// 	printf("%s\n",s[i]+1);
		int tx,ty;
		for(tx=1;tx<=5;tx++){
			int tmp=0;
			for(ty=1;ty<=5;ty++){
				if(!isalpha(s[tx][ty])) {
					// printf("%d %d\n",tx,ty);
					tmp=1;
					break;
				}
			}
			if(tmp) break;
		}
		// printf("%d %d\n",tx,ty);
		int ans=0;
		char t;
		while(true){
			t=getchar();
			if(t=='0') break;
			if(t=='\n') continue;
			// printf("*******\n");
			// for(int i=1;i<=5;i++)
			// 	printf("%s\n",s[i]+1);
			// printf("%d %d\n",tx,ty);
			if(t=='A'){
				if(tx-1>=1){
					s[tx][ty]=s[tx-1][ty];
					tx--;
					s[tx][ty]=' ';
				}
				else{
					ans=1;
				}
			}
			else if(t=='B'){
				if(tx+1<=5){
					s[tx][ty]=s[tx+1][ty];
					tx++;
					s[tx][ty]=' ';
				}
				else {
					ans=1;
				} 
			}
			else if(t=='L'){
				if(ty-1>=1){
					s[tx][ty]=s[tx][ty-1];
					ty--;
					s[tx][ty]=' ';
				}
				else{
					ans=1;
				}
			}
			else if(t=='R'){
				if(ty+1<=5){
					s[tx][ty]=s[tx][ty+1];
					ty++;
					s[tx][ty]=' ';
				}
				else{
					ans=1;
				}
			}
		}
		// getchar();
		if(cas++) printf("\n");
		printf("Puzzle #%d:\n",cas);
		if(!ans){
			for(int i=1;i<=5;i++)
				for(int j=1;j<=5;j++){
					if(j==5)  printf("%c\n",s[i][j]);
					else printf("%c ",s[i][j]);
				}
		}
		else{
			printf("This puzzle has no final configuration.\n");
		}
		// for(int i=1;i<=5;i++)
		// 	printf("%s\n",s[i]+1);
	}
	return 0;
}
/*
ABCDE
FGHIJ
KLMNO
PQRS
TUVWX
AAA
LLLL0
*/