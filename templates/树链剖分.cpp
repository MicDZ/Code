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

const int MAXN=500000+10;

int n,m,rt,MOD;

int val[MAXN];

struct SegmentTree {
	int a[MAXN],lf[MAXN<<2],rg[MAXN<<2];
	ll sum[MAXN<<2],add[MAXN<<2];
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
	void change(int p,int l,int r,int d) {
		if(l(p)>=l&&r(p)<=r) {
			sum(p)=(sum(p)+d*len(p))%MOD;
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

int head[MAXN],_next[MAXN<<1],to[MAXN<<1],cnt;

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

int dept[MAXN],fa[MAXN],hson[MAXN],size[MAXN];

void dfs1(int u) {
	size[u]=1;dept[u]=dept[fa[u]]+1;
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(fa[u]==v) continue;
		fa[v]=u;
		dfs1(v);
		size[u]+=size[v];
		if(!hson[u]||size[hson[u]]<size[v]) hson[u]=v;
	}
}

int top[MAXN],id[MAXN],num;

void dfs2(int u,int nowtop) {
	id[u]=++num;top[u]=nowtop;s.a[num]=val[u];
	if(hson[u]) dfs2(hson[u],nowtop);
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(fa[u]!=v&&v!=hson[u]) dfs2(v,v);
	}
}

void change(int x,int y,ll d) {
	while(top[x]!=top[y]) {
		if(dept[top[x]]<dept[top[y]]) swap(x,y);
		s.change(1,id[top[x]],id[x],d);
		x=fa[top[x]];
	}
	if(dept[x]<dept[y]) swap(x,y);
	s.change(1,id[y],id[x],d);
}

ll ask(int x,int y) {
	ll ans=0;
	while(top[x]!=top[y]) {
		if(dept[top[x]]<dept[top[y]]) swap(x,y);
		ans=(ans+s.ask(1,id[top[x]],id[x]))%MOD;
		x=fa[top[x]];
	}
	if(dept[x]<dept[y]) swap(x,y);
	ans=(ans+s.ask(1,id[y],id[x]))%MOD;
	return ans;
}

int main() {
	file("树链剖分");
	n=read(),m=read(),rt=read(),MOD=read();
	

	REP(i,1,n) val[i]=read();

	REP(i,1,n-1) {
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
	dfs1(rt);
	dfs2(rt,rt);
	s.build(1,1,n);
	

	REP(i,1,m) {
		int op=read();
 		if(op==1) {
			int x=read(),y=read(),d=read();
			change(x,y,d);
		}
		if(op==2) {
			int x=read(),y=read();
			printf("%lld\n",ask(x,y));
		}		
		if(op==3) {
			int x=read(),d=read();
			s.change(1,id[x],id[x]+size[x]-1,d);
		}
		if(op==4) {
			int x=read();
			printf("%lld\n",s.ask(1,id[x],id[x]+size[x]-1));
		}
	}
	return 0;
}
