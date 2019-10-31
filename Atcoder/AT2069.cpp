#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define DE(...) fprintf(stderr,__VA_ARGS__);
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define ll long long

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int INF=0x3f3f3f,MAXN=1e6+10,MAXM=1e6+10;

int head[MAXN],to[MAXM<<1],_next[MAXM<<1],weigh[MAXM<<1],cnt;

void addedge(int u,int v,int w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
}

int dist[MAXN],inq[MAXN];
queue<int> q;
void SPFA() {
	q.push(1);
	inq[1]=1;
	memset(dist,127,sizeof(dist));
	dist[1]=0;
	while(!q.empty()) {
		int u=q.front();q.pop();
		inq[u]=0;
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(dist[v]>dist[u]+weigh[i]) {
				dist[v]=dist[u]+weigh[i];
				if(!inq[v]) {
					inq[v]=1;
					q.push(v);
				}
			}
		}
	}
}

map<int,int> mp[MAXN];
int tot;
int get(int x,int w) {
	if(!mp[x][w]) mp[x][w]=++tot;
	return mp[x][w];
}

int main() {
	int n=read(),m=read();
	tot=n;
	REP(i,1,m) {
		int u=read(),v=read(),w=read();
		int du=get(u,w),dv=get(v,w);
		addedge(u,du,1);addedge(du,u,1);
		addedge(du,dv,0);addedge(dv,du,0);
		addedge(v,dv,1);addedge(dv,v,1);
	}

	SPFA();

	printf("%d\n",dist[n]>2*n?-1:dist[n]/2);
	return 0;
}

