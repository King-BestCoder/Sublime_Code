#include <bits/stdc++.h>
using namespace std;
const int maxn=1000005;
class HashTable {
private:
    string *elem;
    int size;
public:
    HashTable() {
        size = maxn;
        elem = new string[size];
        for (int i = 0; i < size; i++) {
            elem[i] = "#";
        }
    }
    ~HashTable() {
        delete[] elem;
    }
    //关键字key的选取
    int hash(const string& index) {
        int code = 0;
        for (int i = 0; i < index.length(); i++) {  //此哈希函数无固定要求,可以有多种生成方法
            code = (code * 256 + index[i]-'a') % size;
        }
        return code;
    }
	//哈希表的查找操作
    bool search(const string& index, int& pos, int& times) {
        pos = hash(index);    //获取哈希地址
        times = 0;
        while (elem[pos] != "#" && elem[pos] != index) {    //发生冲突
            times++;
            if (times < size) {
                pos = (pos + 1) % size;   //哈希表的开放地址法的线性探测法,解决冲突的一种方法
            } else {
                return false;
            }
        }
        if (elem[pos] == index) {
            return true;
        } else {
            return false;
        }
    }
	//哈希表元素的插入操作
    int insert(string& index) {
        int pos, times;
        if (search(index, pos, times)) {
            return 2;     //表示已经存在
        } else if (times < size / 2) {
            elem[pos] = index;
            // cout<<"insert"<<"     "<<index<<endl;
            return 1;   //表示插入成功
        } else {
            //recreate();
            return 0;  //表示插入失败
        }
    }

    string changemin(string& index ){
    	string word;
        for(int i=0; i < index.length(); i++ ){
            if( index[i]>='A' && index[i]<='Z' ){
                index[i]+=32;
                word+=index[i];
            }
            else if(index[i]>='a'&&index[i]<='z')
            	word+=index[i];
            else{
            	break;
            }
        }
        return word;
    }
    void print(){
    	sort(elem,elem+maxn);
    	for(int i=0;i<maxn;i++){
    		if(elem[i]!="#") cout<<i<<"    "elem[i]<<endl;
    	}
    }
};

string line,word;
int main(int argc, char const *argv[])
{
	// freopen("paper.txt","r",stdin);
	// freopen("words.txt","w",stdout);
	HashTable hashmap;
	while(getline(cin,line)){
		stringstream sin(line);
		while(sin>>word){
			word=hashmap.changemin(word);
			hashmap.insert(word);
		}
	}
	printf("%.2f\n",(double)clock()/CLOCKS_PER_SEC);
	hashmap.print();
	return 0;
}