#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

#define ll long long
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=300+10,INF=0x3f3f3f;

int head[MAXN],_next[MAXN<<1],to[MAXN<<1],weigh[MAXN<<1],cnt;

void addedge(int u,int v,int w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
}

queue<int> q;

int dist[MAXN],dist2[MAXN][MAXN];

void bfs(int s) {
	q.push(s);
	memset(dist,127,sizeof(dist));
	dist[s]=0;
	while(!q.empty()) {
		int u=q.front();q.pop();
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(dist[v]>=dist[0]) {
				dist[v]=dist[u]+weigh[i];
				q.push(v);
			}
		}
	}
}
int n,s;
void bfs3(int s) {
	q.push(s);
	REP(i,1,n) dist2[s][i]=INF;
	dist2[s][s]=0;
	while(!q.empty()) {
		int u=q.front();q.pop();
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(dist2[s][v]>=INF) {
				dist2[s][v]=dist2[s][u]+weigh[i];
				q.push(v);
			}
		}
	}
}


vector<int> route;

struct edge {
	int pos;
	vector<int> rou;
};

queue<edge> q2;
int vis[MAXN];
void bfs2(int s,int t) {
	edge st;

	vis[s]=1;
	st.rou.push_back(s);
	q2.push(st);
	while(!q2.empty()) {
		edge y=q2.front();q2.pop();
		int u=y.rou[y.rou.size()-1];
		
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(vis[v]) continue;
			vis[v]=1;
			
			y.rou.push_back(v);
			if(v==t) {
				REP(i,0,(int)y.rou.size()-1) 
					route.push_back(y.rou[i]);
				return ;
			}

			q2.push(y);
			y.rou.pop_back();
		}
				
	}
}

int main() {
	n=read(),s=read();
	REP(i,1,n-1) {
		int u=read(),v=read(),w=read();
		addedge(u,v,w);
		addedge(v,u,w);
	}
	
	bfs(1);
	int maxx=0,pos1;
	
	REP(i,1,n) if(dist[i]>maxx) {
		maxx=dist[i];
		pos1=i;
	}
	
	bfs(pos1);
	maxx=0;int pos2;
	REP(i,1,n) if(dist[i]>maxx) {
		maxx=dist[i];
		pos2=i;
	}
	
	// pos1->pos2
	bfs2(pos1,pos2);
	
	REP(i,1,n) bfs3(i);

	int ans=INF;
	REP(i,1,s) {
		REP(j,0,i-1) {
			
			REP(k,1,s) {
				int maxx=0;
				int now=j+k-1;
				if(now>route.size()-1) continue;
				REP(q,1,n)
				maxx=max(maxx,dist2[route[now]][q]);
				ans=min(ans,maxx);
			}
			
		}
	}
	printf("%d\n",ans);
	return 0;
}

