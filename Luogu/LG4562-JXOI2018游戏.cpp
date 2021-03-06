#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;
#define int ll
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
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

const int MOD=1e9+7,MAXN=1e7+10;

int vis[MAXN],num,fac[MAXN],inv[MAXN];

int qpow(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1) ans=ans*a%MOD;
		a=a*a%MOD;
		b>>=1;
	}
	return ans;
}

int c(int n,int m) {
	if(n<m) return 0;
	return fac[n]*inv[m]%MOD*inv[n-m]%MOD;
}

signed main() {
	int l=read(),r=read(),n=r-l+1;
	REP(i,l,r) {
		if(vis[i]) continue;
		num++;
		for(int j=i+i; j<=r; j+=i) vis[j]=1;
	}
	
	fac[0]=fac[1]=1;
	REP(i,2,n) fac[i]=fac[i-1]*i%MOD;

	inv[n]=qpow(fac[n],MOD-2);
	DREP(i,n-1,0) inv[i]=inv[i+1]*(i+1)%MOD;

	int ans=0;
	
	REP(i,1,n) ans=(ans+i*fac[i-1]%MOD*num%MOD*c(n-num,n-i)%MOD*fac[n-i]%MOD)%MOD;
	printf("%lld\n",ans);

	return 0;
}
