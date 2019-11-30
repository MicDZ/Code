#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;
#define int ll
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

const int MAXN=10000000+10;

int a[MAXN];

int head[MAXN],_next[MAXN<<1],to[MAXN<<1],weigh[MAXN<<1],cnt;

void addedge(int u,int v,int w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
}

int fa[MAXN],sum;

void dfs(int u,int minn) {
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(fa[u]==v||weigh[i]>minn) continue;
		fa[v]=u;//f[v]=f[u]+a[v];
		sum+=a[v];
		dfs(v,minn);
	}
}

int n,W;

bool check(int mid) {
	sum=0;
	dfs(1,mid);
	
	return sum>=W;
}

signed main() {
	file("a");
	n=read(),W=read();
	REP(i,1,n-1) a[i+1]=read(); 
	
	int maxx=0;

	REP(i,1,n-1) {
		int u=read(),v=read(),w=read();
		addedge(u,v,w);
		addedge(v,u,w);
		maxx=max(maxx,w);
	}

	int l=0,r=maxx;
	while(l<r) {
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}

	printf("%lld\n",r);
}

