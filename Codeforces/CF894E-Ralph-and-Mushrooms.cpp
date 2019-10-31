#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<stack>
#include<queue>

using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define ll long long
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define int ll

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=1000000+10,MAXM=1000000+10,INF=0x3f3f3f3f3f3f;

int head[MAXN],_next[MAXM],to[MAXM],weigh[MAXM],cnt;

void addedge(int u,int v,int w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
}

int dfn[MAXN],low[MAXN],ins[MAXN],tot,id[MAXN],color,mush[MAXN];
stack<int> s;

void tarjan(int u) {
	low[u]=dfn[u]=++tot;
	s.push(u);ins[u]=1;
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(!dfn[v]) tarjan(v),low[u]=min(low[u],low[v]);
		else if(ins[v]) low[u]=min(low[u],low[v]);
	}

	if(dfn[u]==low[u]) {
		int v;color++;
		do {
			v=s.top();
			s.pop();
			ins[v]=0;
			id[v]=color;
		}while(u!=v);
	}
}
vector<pair<int,int> > g[MAXN];

queue<int> q;
int dist[MAXN];


int calc(int x){
    int tt=sqrt(2*x+0.25)-0.5;
    return x+tt*x-(tt+1)*(tt+2)*tt/6;
}

int in[MAXN];


int dfs(int u) {
    if (dist[u]) return dist[u];
    REP(i,0,(int)g[u].size()-1)
		dist[u]=max(dist[u],g[u][i].second+dfs(g[u][i].first));
    return dist[u]+=mush[u];
}

signed main() {
	int n=read(),m=read();

	REP(i,1,m) {
		int u=read(),v=read(),w=read();
		addedge(u,v,w);
	}
	
	REP(i,1,n) if(!dfn[i]) tarjan(i);

	REP(u,1,n) {
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(id[u]==id[v]) {
				mush[id[u]]+=calc(weigh[i]);
			}
		}
	}
	
	//REP(i,1,n) printf("%d\n",id[i]);

	REP(u,1,n) {
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(id[u]==id[v]) continue;
			g[id[u]].push_back(make_pair(id[v],weigh[i]));
			//DE("%d %d %d\n",id[u],id[v],mush[id[v]]+weigh[i]);
			in[id[v]]++;
	}
	}
	int s=read(),ans=0;
		//topo(id[s]);
	//SPFA(id[s]);
	
	REP(i,1,color) ans=max(ans,dist[i]);

	printf("%lld\n",dfs(id[s]));
	return 0;
}
