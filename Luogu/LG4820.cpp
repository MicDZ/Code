#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define DE(...) fprintf(stderr,__VA_ARGS__);
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define ll long long

ll read() {
	ll x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int INF=0x3f3f3f;

void print(double a) {
	if(ceil(a)==a) printf("%d\n",(int)(a-1));
	else printf("%d\n",(int)a);

}
int main() {
	ll n=read(),m=read();
	double ans=0;
	if(n>10000000) ans=log(n)+0.5772156649;
	else {
		REP(i,1,n) ans+=1.0/i;
	}
	
	printf("%d\n",(int)(ans*m/2-0.0000000001));
	return 0;
}

