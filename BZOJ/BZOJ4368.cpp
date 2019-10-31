#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;
#define ll long long
#define REP(i,e,s) for(register ll i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define DE(...) fprintf(stderr,__VA_ARGS__);
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)


ll read() {
	ll x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const ll INF=0x3f3f3f3f3f3f,MAXN=10000000+10;

ll p[MAXN];

ll calc(ll l,ll r,ll L) {
	return min(L,min(2*r,2*(L-l)));
}

int main() {
	ll n=read(),k=read(),l=read();
	REP(i,1,n) p[i]=read();

	ll ans=INF;

	for(ll i=1; i<=n&&i<=k; i++) {
		ll cnt=calc(p[1],p[i],l);
		for(ll j=i+1; j<=n; j+=k) cnt+=calc(p[j],p[min(j+k,n)-1],l);

		ans=min(ans,cnt);
	}

	printf("%lld\n",ans);
	return 0;
}
