#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#define MAX 60
#define len 100
using namespace std;
 
typedef struct TrieNode                     //Trie结点声明 
{
    bool isStr;                            //标记该结点处是否构成单词 
    struct TrieNode *next[MAX];            //儿子分支 
}Trie;
int tmp;
void insert(Trie *root,const char *s)     //将单词s插入到字典树中 
{
    if(root==NULL||*s=='\0')
        return;
    int i;
    Trie *p=root;
    while(*s!='\0')
    {
        tmp=*s>='a'?(*s-'a'):(*s-'A'+26);
        if(p->next[tmp]==NULL)        //如果不存在，则建立结点 
        {
            Trie *temp=(Trie *)malloc(sizeof(Trie));
            for(i=0;i<MAX;i++)
            {
                temp->next[i]=NULL;
            }
            temp->isStr=false;
            p->next[tmp]=temp;
            p=p->next[tmp];   
        }   
        else
        {
            p=p->next[tmp];
        }
        s++;
    }
    p->isStr=true;                       //单词结束的地方标记此处可以构成一个单词 
}
 
int search(Trie *root,const char *s)  //查找某个单词是否已经存在 
{
    Trie *p=root;
    while(p!=NULL&&*s!='\0')
    {
        tmp=*s>='a'?(*s-'a'):(*s-'A'+26);
        p=p->next[tmp];
        s++;
    }
    return (p!=NULL&&p->isStr==true);      //在单词结束处的标记为true时，单词才存在 
}
 
void del(Trie *root)                      //释放整个字典树占的堆区空间 
{
    int i;
    for(i=0;i<MAX;i++)
    {
        if(root->next[i]!=NULL)
        {
            del(root->next[i]);
        }
    }
    free(root);
}
 
int main(int argc, char *argv[])
{
    Trie *root= (Trie *)malloc(sizeof(Trie));
    char s[len],str[len];
    // struct trie t;
    FILE *fin;
    fin=fopen("C:\\Users\\ASUS\\Desktop\\DataWork\\query_task1.txt","r");
    int i,n;
    while(fgets(s,len,fin)!=NULL){
        n=strlen(s);
        memset(str,0,sizeof(str));
        for(i=0;i<n&&s[i]!='\n';i++){
            str[i]=s[i];
        }
        printf("%s\n",str);
        insert(root,str);
    }
    printf("*******\n");
    for(int i=0;i<40;i++){
        memset(str,0,sizeof(str));
        scanf("%s",str);
        // printf("%s\n",str);
        if(search(root,str)) printf("YES\n");
        else printf("NO\n");
    }
    del(root);                         //释放空间很重要 
    return 0;
}