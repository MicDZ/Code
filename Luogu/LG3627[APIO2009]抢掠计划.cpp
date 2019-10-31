#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<stack>
#include<vector>
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

const int MAXN=500000+10;

int head[MAXN],_next[MAXN],to[MAXN],cnt;

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

int head_[MAXN],_next_[MAXN],to_[MAXN],weigh[MAXN],cnt_;
void Addedge(int u,int v,int w) {
	cnt_++;
	_next_[cnt_]=head_[u];
	head_[u]=cnt_;
	to_[cnt_]=v;
	weigh[cnt_]=w;
}

stack <int> s;

int dfn[MAXN],low[MAXN],ins[MAXN],id[MAXN],a[MAXN],weig[MAXN],color,tot;

void tarjan(int u) {
	dfn[u]=low[u]=++tot;
	s.push(u);
	ins[u]=1;
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(!dfn[v]) {
			tarjan(v);
			low[u]=min(low[v],low[u]);
		}
		else if(ins[v]) low[u]=min(low[v],low[u]);
	}
	if(dfn[u]==low[u]) {
		int v;
		color++;
		do {
			v=s.top();s.pop();ins[v]=0;
			id[v]=color;
			weig[color]+=a[v];
		} while(u!=v);
	}
}

int have[MAXN],end[MAXN];

vector <int> g[MAXN];

int inq[MAXN],dist[MAXN];
queue<int> q;

void SPFA(int s) {
	memset(dist,0,sizeof(dist));
	dist[s]=weigh[s];
	q.push(s);inq[s]=1;
	while(!q.empty()) {
		int u=q.front();q.pop();
		inq[u]=0;
		for(int i=head_[u]; i; i=_next_[i]) {
			int v=to_[i];
			if(dist[v]<dist[u]+weigh[i]) {
				dist[v]=dist[u]+weigh[i];
				if(!inq[v]) {
					inq[v]=1;
					q.push(v);
				}
			}
		}
	}
}


int main() {
	int n=read(),m=read();

	REP(i,1,m) {
		int u=read(),v=read();
		addedge(u,v);
	} 
	
	REP(i,1,n) a[i]=read();

	int s=read(),p=read();

	
	REP(i,1,n) if(!dfn[i]) tarjan(i);

	REP(u,1,n) for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(id[u]==id[v]) continue;
		Addedge(id[u],id[v],weig[id[v]]);
		DE("%d %d %d \n",id[u],id[v],weig[id[v]]);
	}
	
	Addedge(0,id[s],weig[id[s]]);

	SPFA(0);
	

		int ans=0;

	REP(i,1,p) 
		ans=max(ans,dist[id[read()]]);

	printf("%d\n",ans);
	return 0;
}
