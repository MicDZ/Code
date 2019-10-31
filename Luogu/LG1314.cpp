#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define ll long long
ll read() {
	ll x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const ll MAXN=2000000+10,INF=0x3f3f3f3f3f;

ll su,n,m,s,sum[2][MAXN],w[MAXN],v[MAXN],l[MAXN],r[MAXN];

bool check(ll W) {
	memset(sum,0,sizeof(sum));
	//REP(i,1,n) sum[0][i]=sum[0][i-1]+1,sum[1][i]=sum[1][i-1]+v[i];
	
	REP(i,1,n) {
		if(w[i]>W) sum[0][i]=sum[0][i-1]+1,sum[1][i]=sum[1][i-1]+v[i];
		else sum[0][i]=sum[0][i-1],sum[1][i]=sum[1][i-1];
	}
	ll Y=0;
	REP(i,1,m) {
		Y+=(sum[0][r[i]]-sum[0][l[i]-1])*(sum[1][r[i]]-sum[1][l[i]-1]);
	}
	
	su=abs(Y-s);
	return Y<=s;
}	

int main() {
	n=read(),m=read(),s=read();
	ll maxx=0;
	REP(i,1,n) w[i]=read(),maxx=max(w[i],maxx),v[i]=read();
	REP(i,1,m) l[i]=read(),r[i]=read();
	ll l=1,r=maxx+1;
	ll ans=INF;
	while(l<r) {
		ll mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
		ans=min(ans,su);
	}

	printf("%lld\n",ans);
	return 0;
}
