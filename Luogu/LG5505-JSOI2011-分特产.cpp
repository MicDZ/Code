#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

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

const int MAXN=100000+10,MOD=1e9+7,N=100005;

ll a[MAXN],fac[MAXN],inv[MAXN];

ll qpow(ll a,int b) {
	ll ans=1;
	while(b) {
		if(b&1) ans=1ll*ans*a%MOD;
		a=1ll*a*a%MOD;
		b>>=1;
	}
	return ans;
}

ll C(int n,int m) {return 1ll*fac[n]*inv[m]%MOD*inv[n-m]%MOD;}

int main() {
	int n=read(),m=read();
	REP(i,1,m) a[i]=read();
	fac[0]=1;
	REP(i,1,N) fac[i]=1ll*fac[i-1]*i%MOD;
	inv[N]=qpow(fac[N],MOD-2);
	DREP(i,N-1,0) inv[i]=1ll*(i+1)*inv[i+1]%MOD;
	ll ans=0;

	REP(i,0,n) {
		ll prod=1;
		REP(j,1,m) prod=1ll*prod*C(n-i-1+a[j],n-i-1)%MOD;
		ans=(ans+1ll*C(n,i)*qpow(-1,i)%MOD*prod%MOD+MOD)%MOD;
	}

	printf("%lld\n",ans);
	return 0;
}

