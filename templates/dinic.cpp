#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>

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

const int MAXN=10000+10,MAXM=100000+10,INF=0x3f3f3f3f;

int head[MAXN],cur[MAXN],_next[MAXM<<1],to[MAXM<<1],cap[MAXM<<1],cnt=1;

void addedge(int u,int v,int c) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	cap[cnt]=c;
}

int n,m,s,t;

int dept[MAXN];
queue<int> q;
bool bfs() {
	memset(dept,0,sizeof(dept));
	dept[s]=1;
	q.push(s);
	while(!q.empty()) {
		int u=q.front();q.pop();
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(cap[i]&&dept[v]==0) {
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
		if(dept[v]==dept[u]+1&&cap[i]&&(ft=dfs(v,min(cap[i],minn-sum)))) {
			cap[i]-=ft;
			cap[i^1]+=ft;
			sum+=ft;
		}
	}
	return sum;
}

int main() {
	n=read(),m=read(),s=read(),t=read();
	REP(i,1,m) {
		int u=read(),v=read(),w=read();
		addedge(u,v,w);
		addedge(v,u,0);
	}
	int ans=0;
	while(bfs()) {
		REP(i,1,n) cur[i]=head[i];
		int x=dfs(s,INF);
		if(!x) break;
		ans+=x;
	}

	printf("%d\n",ans);
	return 0;
}

