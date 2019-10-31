#include<bits/stdc++.h>
using namespace std;
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define ll long long
ll read() {
    ll x=0,f=1,ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
const ll MAXN=6000+10,INF=0x3f3f3f3f3f3f3f3f;
ll w[MAXN],v[MAXN],l[MAXN],dp[MAXN*1000];

int main() {
	ll n=read(),m=n,t=read();
	REP(i,1,n) {
		w[i]=read();
		v[i]=read();
		l[i]=read();
	}

	REP(i,1,m) 
		DREP(j,t,w[i]) 
			REP(k,1,l[i]) if(j>=w[i]*k) dp[j]=max(dp[j],dp[j-k*w[i]]+v[i]*k);


	printf("%lld\n",dp[t]);
}


