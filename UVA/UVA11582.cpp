#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define ll unsigned long long
ll read() {
	ll x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll qpow(ll a,ll b,ll p) {
	ll ans=1;
	while(b) {
		if(b&1) ans=ans*a%p;
		a=a*a%p;
		b>>=1;
	}
	return ans%p;
}

ll f[10000+10][10000+10],start[10000+10];

signed main() {
	REP(i,2,1000) {
		f[i][0]=0;f[i][1]=1;
		ll cnt=2;
		while(1) {
			
			f[i][cnt]=(f[i][cnt-1]+f[i][cnt-2])%i;
			if(f[i][cnt-1]==0&&f[i][cnt]==1) {
				start[i]=cnt-1;
				break;
			}
			cnt++;
		}
	}
	ll t=read();
	while(t--) {
		ll a=read(),b=read(),n=read();
		ll ans;//puts("in");
		if(a==0||n==1) ans=0;
		
		else ans=f[n][qpow(a%start[n],b,start[n])];

		printf("%lld\n",ans);
	}
	return 0;
}
