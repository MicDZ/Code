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

const ll MAXN=100000+10,MOD=0x3f3f3f3f3f3f3f3f;
struct SegmentTree {
	int lf[MAXN<<2],rg[MAXN<<2];
	ll sum[MAXN<<2],add[MAXN<<2],a[MAXN];
#define l(x) lf[x]
#define r(x) rg[x]
#define sum(x) sum[x]
#define add(x) add[x]
#define len(x) (rg[x]-lf[x]+1)
	void pushup(int p) {
		sum(p)=(sum(p*2)+sum(p*2+1))%MOD;
	}
	void pushdown(int p) {
		if(add(p)) {
			add(p*2)=(add(p)+add(p*2))%MOD;
			add(p*2+1)=(add(p)+add(p*2+1))%MOD;
			sum(p*2)=(add(p)*1ll*len(p*2)+sum(p*2))%MOD;
			sum(p*2+1)=(add(p)*1ll*len(p*2+1)+sum(p*2+1))%MOD;
			add(p)=0;
		}
	}
	void build(int p,int l,int r) {
		l(p)=l,r(p)=r;
		if(l==r) {sum(p)=a[l];return ;}
		int mid=(l+r)>>1;
		build(p*2,l,mid);
		build(p*2+1,mid+1,r);
		pushup(p);
	}
	void change(int p,int l,int r,ll d) {
		if(l(p)>=l&&r(p)<=r) {
			sum(p)=(sum(p)+1ll*d*len(p))%MOD;
			add(p)=(add(p)+d)%MOD;
			return ;
		}
		pushdown(p);
		int mid=(l(p)+r(p))>>1;
		if(l<=mid) change(p*2,l,r,d);
		if(r>mid) change(p*2+1,l,r,d);	
		pushup(p);
	}
	ll ask(int p,int l,int r) {
		if(l(p)>=l&&r(p)<=r) {return sum(p);}
		ll ans=0;
		pushdown(p);
		int mid=(l(p)+r(p))>>1;
		if(l<=mid) ans=(ans+ask(p*2,l,r))%MOD;
		if(r>mid) ans=(ans+ask(p*2+1,l,r))%MOD;
		return ans;
	}
} s;

int main() {
	file("data");
	int n=read(),m=read();
	REP(i,1,n) s.a[i]=read();
	s.build(1,1,n);
	REP(i,1,m) {
		int op=read();
		if(op==1) {
			int x=read(),y=read();
			ll k=read();
			s.change(1,x,y,k);
		}
		if(op==2) {
			int x=read(),y=read();
			printf("%lld\n",s.ask(1,x,y));
		}
	}
	return 0;
}

