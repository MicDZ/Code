#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>
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

const int MAXN=50000+10;

int n,m,head[MAXN],to[MAXN<<1],weigh[MAXN<<1],_next[MAXN<<1],cnt;

void addedge(int u,int v,int w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
}

int fa[MAXN][25],dist[MAXN][25];

queue<int> q;

void bfs(int s) {
	q.push(s);
	while(!q.empty()) {
		int u=q.front();q.pop();
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(fa[u][0]==v) continue;
			fa[v][0]=u;
			dist[v][0]=weigh[i];
			q.push(v);
		}
	}
}

int army[MAXN],tag[MAXN],cntarmy,cntrest;

struct ary {
	int s,id;
} arm[MAXN],res[MAXN];

int cnt_arm,cnt_res;

void dfs(int u) {
	bool re=1,fl=0;
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(fa[u][0]==v) continue;
		dfs(v);
		re&=tag[v];
		fl=1;
	}
	if(u!=1&&re&&fl) tag[u]=1;
}

bool const operator <(ary a,ary b) {
	return a.s<b.s;
}

bool check(int lim) {
	memset(tag,0,sizeof(tag));
	cnt_arm=cnt_res=0;
	REP(i,1,m) {
		int x=army[i];
		int sum=0;
		DREP(j,20,0) 
			if(fa[x][j]!=1&&fa[x][j]>0&&lim-sum-dist[x][j]>=0) 
				sum+=dist[x][j],x=fa[x][j];
		int left=lim-sum-dist[x][0];
		if(fa[x][0]==1&&left>=0) 
			arm[++cnt_arm]=(ary){left,x};
		else tag[x]=1;
	}
	dfs(1);
	for(int i=head[1]; i; i=_next[i]) {
		int v=to[i];
		if(!tag[v]) 
			res[++cnt_res]=(ary){weigh[i],v};
	}
	sort(arm+1,arm+cnt_arm+1);
	sort(res+1,res+cnt_res+1);
	int cnt=1;

	REP(i,1,cnt_arm) {
		if(!tag[arm[i].id]) 
			tag[arm[i].id]=1;
		else if(arm[i].s>=res[cnt].s) 
			tag[res[cnt].id]=1;
        while(tag[res[cnt].id]&&cnt<=cnt_res) 
			cnt++;
	}
	
	return cnt_res<cnt;
}

int main() {
	n=read();
	REP(i,1,n-1) {
		int u=read(),v=read(),w=read();
		addedge(u,v,w);
		addedge(v,u,w);
	}
	bfs(1);
	
	REP(j,1,20) REP(i,1,n) fa[i][j]=fa[fa[i][j-1]][j-1];
	REP(j,1,20) REP(i,1,n) dist[i][j]=dist[i][j-1]+dist[fa[i][j-1]][j-1];
	
	m=read();
	REP(i,1,m) army[i]=read();
	int l=1,r=500001;
	while(l<r) {
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",r==500001?-1:r);
	return 0;
}
/*
4 
1 2 1 
1 3 2 
3 4 3 
2 
2 2
*/
