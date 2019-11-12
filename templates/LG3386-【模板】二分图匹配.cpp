
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

#define REP(i,e,s) for(register int i=(e); i<=(s); i++)
#define DREP(i,e,s) for(register int i=(e); i>=(s); i--)
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

const int MAXN=1000+10,MAXM=6*MAXN*MAXN,INF=0x3f3f3f3f;

int n,m,s,t,e;

int cur[MAXN],head[MAXN],to[MAXM],_next[MAXM],weigh[MAXM],cnt=1;

void addedge(int u,int v,int w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
}

queue<int> q;
int dept[MAXN];

bool bfs() {
	q.push(s);
	REP(i,1,n+m+2) dept[i]=-1;
	dept[s]=0;
	while(!q.empty()) {
		int u=q.front();q.pop();
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(weigh[i]&&dept[v]==-1) {
				dept[v]=dept[u]+1;
				q.push(v);
			}
		}
	}
	return dept[t]!=-1;
}

int dfs(int u,int minn) {
	if(u==t) return minn;
	int ft=0,sum=0;
	for(int i=cur[u]; i; i=_next[i]) {
		cur[u]=i;
		int v=to[i];
		if(dept[v]!=dept[u]+1||!weigh[i]) continue;
		ft=dfs(v,min(minn-sum,weigh[i]));
		if(!ft) continue;
		
		weigh[i]-=ft;
		weigh[i^1]+=ft;
		sum+=ft;
	}
	return sum;
}

int main() {
	n=read(),m=read(),e=read();
	s=1,t=n+m+2;
	REP(i,1,n) addedge(s,i+1,1),addedge(i+1,s,0);
	REP(i,n+1,n+m) addedge(i+1,t,1),addedge(t,i+1,0);
	REP(i,1,e) {
		int u=read(),v=read();
		if(u>n||v>m) continue;
		addedge(u+1,v+n+1,1);
		addedge(v+n+1,u+1,0);
	}
	int ans=0;

	while(bfs()) {
		REP(i,1,n+m+2) cur[i]=head[i];
		while(1) {
			int x=dfs(s,INF);
			if(!x) break;
			ans+=x;
		}
	}	

	printf("%d\n",ans);

	return 0;
}

