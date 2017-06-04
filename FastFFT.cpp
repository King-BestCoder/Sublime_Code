#include<cstdio>
#include<cmath>
#include<cstring>
char s1[100010],s2[100010];
const double pi=acos(-1);
struct C{
	double a,b;
	C(double _a=0,double _b=0):a(_a),b(_b){}
	C operator+(C x){return C(a+x.a,b+x.b);}
	C operator-(C x){return C(a-x.a,b-x.b);}
	C operator*(C x){return C(a*x.a-b*x.b,a*x.b+b*x.a);}
}a[262144],b[262144],A,B;
int P,N;
int r[262144],v[262144];
void dft(C*a,int t){
	for(int i=0;i<N;i++)if(i>r[i]){A=a[i];a[i]=a[r[i]];a[r[i]]=A;}
	for(int i=1;i<N;i<<=1){
		C w(cos(pi/i),sin(pi/i)*t);
		for(int j=0;j<N;j+=i<<1){
			C e(1),*b=a+j,*c=b+i;
			for(int k=0;k<i;k++,e=e*w){
				A=b[k];B=c[k]*e;
				b[k]=A+B;c[k]=A-B;
			}
		}
	}
	if(t==-1)for(int i=0;i<N;i++)a[i].a/=N;
}
int main(){
	scanf("%s%s",s1,s2);
	int l1=strlen(s1)-1,l2=strlen(s2)-1;
	for(P=0,N=2;N<l1+l2+10;++P,N<<=1);
	for(int i=1;i<N;i++)r[i]=r[i>>1]>>1|(i&1)<<P;
	for(int i=0;i<=l1;i++)a[i]=C(s1[l1-i]-'0');
	for(int i=0;i<=l2;i++)b[i]=C(s2[l2-i]-'0');
	dft(a,1);dft(b,1);
	for(int i=0;i<N;i++)a[i]=a[i]*b[i];
	dft(a,-1);
	for(int i=0;i<N;i++)v[i]=int(a[i].a+0.5);
	for(int i=1;i<N;i++)v[i]+=v[i-1]/10,v[i-1]%=10;
	while(N>0&&!v[N])--N;
	while(~N)putchar(v[N--]+'0');
	return 0;
}