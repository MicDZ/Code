#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;
#define ll long long
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define DE(...) fprintf(stderr,__VA_ARGS__);
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)


int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int INF=0x3f3f3f,MAXN=100000+10;

int n,m,r,mod;

int head[MAXN],to[MAXN<<1],_next[MAXN<<1],cnt;

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}
int a1[MAXN],a2[MAXN];
struct SegmentTree {
	int l,r,dat,add,maxx;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define dat(x) tree[x].dat
	#define add(x) tree[x].add
	#define len(x) (tree[x].r-tree[x].l+1)
    #define maxx(x) tree[x].maxx
} tree[MAXN<<2];

void spread(int p) {
	if(add(p)) {
		dat(p*2)=(dat(p*2)+add(p)*len(p*2))%mod;
		dat(p*2+1)=(dat(p*2+1)+add(p)*len(p*2+1))%mod;
		add(p*2)=(add(p*2)+add(p))%mod;
		add(p*2+1)=(add(p*2+1)+add(p))%mod;
		add(p)=0;
	}
}

void build(int p,int l,int r) {
	l(p)=l,r(p)=r,add(p)=0;
	if(l==r) {
		dat(p)=a2[l]%mod;
        maxx(p)=a2[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	dat(p)=(dat(p*2)+dat(p*2+1))%mod;
    maxx(p)=max(maxx(p*2),maxx(p*2+1));
}

void change(int p,int l,int r,int d) {
	if(l(p)>=l&&r(p)<=r) {
		dat(p)=(dat(p)+len(p)*d)%mod;
		add(p)=(add(p)+d)%mod;
		return ;
	}
	spread(p);
	
	int mid=(l(p)+r(p))>>1;
	if(l<=mid) change(p*2,l,r,d);
	if(r>mid) change(p*2+1,l,r,d);
	dat(p)=(dat(p*2)+dat(p*2+1))%mod;
    maxx(p)=max(dat(p*2),dat(p*2+1));
}

int ask(int p,int l,int r) {
	int ans=0;
	if(l(p)>=l&&r(p)<=r) {
		return dat(p);
		//return ;
	}
	spread(p);
	int mid=(l(p)+r(p))>>1;
	if(l<=mid) ans=(ans+ask(p*2,l,r))%mod;
	if(r>mid) ans=(ans+ask(p*2+1,l,r))%mod;
	return ans%mod;
}

int ask_max(int p,int l,int r) {
	int ans=0;
	if(l(p)>=l&&r(p)<=r) {
		return dat(p);
		//return ;
	}
	spread(p);
	int mid=(l(p)+r(p))>>1;
	if(l<=mid) ans=max(ans,ask(p*2,l,r))%mod;
	if(r>mid) ans=max(ans,ask(p*2+1,l,r))%mod;
	return ans%mod;
}

int size[MAXN],hson[MAXN],fa[MAXN],dept[MAXN];

void dfs1(int u) {
	size[u]=1;
	dept[u]=dept[fa[u]]+1;
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(v==fa[u]) continue;
		fa[v]=u;
		dfs1(v);
		size[u]+=size[v];
		if(!hson[u]||size[v]>size[hson[u]]) hson[u]=v;
	}
}

int id[MAXN],top[MAXN],tot;

void dfs2(int u,int nowtop) {
	id[u]=++tot;
	a2[tot]=a1[u];
	top[u]=nowtop;
    //if(u==2) DE("hson: %d\n",hson[u]);
	if(hson[u]) dfs2(hson[u],nowtop);
	for(int i=head[u]; i; i=_next[i]) {
        
		int v=to[i];
        
		if(v==fa[u]||v==hson[u]) continue;
        //DEBUG(v);
		dfs2(v,v);
	}
}

int main() {
	//file("t");
	n=read();mod=INF;
	

	REP(i,1,n-1) {
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}

    REP(i,1,n) a1[i]=read();

	dfs1(r);
	dfs2(r,r);
	
	build(1,1,n);
    m=read();

	REP(i,1,m) {
		char op[7];
        scanf("%s",op+1);
        if(op[1]=='Q'&&op[2]=='M') {
            int x=read(),y=read();
			int ans=0;
			while(top[x]!=top[y]) {
				if(dept[top[x]]<dept[top[y]]) swap(x,y);
				ans=(ans+ask_max(1,id[top[x]],id[x]))%mod;
				x=fa[top[x]];
			}
			if(dept[x]>dept[y]) swap(x,y);
			ans=(ans+ask_max(1,id[x],id[y]))%mod;
			printf("%d\n",ans);
        }
        if(op[1]=='Q'&&op[2]=='S') {
            int x=read(),y=read();
			int ans=0;
			while(top[x]!=top[y]) {
				if(dept[top[x]]<dept[top[y]]) swap(x,y);
				ans=(ans+ask(1,id[top[x]],id[x]))%mod;
				x=fa[top[x]];
			}
			if(dept[x]>dept[y]) swap(x,y);
			ans=(ans+ask(1,id[x],id[y]))%mod;
			printf("%d\n",ans);
        }
        if(op[1]=='C') {
            int x=read(),y=x,z=read();
			z%=mod;
			while(top[x]!=top[y]) {
				if(dept[top[x]]<dept[top[y]]) swap(x,y);
				change(1,id[top[x]],id[x],z);
				x=fa[top[x]];
			}
			if(dept[x]>dept[y]) swap(x,y);
			change(1,id[x],id[y],z);
        }
		
	}
	return 0;
}
