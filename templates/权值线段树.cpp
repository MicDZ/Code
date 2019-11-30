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
const int MAXN=100000+10;

struct SegmentTree {
	int lson[MAXN*31],rson[MAXN*31],a[MAXN];
	int lf[MAXN*31],rg[MAXN*31],sum[MAXN*31],add[MAXN*31],cnt;
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
	int getvl(int p,int l,int r,int rk) {
		if(l==r) return l; 
		int mid=(l+r)>>1;
		if(sum(lson[p])>=rk) return getvl(lson[p],l,mid,rk);
		else return getvl(rson[p],mid+1,r,rk-sum(lson[p]));
	}
	int getrk(int p,int l,int r,int vl) {
		if(!p) return 0;
		if(l==r) return 1;
		int mid=(l+r)>>1;
		if(vl<=mid) return getrk(lson[p],l,mid,vl);
		else return sum[lson[p]]+getrk(rson[p],mid+1,r,vl);
	}
} s;

const int N=2e9+10;

signed main() {
	file("权值线段树");
	int n=read(),rt=0;
	REP(i,1,n) {
		int op=read();
		if(op==1) {
			int x=read();
			s.change(rt,-N,N,x,x,1);
		}
		if(op==2) {
			int x=read();
			s.change(rt,-N,N,x,x,-1);
		}
		if(op==3) {
			int x=read();
			printf("%d\n",s.getrk(1,-N,N,x));
		}
		if(op==4) {
			int k=read();
			printf("%d\n",s.getvl(1,-N,N,k));
		}
		if(op==5) {
			int x=read();
			printf("%d\n",s.getvl(1,-N,N,s.ask(1,-N,x-1)));
		}
		if(op==6) {
			int x=read();
			printf("%d\n",s.getvl(1,-N,N,s.ask(1,-N,x)+1));
		}
	}
	return 0;
}


