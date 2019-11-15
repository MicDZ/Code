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

const int MAXN=1000000+10,MOD=1e9+7;
ll a[MAXN];
ll sum[MAXN],suf[MAXN];

ll qpow(ll a,ll b) {
	ll ans=1;
	while(b) {
		if(b&1) ans=ans*a%MOD;
		b>>=1;
		a=a*a%MOD;
	}
	return ans;
}

int main() {
	int n=read();
	REP(i,1,n) a[i]=read()%MOD;
	sort(a+1,a+1+n);
	REP(i,1,n) sum[i]=(sum[i-1]+a[i])%MOD;
	DREP(i,n,1) suf[i]=(suf[i+1]+a[i])%MOD;
	
	ll ans=0;
	REP(i,2,n) {
		ans=(ans+qpow(2,i-2)*(suf[n-i+2]-sum[i-1]+MOD))%MOD;
	}

	printf("%lld\n",ans);
	return 0;
}

