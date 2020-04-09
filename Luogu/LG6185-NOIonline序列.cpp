#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a)	freopen(a".in","r",stdin);freopen(a".out","w",stdout)
using namespace std;
#define ll long long
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=1e5+10;

int a[MAXN],b[MAXN],fa[MAXN];
ll s[MAXN],v[MAXN],c[MAXN];

vector<int> g[MAXN],p[MAXN];

int find(int x) {
	if(fa[x]==x) return fa[x];
	return fa[x]=find(fa[x]);
}

void link(int x,int y) {fa[find(x)]=find(y);}

struct edge {
	int u,v;
} e[MAXN];

bool dfs(int u,int k) {
	v[u]=k,c[k]+=s[u];
	bool fl=1;
	REP(i,0,(int)g[u].size()-1) {
		int to=g[u][i];
		if(v[to]==v[u]) fl=0;
		if(!v[to]&&!dfs(to,3-k)) fl=0;
	}
	return fl;
}

int main() {
	int t=read();
	while(t--) {
		int n=read(),m=read(),t=0;
		REP(i,1,n) a[i]=read();
		REP(i,1,n) b[i]=read();
		REP(i,1,n) fa[i]=i,s[i]=v[i]=0,g[i].clear();
		REP(i,1,m) {
			int t=read(),u=read(),v=read();
			if(t==2) link(u,v);
			else e[++t]=(edge){u,v};
		}
		REP(i,1,n) s[find(i)]+=b[i]-a[i];
		REP(i,1,t) {
			int u=find(e[i].u),v=find(e[i].v);
			g[u].push_back(v),g[v].push_back(u);
		}
		bool mark=0;
		REP(i,1,n) if(find(i)==i&&!v[i]) {
			c[1]=c[2]=0;
			bool fl=dfs(i,1);
			if(fl&&c[1]!=c[2]) puts("NO"),mark=1;
			else if(!fl&&(c[1]^c[2])&1) puts("NO"),mark=1;
		}
		if(!mark) puts("YES");
	}
	return 0;
}

