#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;
#define int ll
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

int a[MAXN];

struct SegmentTree {
	int lf[MAXN<<2],rg[MAXN<<2],sum[MAXN<<2],add[MAXN<<2];
	#define l(x) lf[x]
	#define r(x) rg[x]
	#define len(x) (rg[x]-lf[x]+1)
	#define sum(x) sum[x]
	#define add(x) add[x]
	void build(int p,int l,int r) {
		l(p)=l,r(p)=r;
		if(l==r) {sum(p)=a[l]; return;}
		int mid=(l+r)>>1;
		build(p*2,l,mid);
		build(p*2+1,mid+1,r);
		sum(p)=(sum(p*2)+sum(p*2+1))%MOD;
	}
	void spread(int p) {
		if(add(p)) {
			sum(p*2)=(sum(p*2)+add(p)*len(p*2))%MOD;
			sum(p*2+1)=(sum(p*2+1)+add(p)*len(p*2+1))%MOD;
			add(p*2)=(add(p*2)+add(p))%MOD;
			add(p*2+1)=(add(p*2+1)+add(p))%MOD;
			add(p)=0;
		}
	}
	void change(int p,int l,int r,int d) {
		if(l(p)>=l&&r(p)<=r) {
			sum(p)=(sum(p)+d*len(p))%MOD;
			add(p)=(add(p)+d)%MOD;
			return ;
		}
		spread(p);
		int mid=(l(p)+r(p))>>1;
		if(l<=mid) change(p*2,l,r,d);
		if(r>mid) change(p*2+1,l,r,d);
		sum(p)=(sum(p*2)+sum(p*2+1))%MOD;
	}
	int ask(int p,int l,int r) {
		if(l(p)>=l&&r(p)<=r) {return sum(p);}
		spread(p);
		int ans=0;
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

int size[MAXN],fa[MAXN],dept[MAXN],hson[MAXN];

void dfs1(int u) {
	size[u]=1,dept[u]=dept[fa[u]]+1;
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(fa[u]==v) continue;
		fa[v]=u;
		dfs1(v);
		size[u]+=size[v];
		if(!hson[u]||size[v]>size[hson[u]]) hson[u]=v;
	}
}
int val[MAXN];
int top[MAXN],id[MAXN],tot;

void dfs2(int u,int nowtop) {
	id[u]=++tot;top[u]=nowtop;
	a[tot]=val[u];
	if(hson[u]) dfs2(hson[u],nowtop);
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(fa[u]==v||v==hson[u]) continue;
		fa[v]=u;
		dfs2(v,v);	
	}
}

void change(int u,int v,int d) {
	while(top[u]!=top[v]) {
		if(dept[top[u]]<dept[top[v]]) swap(u,v);
		s.change(1,id[top[u]],id[u],d);
		u=fa[top[u]];
	}
	if(dept[u]<dept[v]) swap(u,v);
	s.change(1,id[v],id[u],d);
}
int ask(int u,int v) {
	int ans=0;
	while(top[u]!=top[v]) {
		if(dept[top[u]]<dept[top[v]]) swap(u,v);
		ans=(ans+s.ask(1,id[top[u]],id[u]))%MOD;
		u=fa[top[u]];
	}
	if(dept[u]<dept[v]) swap(u,v);
	ans=(ans+s.ask(1,id[v],id[u]))%MOD;
	return ans;
}

signed main() {
	file("data");
	n=read(),m=read(),rt=read(),MOD=read();
	REP(i,1,n) val[i]=read();
	REP(i,1,n-1) {
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
		
	dfs1(rt);dfs2(rt,rt);	
		
	s.build(1,1,n);
	REP(i,1,m) {
		int op=read();
		if(op==1) {
			int u=read(),v=read(),d=read();
			change(u,v,d);
		}
		if(op==2) {
			int u=read(),v=read();
			printf("%lld\n",ask(u,v));
		}
		if(op==3) {
			int u=read(),z=read();
			s.change(1,id[u],id[u]+size[u]-1,z);
		}
		if(op==4) {
			int u=read();
			printf("%lld\n",s.ask(1,id[u],id[u]+size[u]-1));
		}
	}
	return 0;
}

