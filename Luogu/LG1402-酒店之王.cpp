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

int n,m,s,t;

const int MAXN=100000+10,MAXM=2000000+10,INF=0x3f3f3f3f;

int cur[MAXN],head[MAXN],to[MAXM],_next[MAXM],weigh[MAXM],cnt=1;

void addedge(int u,int v,int w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
}

int k1,k2;


queue<int> q;

int dept[MAXN];

bool bfs() {
	memset(dept,-1,sizeof(dept));
	dept[s]=0;
	q.push(s);
	while(!q.empty()) {
		int u=q.front();q.pop();
		for(int i=head[u]; i!=-1; i=_next[i]) {
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
	int sum=0,ft=0;
	for(int i=cur[u]; i!=-1; i=_next[i]) {
		cur[u]=i;
		int v=to[i];
		if(dept[v]==dept[u]+1&&weigh[i]>0&&(ft=dfs(v,min(weigh[i],minn-sum)))) {
			weigh[i]-=ft;
			weigh[i^1]+=ft;
			sum+=ft;
		}
	}
	return sum;
}
int main() {
	n=read();
	k1=read(),k2=read();
	s=0,t=100000;
	memset(head,-1,sizeof(head));
	REP(i,1,k1) addedge(s,i,1),addedge(i,s,0);
	REP(i,1,k2) addedge(i+k1,t,1),addedge(t,i+k1,0);

	REP(i,1,n) addedge(i+k1+k2,i+k1+k2+n,1),addedge(i+k1+k2+n,i+k1+k2,0);
	
	int num=read();

	REP(t,1,num) {
		int i=read(),j=read();
		addedge(j,i+k1+k2,1),addedge(i+k1+k2,j,0);
	}
	num=read();
	REP(t,1,num) {
		int i=read(),j=read();
		addedge(i+n+k1+k2,k1+j,1),addedge(k1+j,i+n+k1+k2,0);
	} 
	int ans=0;
	while(bfs()) {
		REP(i,0,n+k1+k2+n) cur[i]=head[i];
		int x=dfs(s,INF);
		if(!x) break;
		ans+=x;
	}

	printf("%d\n",ans);
	return 0;
}


