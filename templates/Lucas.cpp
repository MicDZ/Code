#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;
#define int ll
#define REP(i,e,s) for(register int i=(e); i<=(s); i++)
#define DREP(i,e,s) for(register int i=(e); i>=(s); i--)
#define ll long long
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,p;

const int MAXN=100000+10,N=100000;

int fac[MAXN],inv[MAXN];

int qpow(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1) ans=ans*a%p;
		a=a*a%p;
		b>>=1;
	}
	return ans;
}

int C(int n,int m) {
	if(n<m) return 0;
	return fac[n]*inv[m]%p*inv[n-m]%p;
}

int lucas(int n,int m) {
	if(n<p&&m<p) return C(n,m);
	return C(n%p,m%p)*lucas(n/p,m/p)%p;
}

signed main() {
	int t=read();

	while(t--) {
		n=read(),m=read(),p=read();
		fac[0]=1;
		REP(i,1,p-1) fac[i]=fac[i-1]*i%p;
		inv[p-1]=qpow(fac[p-1],p-2);
		
		DREP(i,p-1-1,0) inv[i]=inv[i+1]*(i+1)%p;
			
		printf("%lld\n",lucas(n+m,m));
	}
	return 0;
}

