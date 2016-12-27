#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxn 1000007
#define len 100
const int mod=1e9+7;
int num[maxn][2];
typedef struct Node{
    int x,y;
    Node(int x1=0,int x2=0){
        x=x1,y=x2;
    }
}node;
char s[len],str[len];
int key1,key2;
node hash(){
    int n=strlen(str);
    node tmp;
    if(n<=3){
        for(int i=0;i<n;i++){
            tmp.x=(str[i]>='a'?str[i]-'a'+26:str[i]-'A')%mod+tmp.x*10%mod;
            tmp.y=tmp.x;
        }
    }
    else{
        for(int i=0;i<3;i++){
            tmp.x=(str[i]>='a'?str[i]-'a'+26:str[i]-'A')%mod+tmp.x*10%mod;
        }
        for(int i=n-1;i>=n-3;i--){
            tmp.y=(str[i]>='a'?str[i]-'a'+26:str[i]-'A')%mod+tmp.y*10%mod;
        }
    }
    return tmp;
}
int main(int argc, char const *argv[])
{
    // struct trie t;
    FILE *fin;
    fin=fopen("C:\\Users\\ASUS\\Desktop\\DataWork\\query_task1.txt","r");
    int i,n,cnt;
    node tmp;
    while(fgets(s,len,fin)!=NULL){
        n=strlen(s);
        cnt=0;
        memset(str,0,sizeof(str));
        for(i=0;i<n;i++){
            if((s[i]>='a'&&s[i]<='z')||(s[i]<='Z'&&s[i]>='A')){
                str[cnt++]=s[i];
            }
            else break;
        }
        node tmp=hash();
        // printf("%d %d %d\n",strlen(str),tmp.x,tmp.y);
        num[tmp.x][tmp.y]=1;
    }
    for(int i=0;i<40;i++){
        memset(str,0,sizeof(str));
        scanf("%s",str);
        tmp=hash();
        if(num[tmp.x][tmp.y]) printf("YES\n");
        else printf("NO\n"); 
    }
    return 0;
}
