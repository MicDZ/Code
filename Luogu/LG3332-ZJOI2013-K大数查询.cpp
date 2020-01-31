#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

#define REP(i,e,s) for(register int i=(e); i<=(s); i++)
#define DREP(i,e,s) for(register int i=(e); i>=(s); i--)
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define ll long long

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
#define int ll
const ll MAXN=200000+10;
struct SegmentTree {
	int lf[MAXN<<2],rg[MAXN<<2];
	ll sum[MAXN<<2],add[MAXN<<2],a[MAXN];
#define l(x) lf[x]
#define r(x) rg[x]
#define sum(x) sum[x]
#define add(x) add[x]
#define len(x) (rg[x]-lf[x]+1)
	void pushup(int p) {
		sum(p)=(sum(p*2)+sum(p*2+1));
	}
	void pushdown(int p) {
		if(add(p)) {
			add(p*2)=(add(p)+add(p*2));
			add(p*2+1)=(add(p)+add(p*2+1));
			sum(p*2)=(add(p)*1ll*len(p*2)+sum(p*2));
			sum(p*2+1)=(add(p)*1ll*len(p*2+1)+sum(p*2+1));
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
			sum(p)=(sum(p)+1ll*d*len(p));
			add(p)=(add(p)+d);
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
		if(l<=mid) ans=(ans+ask(p*2,l,r));
		if(r>mid) ans=(ans+ask(p*2+1,l,r));
		return ans;
	}
} s;

struct query {
	int op,l,r,c,id;
} q[MAXN],p[2][MAXN];

int n,m,tot,ans[MAXN];

void solve(int l,int r,int ql,int qr) {
	if(ql>qr||l>r) return ;
	if(l==r){
		REP(i,ql,qr) if(q[i].op==2) ans[q[i].id]=l;
		return ;
	}
	int mid=(l+r)>>1;
	int cnt[2]={0,0};
	REP(i,ql,qr) {
		if(q[i].op==1) {
			if(q[i].c>mid) {
				s.change(1,q[i].l,q[i].r,1);
				p[0][++cnt[0]]=q[i];
			}
			else p[1][++cnt[1]]=q[i];
		}
		else {
			int temp=s.ask(1,q[i].l,q[i].r);
			if(temp>=q[i].c) p[0][++cnt[0]]=q[i];
			else {
				q[i].c-=temp;
				p[1][++cnt[1]]=q[i];
			}
		}
	}
	REP(i,1,cnt[0]) if(p[0][i].op==1&&p[0][i].c>mid) s.change(1,p[0][i].l,p[0][i].r,-1);
	REP(i,ql,ql+cnt[0]-1) q[i]=p[0][i-ql+1];
	REP(i,ql+cnt[0],qr) q[i]=p[1][i-ql-cnt[0]+1];
	solve(mid+1,r,ql,ql+cnt[0]-1);
	solve(l,mid,ql+cnt[0],qr);
}

signed main() {
file("data");
	n=read(),m=read(),tot=0;
	s.build(1,1,n);
	REP(i,1,m) {
		int op=read(),l=read(),r=read(),c=read();
		q[i]=(query){op,l,r,c,tot=tot+(op==2)};
	}

	solve(-n,n,1,m);

	REP(i,1,tot) printf("%lld\n",ans[i]);
	return 0;
}

