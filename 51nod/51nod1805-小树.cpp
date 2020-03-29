#include<iostream>
#include<cstdio>
#include<cstring>
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a)	freopen(a".in","r",stdin);freopen(a".out","w",stdout)
using namespace std;
#define ll long long
const int MOD=1e9+7,N=1e6,MAXN=1e6+10;
#define int ll
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int qpow(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1) ans=1ll*ans*a%MOD;
		a=1ll*a*a%MOD;
		b>>=1;
	}
	return ans;
}

int fac[MAXN],inv[MAXN];

int C(int n,int m) {return 1ll*fac[n]*inv[m]%MOD*inv[n-m]%MOD;}

signed main() {
	int n=read(),m=read();
	fac[0]=1;
	REP(i,1,N) fac[i]=fac[i-1]*i%MOD;
	REP(i,0,N) inv[i]=qpow(fac[i],MOD-2);
	if(n==1||n==2) puts("1");
	else {
		ll ans=0;
		int tmp=n-m;
		DREP(i,tmp,1) {
			if((i&1)==(tmp&1)) ans=(ans+1ll*qpow(i,n-2)*C(tmp,i))%MOD;
			else ans=(ans+MOD-1ll*qpow(i,n-2)*C(tmp,i)%MOD);
		}
		ans=ans*C(n,m)%MOD;

		printf("%lld\n",ans);
	}
	return 0;
}

