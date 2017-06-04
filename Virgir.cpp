#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
#define MINCHAR 97
#define CHARSUM 26
char table[CHARSUM][CHARSUM];
bool Init();
bool Encode(char* key, char* source, char* dest);
bool Dncode(char* key, char* source, char* dest);

int main()
{
	// printf("%d %d\n",'a','A');
    if(!Init()){
        return 1;
    }
    char key[256];
    char str1[256];
    char str2[256];
    memset(key,0,sizeof(key));
    memset(str1,0,sizeof(str1));
    memset(str2,0,sizeof(str2));
    while(cin>>str1>>key){
    	Encode(key,str1,str2);
    	cout<<str2<<endl;
    	memset(key,0,sizeof(key));
    	memset(str1,0,sizeof(str1));
    	memset(str2,0,sizeof(str2));
    }
    return 0;
}
// 初始化维吉尼亚方阵
bool Init()
{
    int i, j;
    for(i = 0; i < CHARSUM; i++)
    {
        for(j = 0; j < CHARSUM; j++)
        {
            table[i][j] = MINCHAR + (i + j) % CHARSUM;
        }
    }
    return true;
}
// 加密
// key：密钥
// source：待加密的字符串
// dest：经过加密后的字符串
bool Encode(char* key, char* source, char* dest)
{
    char* tempSource = source;
    char* tempKey = key;
    char* tempDest = dest;
    do
    {
        *tempDest = table[(*tempKey) - MINCHAR][(*tempSource) - MINCHAR];
        tempDest++;
        if(!(*(++tempKey)))
            tempKey = key;
    }
    while(*tempSource++);
    dest[strlen(source)] = 0;
    return true;
}
// 解密
// key：密钥
// source：待解密的字符串
// dest：经过解密后的字符串
bool Dncode(char* key, char* source, char* dest)
{
    char* tempSource = source;
    char* tempKey = key;
    char* tempDest = dest;
    char offset;
    do
    {
        offset = (*tempSource) - (*tempKey);
        offset = offset >= 0 ? offset : offset + CHARSUM;
        *tempDest = MINCHAR + offset;
        tempDest++;
        if(!(*(++tempKey)))
            tempKey = key;
    }
    while(*++tempSource);
    dest[strlen(source)] = 0;
    return true;
}
