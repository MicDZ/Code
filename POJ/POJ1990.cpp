#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define lowbit(x) (x&(-x))
#define ll long long

ll read() {
	ll x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const ll MAXN=20000+10;

struct cow {
	ll v,x;
}a[MAXN];

bool cmp(cow x,cow y) {
	return x.v<y.v;
}

ll n,c[MAXN][2];

void update(ll x,ll v,ll k) {
	while(x<=20005) {
		c[x][k]+=v;
		x+=lowbit(x);
	}
}

ll ask(ll x,ll k) {
	ll ans=0;
	while(x) {
		ans+=c[x][k];
		x-=lowbit(x);
	}
	return ans;
}

int main() {
	n=read();
	REP(i,1,n) a[i].v=read(),a[i].x=read();
	sort(a+1,a+1+n,cmp);
	
	ll ans=0,all=0;

	REP(i,1,n) {
		ll tot=ask(a[i].x,0),sum=ask(a[i].x,1);
		ans+=(all-sum-(i-1-tot)*a[i].x+tot*a[i].x-sum)*a[i].v;
		update(a[i].x,1,0);
		update(a[i].x,a[i].x,1);
		all+=a[i].x;
	}

	printf("%lld\n",ans);
	return 0;
}

