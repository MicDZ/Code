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

const int MAXN=100000+10,INF=0x3f3f3f;

struct city {
	int w,c;
} a[MAXN];

int head[MAXN],_next[MAXN<<1],to[MAXN<<1],cnt;

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

int tot,fa[MAXN],f[MAXN],book[MAXN];
pair<int,int> temp[MAXN];

bool cmp(pair<int,int> a,pair<int,int> b) {
	return a>b;
}

void dfs(int u) {
	f[u]=a[u].w;
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(v==fa[u]) continue;
		fa[v]=u;
		dfs(v);
	}
	tot=0;
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(v==fa[u]) continue;
		temp[++tot]=make_pair(f[v],v);
	}
	sort(temp+1,temp+1+tot,cmp);
	int ptr=1,lim=min(tot,a[u].c-1);
	while(ptr<=lim&&f[temp[ptr].second]>=0) f[u]+=f[temp[ptr].second],book[u]|=book[temp[ptr].second],ptr++;
	if((ptr<=tot&&ptr>1&&f[temp[ptr].second]==f[temp[ptr-1].second])||(f[temp[ptr-1].second]==0&&ptr>1)) book[u]=1;
}

int main() {
	freopen("data.in","r",stdin);
	int n=read();
	REP(i,2,n) a[i].w=read();
	REP(i,2,n) a[i].c=read();

	REP(i,1,n-1) {
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
	a[1].w=0;a[1].c=INF;
	dfs(1);

	printf("%d\n",f[1]);
	puts(book[1]?"solution is not unique":"solution is unique");
	return 0;
}

