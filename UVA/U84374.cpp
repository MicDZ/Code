#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;
#define ll long long
#define REP(i,e,s) for(register ll i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)


ll read() {
	ll x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int INF=0x3f3f3f,MAXN=3000000+10;

int a[MAXN];

int main() {
    ll n=read(),k=read();
    REP(i,1,n) a[i]=read();
    k=k%n;
    REP(i,1,n) {
        if(k>n) k=1;
        if(k==0) k=n;
        printf("%d ",a[k]);
        k++;
    }
	return 0;
}