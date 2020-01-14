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

int head[MAXN],to[MAXN<<1],_next[MAXN<<1],weigh[MAXN<<1],cnt;

void addedge(int u,int v,int w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
}

int fa[MAXN],f[MAXN][3];

void dfs1(int u) {
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(fa[u]==v) continue;
		fa[v]=u;
		dfs1(v);	
		int d=weigh[i]+f[v][0];
		if(d>f[u][0]) swap(d,f[u][0]);
		if(d>f[u][1]) swap(d,f[u][1]);	
	}
}

void dfs2(int u) {
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(fa[u]==v) continue;
		if(f[u][0]==f[v][0]+weigh[i]) f[v][2]=max(f[u][2],f[u][1])+weigh[i];
		else f[v][2]=max(f[u][2],f[u][0])+weigh[i];
		dfs2(v);
	}
}

int main() {
	int n;
	while(scanf("%d",&n)==1) {
		memset(head,0,sizeof(head));
		memset(f,0,sizeof(f));
		cnt=0;
		memset(fa,0,sizeof(fa));
		REP(u,2,n) {
			int v=read(),w=read();
			addedge(u,v,w);
			addedge(v,u,w);
		}
		dfs1(1);dfs2(1);
	
		REP(i,1,n) printf("%d\n",max(f[i][0],f[i][2]));
	}
	return 0;
}

