#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
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

#define ll long long
#define int ll

const int MAXN=1e4+10,MAXM=4e5+10,INF=0x3f3f3f3f;

int head[MAXN],cur[MAXN],_next[MAXM<<1],to[MAXM<<1],weigh[MAXM<<1],cnt=1;

void addedge(int u,int v,int w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
}

int va[MAXN],vb[MAXN],ea[MAXM],eb[MAXM],ec[MAXM],u[MAXM],v[MAXM];

int n,m,s,t;

int dept[MAXN];
queue<int> q;
bool bfs() {
	memset(dept,0,sizeof(dept));
	memcpy(cur,head,sizeof(head));
	dept[s]=1;
	q.push(s);
	while(!q.empty()) {
		int u=q.front();q.pop();
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(weigh[i]&&dept[v]==0) {
				dept[v]=dept[u]+1;
				q.push(v);
			}
		}
	}
	return dept[t]!=0;
}

int dfs(int u,int minn) {
	if(u==t) return minn;
	int sum=0,ft=0;
	for(int i=cur[u]; i; i=_next[i]) {
		cur[u]=i;
		int v=to[i];
		if(dept[v]==dept[u]+1&&weigh[i]&&(ft=dfs(v,min(weigh[i],minn-sum)))) {
			weigh[i]-=ft;
			weigh[i^1]+=ft;
			sum+=ft;
			if(!(minn-sum)) break;
		}
	}
	return sum;
}

int dinic() {
	int ans=0;
	while(bfs()) {
		int x=dfs(s,INF);
		if(!x) break;
		ans+=x;
	}
	return ans;
}

void add(int u,int v,int w) {
	addedge(u,v,w);
	addedge(v,u,0);
}


signed main() {
	n=read(),m=read();
	ll sum=0;	
	REP(i,2,n-1) va[i]=2*read(),sum+=va[i];
	REP(i,2,n-1) vb[i]=2*read(),sum+=vb[i];

	REP(i,1,m) u[i]=read(),v[i]=read(),ea[i]=2*read(),eb[i]=2*read(),ec[i]=2*read(),sum+=ea[i]+eb[i];
	
	s=1e4+1,t=1e4+2;
	REP(i,2,n-1) add(s,i,va[i]);
	REP(i,2,n-1) add(i,t,vb[i]);
	add(s,1,INF),add(n,t,INF);
	


	REP(i,1,m) {
		int w=ea[i]/2+eb[i]/2+ec[i];
		addedge(u[i],v[i],w),addedge(v[i],u[i],w);
		add(s,u[i],ea[i]/2),add(u[i],t,eb[i]/2);
		add(s,v[i],ea[i]/2),add(v[i],t,eb[i]/2);
	}
	int d=dinic();
	printf("%lld\n",(sum-d)/2);
	return 0;
}
