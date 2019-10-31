#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
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

const int MAXN=10000+10,MAXM=5000+10;

int head[MAXN],_next[MAXM<<1],to[MAXM<<1],weigh[MAXM<<1],cnt;

void addedge(int u,int v,int w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
}

int n,m,vis[MAXN],check1[MAXN],check2[MAXN];

queue<int> q;

vector<int> g1[MAXN],g2[MAXN];

void bfs1(int s) {
	q.push(s);check1[s]=1;
	while(!q.empty()) {
		int u=q.front();q.pop();
		REP(i,0,(int)g1[u].size()-1) {
			int v=g1[u][i];
			if(check1[v]) continue;
			check1[v]=1;
			q.push(v);
		}
	}
}
void bfs2(int s) {
	q.push(s);check2[s]=1;
	while(!q.empty()) {
		int u=q.front();q.pop();
		REP(i,0,(int)g2[u].size()-1) {
			int v=g2[u][i];
			if(check2[v]) continue;
			check2[v]=1;
			q.push(v);
		}
	}
}




int inq[MAXN],dist[MAXN],num[MAXN];

int x[MAXN],y[MAXN];

void SPFA() {
	q.push(1);inq[1]=1;
	memset(dist,127,sizeof(dist));
	dist[1]=0;
	while(!q.empty()) {
		int u=q.front();q.pop();
		inq[u]=0;
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(!check1[v]||!check2[v]) continue;
			if(dist[v]>dist[u]+weigh[i]) {
				dist[v]=dist[u]+weigh[i];
				if(!inq[v]) {
					num[v]++;
					if(num[v]>n) {
						puts("-1");
						return ;
					}
					inq[v]=1;
					q.push(v);
				}
			}
		}
	}
	
	if(dist[n]==dist[0]) {puts("-1");return ;}

	printf("%d %d\n",n,m);
	REP(i,1,m) {
		printf("%d %d ",x[i],y[i]);
		if(check1[x[i]]&&check1[y[i]]&&check2[x[i]]&&check2[y[i]]) printf("%d\n",dist[y[i]]-dist[x[i]]);
		else puts("1");
	}
}


int main() {
	n=read(),m=read();

	REP(i,1,m) {
		int u=read(),v=read();
		addedge(u,v,9);
		addedge(v,u,-1);
		g1[v].push_back(u);
		g2[u].push_back(v);
		x[i]=u;y[i]=v;
	}

	bfs1(n);
	bfs2(1);
	SPFA();


	return 0;
}
