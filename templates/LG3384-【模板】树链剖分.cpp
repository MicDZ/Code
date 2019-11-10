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

int n,m,r,MOD;

const int MAXN=100000+10;

int val[MAXN],head[MAXN],to[MAXN<<1],_next[MAXN<<1],cnt;

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

int size[MAXN],hson[MAXN],fa[MAXN],dept[MAXN];

void dfs1(int u) {
	size[u]=1;
	dept[u]=dept[fa[u]]+1;
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(fa[u]==v) continue;
		fa[v]=u;
		dfs1(v);
		size[u]+=size[v];
		if(!hson[u]||size[v]>size[hson[u]]) hson[u]=v;
	}
}

int a[MAXN],id[MAXN],top[MAXN],tot;

void dfs2(int u,int nowtop) {
	id[u]=++tot;
	a[tot]=val[u];
	top[u]=nowtop;
	if(hson[u]) dfs2(hson[u],nowtop);
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(fa[u]==v||v==hson[u]) continue;
		dfs2(v,v);
	}
}

struct SegmentTree {
	int l[MAXN<<2],r[MAXN<<2],len[MAXN<<2],sum[MAXN<<2],add[MAXN<<2];
	void build(int p,int lf,int rg) {
		l[p]=lf,r[p]=rg,len[p]=r[p]-l[p]+1,sum[p]=0;
		if(lf==rg) {sum[p]=a[lf]%MOD; return ;}
		int mid=(l[p]+r[p])>>1;
		build(p*2,lf,mid);
		build(p*2+1,mid+1,rg);
		sum[p]=(sum[p*2]+sum[p*2+1])%MOD;
	}
	void spread(int p) {
		if(add[p]) {
			sum[p*2]=(sum[p*2]+add[p]*len[p*2])%MOD;
			sum[p*2+1]=(sum[p*2+1]+add[p]*len[p*2+1])%MOD;
			add[p*2]=(add[p*2]+add[p])%MOD;
			add[p*2+1]=(add[p*2+1]+add[p])%MOD;
			add[p]=0;
		}
	}
	void change(int p,int lf,int rg,int d) {
		if(l[p]>=lf&&r[p]<=rg) {sum[p]=(sum[p]+len[p]*d)%MOD;add[p]=(add[p]+d)%MOD;return ;}
		spread(p);
		int mid=(l[p]+r[p])>>1;
		if(lf<=mid) change(p*2,lf,rg,d);
		if(rg>mid) change(p*2+1,lf,rg,d);
		sum[p]=(sum[p*2]+sum[p*2+1])%MOD;
	}
	int ask(int p,int lf,int rg) {
		int ans=0;
		if(l[p]>=lf&&r[p]<=rg) {return sum[p];}
		spread(p);
		int mid=(l[p]+r[p])>>1;
		if(lf<=mid) ans=(ans+ask(p*2,lf,rg))%MOD;
		if(rg>mid) ans=(ans+ask(p*2+1,lf,rg))%MOD;
		return ans%MOD;
	}
} s;

void add(int u,int v,int d) {
	d%=MOD;
	while(top[u]!=top[v]) {
		if(dept[top[u]]<dept[top[v]]) swap(u,v);
		s.change(1,id[top[u]],id[u],d);
		u=fa[top[u]];
	}
	if(dept[u]>dept[v]) swap(u,v);
	s.change(1,id[u],id[v],d);
}

int ask(int u,int v) {
	int ans=0;
	while(top[u]!=top[v]) {
		if(dept[top[u]]<dept[top[v]]) swap(u,v);
		ans=(ans+s.ask(1,id[top[u]],id[u]))%MOD;
		u=fa[top[u]];
	}
	if(dept[u]>dept[v]) swap(u,v);
	ans=(ans+s.ask(1,id[top[u]],id[u]))%MOD;
	return ans;
}

int main() {
	n=read(),m=read(),r=read(),MOD=read();
	
	REP(i,1,n) val[i]=read();

	REP(i,1,n-1) {
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
	
	dfs1(r);dfs2(r,r);
	s.build(1,1,n);		
	REP(i,1,m) {
		int op=read();
		if(op==1) {
			int x=read(),y=read(),z=read();
			add(x,y,z);
		}
		if(op==2) {
			int x=read(),y=read();
			printf("%d\n",ask(x,y));
		}
		if(op==3) {
			int x=read(),d=read();
			s.change(1,id[x],id[x]+size[x]-1,d);
		}
		if(op==4) {
			int x=read();
			printf("%d\n",s.ask(1,id[x],id[x]+size[x]-1));
		}
	}
	return 0;
}

