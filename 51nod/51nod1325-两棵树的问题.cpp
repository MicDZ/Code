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

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=300+10,MAXM=2000+10,INF=0x3f3f3f3f;

int head[MAXN],cur[MAXN],_next[MAXM],to[MAXM],weigh[MAXM],cnt=1;

void addedge(int u,int v,int w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
}

void add(int u,int v,int w) {
	addedge(u,v,w);
	addedge(v,u,0);
}

vector<int> g[2][MAXN];

int n,v[MAXN];

int sum;

void dfs1(int u,int v) {
	if(v) add(u,v,INF);
	REP(i,0,(int)g[0][u].size()-1) if(g[0][u][i]!=v) dfs1(g[0][u][i],u);
}

void dfs2(int u,int v) {
	if(v) add(u,v,INF);
	REP(i,0,(int)g[1][u].size()-1) if(g[1][u][i]!=v) dfs2(g[1][u][i],u);
}

int calc,vis[MAXN],dis[MAXN];

int dfs(int u,int F) {
	vis[u]=calc;
	if(u==n+1) return F;
	for(int i=cur[u]; i; i=_next[i]) {
		if(!weigh[i]||vis[to[i]]>=calc||dis[u]!=dis[to[i]]+1) continue;
		int tmp=dfs(to[i],min(F,weigh[i]));
		if(tmp) {
			weigh[i]-=tmp; weigh[i^1]+=tmp;
			cur[u]=i;
			return tmp;
		}
	}
	return 0;
}

void flow() {
	REP(i,0,n) cur[i]=head[i];
	while(1) {
		calc++;
		int flow=dfs(0,INF);
		if(!flow) break;
		sum-=flow;
	}
}

bool check() {
	int tmp=INF;
	REP(u,0,n+1) if(vis[u]==calc) 
		for(int i=head[u]; i; i=_next[i]) {
			if(vis[to[i]]==calc||!weigh[i]||dis[to[i]]+1-dis[u]>=tmp) continue;
			tmp=dis[to[i]]-dis[u]+1;
		}
	if(tmp==INF) return 0;
	REP(i,0,n+1) if(vis[i]==calc) dis[i]+=tmp;
	return 1;
}

int main() {
	n=read();
	REP(i,1,n) v[i]=read();
	REP(i,1,n-1) {
		int u=read()+1,v=read()+1;
		g[0][u].push_back(v);
		g[0][v].push_back(u);
	}
	REP(i,1,n-1) {
		int u=read()+1,v=read()+1;
		g[1][u].push_back(v);
		g[1][v].push_back(u);
	}
	
	int ans=0;

	REP(i,1,n) {
		cnt=1,sum=0;
		memset(head,0,sizeof(head));
		dfs1(i,0),dfs2(i,0);
		REP(j,1,n) {
			if(v[j]>0) sum+=v[j],add(0,j,v[j]);
			else add(j,n+1,-v[j]);
		}
		calc=0;
		memset(vis,0,sizeof(vis));
		memset(dis,0,sizeof(dis));
		for(flow();check();flow());
		ans=max(ans,sum);
	}

	printf("%d\n",ans);
	return 0;
}

