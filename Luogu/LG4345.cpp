#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define ll long long
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)

ll read() {
	ll x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=2333+10,MOD=2333;

int c[MAXN][MAXN],f[MAXN][MAXN],fac[MAXN],inv[MAXN];


ll lucas(ll n,ll m) {
	if(m<MOD&&n<MOD) return c[n][m];
	return (c[n%MOD][m%MOD]*lucas(n/MOD,m/MOD))%MOD;
}

ll qpow(ll a,ll b) {
	ll ans=1;
	while(b) {
		if(b&1) ans=(ans*a)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return ans%MOD;
}

ll calc(ll n,ll k) {
	if(k<0) return 0;
	if(!n||!k) return 1;
	if(n<MOD&&k<MOD) return f[n][k];

	return (calc(n/MOD,k/MOD-1)*f[n%MOD][MOD-1]%MOD+lucas(n/MOD,k/MOD)*f[n%MOD][k%MOD]%MOD)%MOD;
}

int main() {
	//file("saber");
	ll t=read();
	c[0][0]=1;
	REP(i,1,MAXN) c[i][i]=c[i][0]=1;

	REP(i,1,MAXN) REP(j,1,i-1) c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
	
	f[0][0]=1;

	REP(i,1,MAXN) f[i][0]=1;

	REP(i,0,MAXN) REP(j,1,MAXN) f[i][j]=(c[i][j]+f[i][j-1])%MOD;

	while(t--) {
		ll n=read(),k=read();

		printf("%d\n",calc(n,k));
	}

	return 0;
}
