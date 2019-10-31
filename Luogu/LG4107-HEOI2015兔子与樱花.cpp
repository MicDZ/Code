#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
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

const int MAXN=2000000+10;

int c[MAXN],son[MAXN];

int head[MAXN],to[MAXN],_next[MAXN],cnt;

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

struct edge {
	int w,id;
};

bool cmp(int a,int b) {
	return c[a]+son[a]<c[b]+son[b];
}

int ans;
int n,m,a[MAXN],dfn[MAXN],low[MAXN];
void dfs(int u) {
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		dfs(v);
	}
	
	sort(a+dfn[u],a+low[u]+1,cmp);
	
	REP(i,dfn[u],low[u]) {
		if(c[u]+c[a[i]]+son[u]+son[a[i]]-1<=m) c[u]+=c[a[i]],son[u]+=son[a[i]]-1,ans++;
		else break;
	}
}

int main() {
	n=read(),m=read();
	int num=0;
	REP(i,1,n) c[i]=read();
	REP(i,1,n) {
		son[i]=read();dfn[i]=num+1;
		REP(j,1,son[i]) {
			int v=read()+1;
			addedge(i,v);
			a[++num]=v;
		}
		low[i]=num;
	}
	
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
