#include <bits/stdc++.h>

using namespace std;

typedef struct Complex{//定义虚数
    double x,y;
    Complex(double x1=0.0,double y1=0.0):x(x1),y(y1){};
    Complex operator + (const Complex &a)const {
        return Complex(x+a.x,y+a.y);
    }
    Complex operator - (const Complex &a)const {
        return Complex(x-a.x,y-a.y);
    }
    Complex operator * (const Complex &a)const {
        return Complex(x*a.x-y*a.y,x*a.y+y*a.x);
    }
}node;

const int maxn=250005;
const double pi=acos(-1.0);
char str1[maxn>>1],str2[maxn>>1];
node x1[maxn],x2[maxn];
int sum[maxn];

void Swap(node &a,node &b){
    node tmp=a;
    a=b;
    b=tmp;
}

int prepare(){//准备工作，返回值为补齐的长度
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int len = 1;
    while(len < len1*2 || len < len2*2)
        len<<=1;
    for(int i = 0;i < len1;i++)
      x1[i] = Complex(str1[len1-1-i]-'0',0);
    for(int i = len1;i < len;i++)
      x1[i] = Complex(0,0);
    for(int i = 0;i < len2;i++)
      x2[i] = Complex(str2[len2-1-i]-'0',0);
    for(int i = len2;i < len;i++)
      x2[i] = Complex(0,0);
    return len;
}

//雷德算法，将位置调整一下使得之后可以直接线性地处理这个数列
void rader(node *y,int len){
    for(int i=1,j=len>>1;i<len-1;i++){
        if(i<j) Swap(y[i],y[j]);
        int k=len>>1;
        while(j>=k){
            j-=k;
            k>>=1;
        }
        if(j<k) j+=k;
    }
}

void fft(node *x,int len,int op){
    rader(x,len);
    for(int h=2;h<=len;h<<=1){
        node Wn(cos(-op*2*pi/h),sin(-op*2*pi/h));
        for(int i=0;i<len;i+=h){
            node W(1,0);

            for(int j=i;j<i+h/2;j++){
                node u=x[j];
                node t=W*x[j+h/2];
                x[j]=u+t;
                x[j+h/2]=u-t;
                W=W*Wn;
            }
        }
    }
    if(op==-1){
        for(int i=0;i<len;i++)
            x[i].x/=len;
    }
}

int main()
{
//    freopen("data.in","r",stdin);
//    freopen("output.ans","w",stdout);
    while(~scanf("%s %s",str1,str2)){
//        printf("%s\n%s\n",str1,str2);
        int len1=strlen(str1),len2=strlen(str2);
        int len=prepare();
        fft(x1,len,1);
        fft(x2,len,1);
        for(int i=0;i<len;i++)
            x1[i]=x1[i]*x2[i];
        fft(x1,len,-1);
        for(int i=0;i<len;i++){
            sum[i]=(int)(x1[i].x+0.5);
        }
        for(int i=0;i<len;i++){
            sum[i+1]+=sum[i]/10;
            sum[i]=sum[i]%10;
        }
        len=len1+len2-1;
        while(sum[len]<=0&&len>0)
            len--;
        for(int i=len;i>=0;i--)
            printf("%c",sum[i]+'0');
        printf("\n");
    }
    return 0;
}
