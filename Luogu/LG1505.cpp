#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define ll long long
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define int ll
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=100000+10,INF=0x3f3f3f3f3f;
int a[MAXN],w[MAXN];

int head[MAXN],to[MAXN<<1],_next[MAXN<<1],cnt;

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

struct SegmentTree {
	int l,r,sum,add,maxx;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define sum(x) tree[x].sum
	#define add(x) tree[x].add
	#define maxx(x) tree[x].maxx
	#define len(x) (tree[x].r-tree[x].l+1)
} tree[MAXN<<2];

void spread(int p) {
	if(!add(p)) return ;
	sum(p*2)+=add(p)*len(p*2);
	sum(p*2+1)+=add(p)*len(p*2+1);
	add(p*2)+=add(p);
	add(p*2+1)+=add(p);
	add(p)=0;
}

void build(int p,int l,int r) {
	l(p)=l,r(p)=r;
	if(l==r) {
		sum(p)=w[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);

	sum(p)=sum(p*2)+sum(p*2+1);
}

void change(int p,int l,int r,int d) {
	if(l<=l(p)&&r>=r(p)) {
		add(p)+=d;
		sum(p)+=len(p)*d;;
		return ;
	}
	spread(p);
	int mid=(l(p)+r(p))>>1;
	if(l<=mid) change(p*2,l,r,d);
	if(r>mid) change(p*2+1,l,r,d);
	sum(p)=sum(p*2)+sum(p*2+1);
	maxx(p)=max(maxx(p*2),maxx(p*2+1));
}

int ask(int p,int l,int r) {
	if(l<=l(p)&&r>=r(p)) return sum(p);
	spread(p);
	int mid=(l(p)+r(p))>>1;
	int ans=0;
	if(l<=mid) ans+=ask(p*2,l,r);
	if(r>mid) ans+=ask(p*2+1,l,r);
	return ans;
}

int ask_max(int p,int l,int r) {
	if(l<=l(p)&&r>=r(p)) return sum(p);
	spread(p);
	int mid=(l(p)+r(p))>>1;
	int ans=0;
	if(l<=mid) ans=max(ans.ask(p*2,l,r);
	if(r>mid) ans=max(ans,ask(p*2+1,l,r));

	return ans;
}

int ask_min(int p,int l,int r) {
	if(l<=l(p)&&r>=r(p)) return sum(p);
	spread(p);
	int mid=(l(p)+r(p))>>1;
	int ans=INF;
	if(l<=mid) ans=min(ans,ask(p*2,l,r));
	if(r>mid) ans=min(ans,ask(p*2+1,l,r));

	return ans;
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

int id[MAXN],top[MAXN],tot;

void dfs2(int u,int nowtop) {
	id[u]=++tot;
	w[tot]=a[u];
	top[u]=nowtop;
	if(hson[u]) dfs2(hson[u],nowtop);
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(fa[u]==v||v==hson[u]) continue;

		dfs2(v,v);
	}
}

signed main() {
	int n=read(),m=read();
	REP(i,1,n) a[i]=read();

	REP(i,1,n-1) {
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
	
	dfs1(1);

	dfs2(1,1);

	build(1,1,n);

	REP(i,1,m) {
		int op[5];
		scanf("%s",op+1);
		if(op[1]=='C') {
			int x=read(),a=read();
			change(1,id[x],id[x],a);
		}
		if(op[1]=='N') {
			int x=read(),a=read();
			change(1,id[x],id[x]+size[x]-1,a);
		}
		if(op==3) {
			int x=read(),y=1;
			int ans=0;
			while(top[x]!=top[y]) {
				if(dept[top[x]]<dept[top[y]]) swap(x,y);
				ans=ans+ask(1,id[top[x]],id[x]);
				x=fa[top[x]];
			}
			if(dept[x]>dept[y]) swap(x,y);
			ans=ans+ask(1,id[x],id[y]);

			printf("%lld\n",ans);
		}
	//DEBUG(op);
	}
	return 0;
}
