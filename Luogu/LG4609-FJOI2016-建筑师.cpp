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

#define int ll

const int MOD=1e9+7,MAXN=50000+10,MAXM=200+10,N=50000;

int s[MAXN][MAXM],fac[MAXN],inv[MAXN];

int qpow(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1) ans=ans*a%MOD;
		a=a*a%MOD;
		b>>=1;
	}
	return ans;
}

int C(int n,int m) {return fac[n]*inv[m]%MOD*inv[n-m]%MOD;}

signed main() {
	fac[0]=1;
	REP(i,1,N) fac[i]=fac[i-1]*i%MOD;
	inv[N]=qpow(fac[N],MOD-2);
	DREP(i,N-1,0) inv[i]=(i+1)*inv[i+1]%MOD;
	s[0][0]=1;
	REP(i,1,N) REP(j,1,200) 
		s[i][j]=(s[i-1][j-1]+s[i-1][j]*(i-1)%MOD)%MOD;
	int t=read();

	while(t--) {
		int n=read(),a=read(),b=read();
		printf("%lld\n",s[n-1][a+b-2]*C(a+b-2,a-1)%MOD);
	}
	return 0;
}

