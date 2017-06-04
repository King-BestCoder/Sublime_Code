#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <set>
#include <time.h>
#include <algorithm>
using namespace std;
const int maxn=2005;
const int max_size=128;
const int mod=195709;
#define len 20
#define filenum 101710
const int base='A';
int flag=0;
char word_s[60][len];
int num[200000];
int dou[200000];
struct trie{
    int ch[maxn][max_size];
    int val[maxn];
    int tot;
    trie(){
        tot=1;
        memset(ch[0],0,sizeof(ch[0]));
        memset(val,0,sizeof(val));
    }
    int idx(char c){return c-'a';}
    void insert(char *str){
        flag=0;
        int u=1,n=strlen(str);
        for(int i=0;i<n;i++){
            int c=str[i];
            if(!ch[u][c]){
                tot++;
                memset(ch[tot],0,sizeof(ch[tot]));
                val[tot]=0;
                ch[u][c]=tot;
            }
            u=ch[u][c];
        }
        val[u]++;
    }
    bool sub_str(char *str){
        int u=1,n=strlen(str);
        for(int i=0;i<n&&u;i++){
            int c=str[i];
            u=ch[u][c];
        }
        if(val[u]==1&&u) return true;
        else return false;
    }
};
int Hash(char *str){
    int ans=0;
    for(int i=0;i<strlen(str);i++){
        ans=(str[i]-'a'?(str[i]-'a'+26):(str[i]-'A'))+ans*2;
    }
    return ans;
}
FILE *fout;
typedef struct Vec{
    char s[filenum+10][80];
    int size;
    int namebar[2];
    Vec(){
        memset(s,0,sizeof(s));
        size=0;
    }
    void insert(char *str){
        if(size>=1&&strcmp(str,s[size-1])==0){
            return ;
        }
        int n=strlen(str);
        for(int i=0;i<n;i++){
            s[size][i]=str[i];  
        }
        size++;
    }
    void print(int ran,int i){
        for(int j=0;j<size;j++){
            fprintf(fout,"%s %d %s\n",s[j],ran+1,word_s[i]);
        }
    }
}vec;
typedef struct Node{
    int cnt,id;
}node;
node xxx[30];
vec name[30];
bool cmp(node a,node b){
    return a.cnt>b.cnt;
}
int main(int argc, char const *argv[])
{
    char s[len],str[len];
    char fname[1000],filename[25];
    memset(filename,0,sizeof(filename));
    struct trie t;
    FILE *fin;
    fin=fopen("C:\\Users\\ASUS\\Desktop\\DataWork\\Querytask1.txt","r");
    int i,n;
    int fre=0;
    while(~fscanf(fin,"%s",s)){
        n=strlen(s);
        strcpy(word_s[fre],s);
        memset(str,0,sizeof(str));
        if(num[Hash(s)]==0){
            xxx[fre].id=fre;
            xxx[fre].cnt=0;
            num[Hash(s)]=fre++;
            t.insert(s);
        }
    }
    fclose(fin);
    char tmp[80];
    for(int i=0;i<=filenum;i++){
        if(i%10000==0) printf("%d\n",i);
        sprintf(fname,"C:\\Users\\ASUS\\Desktop\\DataWork\\BigData\\processed\\processed\\report%d.xml",i);
        sprintf(filename,"report%d",i);
        fin=fopen(fname,"r");
        memset(tmp,0,sizeof(tmp));
        if(fin==NULL) printf("%d\n",i);
        while(fscanf(fin,"%s",tmp)!=EOF){
            if(t.sub_str(tmp)){
                // printf("%d\n",i);
                name[num[Hash(tmp)]].insert(filename);
                xxx[num[Hash(tmp)]].cnt++;
            }
        }
        fclose(fin);
    }
    sort(xxx,xxx+10,cmp);
    for(int i=0;i<10;i++){
        printf("%d %d\n",xxx[i].cnt,xxx[i].id);
    }
    fout=fopen("task3_10152130155.txt","w");
    for(int i=0;i<10;i++){
        printf("%d\n",xxx[i].id);
        name[xxx[i].id].print(i,xxx[i].id);
    }
    printf("%.2f\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}