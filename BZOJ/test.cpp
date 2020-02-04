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

const int MAXN=55,MAXM=155,INF=0x3f3f3f3f;

int n,m,k,base,ans=INF,f[MAXN][MAXM][22];

//priority_queue<P,vector<P>,greater<P> >q;

struct node {
	int x,y,z,w;
} ;

bool operator<(node a,node b) {
	if(a.w==b.w) {
		pair<int,pair<int,int> > _a=make_pair(a.x,make_pair(a.y,a.z)),_b=make_pair(b.x,make_pair(b.y,b.z));
		return _a<_b;
	}
	return a.w>b.w;
}

priority_queue<node> q;

struct edge {
	int x,y,w;
} e[MAXM];

bool operator<(edge a,edge b) {
	return a.w<b.w;
}

int head[MAXN],_next[MAXM<<1],to[MAXM<<1],weigh[MAXM<<1],cnt;

void addedge(int u,int v,int w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
}

void push(int l,int x,int y,int z,int w) {
	if(y>l||z>k) return;
	if(f[x][y][z]<=w) return;
	f[x][y][z]=w;
	q.push((node){x,y,z,w});
}

void Dij(int l) {
	base+=e[l].w;
	if(base>=ans) return;
	memset(f,127,sizeof(f));
	push(l,1,0,0,base);
	while(!q.empty()){
		node t=q.top();q.pop();
		int x=t.x,y=t.y,z=t.z;
		if(f[x][y][z]<t.w)continue;
		for(int i=head[x]; i; i=_next[i]) {
			if(i<=l*2) push(l,to[i],y+1,z,t.w);
			else {
				push(l,to[i],y,z,t.w+weigh[i]);
				push(l,to[i],y,z+1,t.w);
			}
		}
	}
	REP(i,0,l) REP(j,0,k) if(i+j<=l) ans=min(ans,f[n][i][j]);

}

int main(){
	freopen("data.in","r",stdin);
	n=read(),m=read(),k=read();
	REP(i,1,m) e[i].x=read(),e[i].y=read(),e[i].w=read();
	sort(e+1,e+m+1);
	REP(i,1,m) addedge(e[i].x,e[i].y,e[i].w),addedge(e[i].y,e[i].x,e[i].w);
	REP(l,0,m) Dij(l);
	printf("%d",ans);
	return 0;
}
