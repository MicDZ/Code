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
const ll MAXN=100000+10,MOD=0x3f3f3f3f3f3f3f;

struct SegmentTree {
	int lf[MAXN<<2],rg[MAXN<<2];
	ll maxx[MAXN<<2],add[MAXN<<2],a[MAXN];
#define l(x) lf[x]
#define r(x) rg[x]
#define maxx(x) maxx[x]
#define add(x) add[x]
#define len(x) (rg[x]-lf[x]+1)
	void pushup(int p) {
		maxx(p)=max(maxx(p*2),maxx(p*2+1));
	}
	void build(int p,int l,int r) {
		l(p)=l,r(p)=r;
		if(l==r) {maxx(p)=a[l];return ;}
		int mid=(l+r)>>1;
		build(p*2,l,mid);
		build(p*2+1,mid+1,r);
		pushup(p);
	}
	ll ask(int p,int l,int r) {
		if(l(p)>=l&&r(p)<=r) {return maxx(p);}
		ll ans=0;
		int mid=(l(p)+r(p))>>1;
		if(l<=mid) ans=max(ans,ask(p*2,l,r));
		if(r>mid) ans=max(ans,ask(p*2+1,l,r));
		return ans;
	}
} s;

int pos[MAXN];

struct query {
	int l,r,id;
} q[MAXN];

bool operator< (query a,query b) {
	if(pos[a.l]==pos[b.r]) return a.r<b.r;
	return a.l<b.l;
}

int ans[MAXN];

void add(int x) {

}

int main() {
	int n=read(),m=read(),gap=sqrt(n);
	REP(i,1,n) s.a[i]=read(),pos[i]=(i-1)/gap+1;
	s.build(1,1,n);
	REP(i,1,m) q[i]=(query){read(),read(),i};
	sort(q+1,q+1+m);		
		
	return 0;
}

