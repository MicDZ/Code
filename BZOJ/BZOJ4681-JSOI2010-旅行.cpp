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

const int MAXN=50+10,MAXM=150+10,MAXW=1000+10,INF=0x3f3f3f3f;

int head[MAXN],_next[MAXM<<1],to[MAXM<<1],weigh[MAXM<<1],cnt;

void addedge(int u,int v,int w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
}

struct edge {
	int x,y,z,w;
} ;

bool operator < (edge a,edge b) {
	return a.w>b.w;
}

priority_queue<edge> q;

int n,m,k,book[MAXN],dist[MAXN],wei[MAXN],f[MAXN][MAXM][22];

int base=0,ans=INF;

void push(int l,int x,int y,int z,int w) {
	if(y>l||z>k) return ;
	if(f[x][y][z]<=w) return ;
	q.push((edge){x,y,z,w});
}

void Dij(int lim,int l) {
	
	base+=lim;
	if(base>=ans) return;
	q.push((edge){1,0,0,base});
	memset(f,127,sizeof(f));
	while(!q.empty()) {
		DE("in\n");
		int x=q.top().x,y=q.top().y,z=q.top().z,w=q.top().w;
		q.pop();
		if(f[x][y][z]<w) continue;
		for(int i=head[x]; i; i=_next[i]) {
			int v=to[i];
			if(weigh[i]<=lim) push(l,v,y+1,z,w); 
			else {
				push(l,v,y,z,w+weigh[i]);
				push(l,v,y,z+1,w);
			}
		}
	}
	REP(i,0,l) REP(j,0,k) if(i+j<=l&&f[n][i][j]<ans) ans=f[n][i][j];
}

int main() {
	n=read(),m=read(),k=read();

	REP(i,1,m) {
		int u=read(),v=read(),w=read();
		addedge(u,v,w);
		addedge(v,u,w);
		wei[w]=w;
	}
	sort(wei+1,wei+1+m);
	REP(i,0,m) Dij(wei[i],i);
	
	printf("%d\n",ans);
	return 0;
}

