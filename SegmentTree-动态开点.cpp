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
const int MAXN=100000+10;

struct SegmentTree {
	int lson[MAXN<<2],rson[MAXN<<2],a[MAXN];
	int lf[MAXN<<2],rg[MAXN<<2],sum[MAXN<<2],add[MAXN<<2],cnt;
#define l(x) lf[x]
#define r(x) rg[x]
#define sum(x) sum[x]
#define add(x) add[x]
#define len(x) (rg[x]-lf[x]+1)
	void pushup(int p) {
		sum(p)=sum(lson[p])+sum(rson[p]);
	}
	void pushdown(int p) {
		if(add(p)) {
			if(!lson[p]) lson[p]=++cnt;
			if(!rson[p]) rson[p]=++cnt;
			int mid=(l(p)+r(p))>>1;
			add(lson[p])=add(lson[p])+add(p);
			add(rson[p])=add(rson[p])+add(p);
			sum(lson[p])=sum(lson[p])+add(p)*(mid-l(p)+1);
			sum(rson[p])=sum(rson[p])+add(p)*(r(p)-mid);
			add(p)=0;
		}
	}
	void change(int &p,int l,int r,int L,int R,int d) {
		if(!p) p=++cnt,l(p)=l,r(p)=r;
		if(l(p)>=L&&r(p)<=R) {
			sum(p)=sum(p)+d*len(p);
			add(p)=add(p)+d;
			return ;
		}
		pushdown(p);
		int mid=(l(p)+r(p))>>1;
		if(L<=mid) change(lson[p],l,mid,L,R,d);
		if(R>mid) change(rson[p],mid+1,r,L,R,d);
		pushup(p);
	}
	int ask(int p,int l,int r) {
		if(!p) return 0;
		if(l(p)>=l&&r(p)<=r) return sum(p);
		pushdown(p);
		int mid=(l(p)+r(p))>>1;
		int ans=0;
		if(l<=mid) ans=ans+ask(lson[p],l,r);
		if(r>mid) ans=ans+ask(rson[p],l,r);
		return ans;
	}
} s;

signed main() {
	int n=read(),m=read(),rt=0;
	REP(i,1,n) {
		int x=read();
		s.change(rt,1,n,i,i,x);
	}
	
	REP(i,1,m) {
		int op=read();
		if(op==1) {
			int x=read(),y=read(),k=read();
			s.change(rt,1,n,x,y,k);
		}
		if(op==2) {
			int x=read(),y=read();
			printf("%lld\n",s.ask(1,x,y));
		}
	}
	return 0;
}

