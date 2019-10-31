#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
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

const int MAXN=2000+10,MAXP=2e6+10;

char a[MAXN][MAXN];

struct build {
	int x,y;
} c[MAXP];

int n,m,p,q;

int dis[MAXN][MAXN],nby[MAXN][MAXN];

queue<build> qu;

int dx[]={0,1,-1,0,0},
	dy[]={0,0,0,1,-1};

int have[MAXN][MAXN];

struct edge {
	int u,v,w;
} e[MAXN*MAXN*4];

int num;

int dept[MAXP<<1],f[MAXP<<1][30];

queue<int> q2;

int fa[MAXP<<1];

int find(int x) {
	if(fa[x]==x) return fa[x];
	return fa[x]=find(fa[x]);
}

int head[MAXP<<1],to[MAXP<<1],_next[MAXP<<1],weigh[MAXP<<1],cnt;

bool cmp(edge a,edge b) {
	return a.w<b.w;
}

void addedge(int u,int v,int w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
}

void bfs(int s) {
	q2.push(s);
	while(!q2.empty()) {
		int u=q2.front();q2.pop();
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(f[u][0]==v) continue;
			f[v][0]=u;
			dept[v]=dept[u]+1;
			q2.push(v);
		}
	}
}

int w[MAXP<<1];

void link(int x,int y) {
	fa[find(x)]=find(y);
}

void kruskal() {
	sort(e+1,e+1+num,cmp);
	REP(i,1,p*2) fa[i]=i;
	int um=p;
	REP(i,1,num) {
		//DE("%d %d %d \n",e[i].u,e[i].v,e[i].w);
		int u=find(e[i].u),v=find(e[i].v);
		if(u==v) continue;
		um++;
		addedge(um,find(e[i].u),e[i].w);
		addedge(um,find(e[i].v),e[i].w);
		link(u,um);
		link(v,um);
		w[um]=e[i].w;
	}
	REP(i,1,num) if(!dept[i]) bfs(find(i));
}



void init() {
	REP(i,1,n) REP(j,1,m) {
		if(a[i][j]=='#') continue;
		REP(t,1,4) {
			if(t==2||t==4) continue;
			int xx=i+dx[t],yy=j+dy[t];
			if(xx<1||xx>n||yy<1||yy>m||a[xx][yy]=='#') continue;
			if(nby[xx][yy]!=nby[i][j]) { 
				e[++num]=(edge){nby[i][j],nby[xx][yy],dis[i][j]+dis[xx][yy]};
			}
		}
	}
	kruskal();
}

void bfs1() {
	memset(dis,127,sizeof(dis));
	REP(i,1,p) {
		nby[c[i].x][c[i].y]=i,dis[c[i].x][c[i].y]=0;
		qu.push(c[i]);
	}
	while(!qu.empty()) {
		int x=qu.front().x,y=qu.front().y;qu.pop();
		REP(i,1,4) {
			int xx=x+dx[i],yy=y+dy[i];
			if(xx<1||xx>n||yy<1||yy>m||a[xx][yy]=='#'||nby[xx][yy]) continue;
			nby[xx][yy]=nby[x][y],dis[xx][yy]=dis[x][y]+1;
			qu.push((build){xx,yy});
		}
	}
	init();
}

int lca(int u,int v) {
	if(dept[v]<dept[u]) swap(u,v);
	int len=dept[v]-dept[u];
	DREP(i,20,0) if((1<<i)&len) v=f[v][i];
	if(u==v) return u;
	DREP(i,20,0) if(f[u][i]!=f[v][i]) u=f[u][i],v=f[v][i];
	return f[u][0];
}

int main() {
	file("14");
	n=read(),m=read(),p=read(),q=read();
	REP(i,1,n) scanf("%s",a[i]+1);
	REP(i,1,p) c[i]=(build){read(),read()};
	bfs1();
	REP(j,1,20) REP(i,1,2*p) f[i][j]=f[f[i][j-1]][j-1];
	while(q--) {
		int u=read(),v=read();
		if(find(u)!=find(v)) puts("-1");
		else printf("%d\n",w[lca(u,v)]);
	}
	return 0;
}
