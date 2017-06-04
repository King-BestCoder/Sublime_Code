#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <set>
#include <time.h>
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
        if(str[i]>='a'&&str[i]<='z'){
            ans=(ans*3+(str[i]-'a')*2)%mod;
        }
        else if(str[i]>='A'&&str[i]<='Z'){
            ans=(ans*3+(str[i]-'A')*2)%mod;
        }
        else ans=(ans+1)%mod;
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
    void print(int i,int t){
        if(t==1){
            for(int j=0;j<size;j++){
                fprintf(fout,"%s %s %s\n",s[j],word_s[i*2+1],word_s[(i+1)*2]);
            }
        }
        else{
            for(int j=0;j<size;j++){
                fprintf(fout,"%s ",s[j]);
                if(namebar[0]) fprintf(fout,"%s\n",word_s[namebar[0]]);
                else fprintf(fout,"%s\n",word_s[namebar[1]]);
            }
        }
    }
}vec;
bool has(int n,char *s1){
    for(int i=0;i<n;i++){
        if(strcmp(word_s[i],s1)==0){
            return true;
        }
    }
    return false;
}
vec simplename[30];
vec bothname[30];
int main(int argc, char const *argv[])
{
    char s1[len],s2[len];
    char fname[1000],filename[25];
    memset(filename,0,sizeof(filename));
    FILE *fin;
    fin=fopen("C:\\Users\\ASUS\\Desktop\\DataWork\\Querytask2.txt","r");
    int cnt,key;
    int linenum=10;
    // fscanf(fin,"%d",&linenum);
    cnt=1;
    struct trie t;
    for(int i=0;i<linenum;i++){
    	fscanf(fin,"%s %s",s1,s2);
        key=Hash(s1);
        if(has(cnt,s1)){
            strcpy(word_s[cnt],s1);
            dou[key]=cnt++;
        }
        else{
            strcpy(word_s[cnt],s1);
            num[key]=cnt++;
        }
        key=Hash(s2);
        if(has(cnt,s2)){
            strcpy(word_s[cnt],s2);
            dou[key]=cnt++;
        }
        else{
            strcpy(word_s[cnt],s2);
            num[key]=cnt++;
        }
        t.insert(s1);
        t.insert(s2);
    }
    fclose(fin);
    char tmp[80];
    int word[64];//1490
    for(int i=0;i<=filenum;i++){
        if(i%10000==0) printf("%d\n",i);
        sprintf(fname,"C:\\Users\\ASUS\\Desktop\\DataWork\\BigData\\processed\\processed\\report%d.xml",i);
        sprintf(filename,"report%d",i);
        fin=fopen(fname,"r");
        cnt=1;
        memset(word,0,sizeof(word));
        memset(tmp,0,sizeof(tmp));
        while(~fscanf(fin,"%s",tmp)){
            if(t.sub_str(tmp)){
                int key=Hash(tmp);
                if(key==1490&&strcmp(tmp,"heart")==0){
                    word[5]++;
                }
                else if(key==1490&&strcmp(tmp,"cough")==0){
                    word[7]++;
                }
                else{
                    if(num[key]&&dou[key]){
                        word[num[key]]++;
                        word[dou[key]]++;
                    }
                    else if(num[key]&&!dou[key]){
                        word[num[key]]++;
                    }
                }
            }
        }
        for(int j=1;j<=60;j+=2){
        	if(word[j]&&word[j+1]){
        		bothname[j/2].insert(filename);
        	}
        	else if(word[j]&&!word[j+1]){
        		simplename[j/2].insert(filename);
                simplename[j/2].namebar[0]=j;
        	}
            else if(!word[j]&&word[j+1]){
                simplename[j/2].insert(filename);
                simplename[j/2].namebar[1]=j+1;
            }
        }
        fclose(fin);
    }
    fout=fopen("task2_10152130155.txt","w");
    for(int i=0;i<30;i++){
        bothname[i].print(i,1);
        simplename[i].print(i,2);
    }
    printf("%.2f\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}
