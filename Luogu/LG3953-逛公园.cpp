#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>

using namespace std;
#define int ll
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

const int MAXN=100000+10,MAXM=200000+10;

int head[MAXN],_next[MAXM],to[MAXM],weigh[MAXM],cnt;

void addedge(int u,int v,int w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
}

queue<int> q;

int dist[MAXN],inq[MAXN];

vector<pair<int,int> > g[MAXN];

void SPFA(int s) {
	q.push(s);inq[s]=1;
	memset(dist,127,sizeof(dist));
	memset(inq,0,sizeof(inq));
	dist[s]=0;
	while(!q.empty()) {
		int u=q.front();q.pop();inq[u]=0;
		REP(i,0,(int)g[u].size()-1) {
			int v=g[u][i].first;
			if(dist[v]>dist[u]+g[u][i].second) {
				dist[v]=dist[u]+g[u][i].second;
				if(!inq[v]) {
					inq[v]=1;
					q.push(v);
				}
			}
		}
	}
}

int vis[MAXN][50+5],dp[MAXN][50+5];

int n,m,k,p;

int dfs(int u,int k) {

	if(vis[u][k]) return dp[u][k]=-1;
	if(dp[u][k]) return dp[u][k];
	if(u==n) dp[u][k]=1;else dp[u][k]=0;
	vis[u][k]=1;
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i],wei=weigh[i]-dist[u]+dist[v];
		if(k>=wei) {
			dfs(v,k-wei);
			if(dp[v][k-wei]==-1) {
				vis[u][k]=0;dp[u][k]=-1;return -1;
			}
			else dp[u][k]=(dp[u][k]+dp[v][k-wei])%p;
		}
	}
	vis[u][k]=0;
	return dp[u][k];
}

signed main() {
file("park6");
	int t=read();
	while(t--) {
		n=read(),m=read(),k=read(),p=read();
		REP(i,1,m) {
			int u=read(),v=read(),w=read();
			addedge(u,v,w);
			g[v].push_back(make_pair(u,w));
		}
		SPFA(n);

		//REP(i,1,n) printf("%d ",dist[i]);	
		printf("%lld \n",dfs(1,k));
		
		memset(dp,0,sizeof(dp));
		memset(vis,0,sizeof(vis));
		memset(head,0,sizeof(head));
		cnt=0;
		REP(i,1,n) g[i].clear();
	}
	return 0;
}
