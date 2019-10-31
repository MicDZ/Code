#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)

int read() {
    int x=0,f=1,ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

const int MAXN=200000+10,INF=1<<30;

int n,r,_next[MAXN],head[MAXN],to[MAXN],weigh[MAXN],cnt;

void addedge(int u,int v,int w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
}
int dis1[MAXN],dis2[MAXN],inq[MAXN];

void SPFA1(int st) {
	queue<int> q;
	q.push(st);
	memset(inq,0,sizeof(inq));
	memset(dis1,1,sizeof(dis1));
	dis1[st]=0;
	while(!q.empty()) {
		int u=q.front();q.pop();
		inq[u]=0;
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(dis1[v]>dis1[u]+weigh[i]) {
				dis1[v]=dis1[u]+weigh[i];
				if(!inq[v]) {
					q.push(v);
					inq[v]=1;
				}
			} 
		}
	}
}
void SPFA2(int st) {
	queue<int> q;
	q.push(st);
	memset(inq,0,sizeof(inq));
	memset(dis2,1,sizeof(dis2));
	dis2[st]=0;
	while(!q.empty()) {
		int u=q.front();q.pop();
		inq[u]=0;
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(dis2[v]>dis2[u]+weigh[i]) {
				dis2[v]=dis2[u]+weigh[i];
				if(!inq[v]) {
					q.push(v);
					inq[v]=1;
				}
			} 
		}
	}
}

struct edge{
	int u,v,w;
}a[MAXN];
int pc[5000+1][5000+1];
int main() {
		//freopen("POJ3255.in","r",stdin);
	n=read(),r=read();
	memset(pc,1,sizeof(pc));
	REP(i,1,r) {
		int u=read(),v=read(),w=read();
		if(u>v) swap(u,v);
		a[i].u=u;a[i].v=v;a[i].w=w;
		pc[u][v]=min(pc[u][v],w);
	}
	
	REP(i,1,r) {
		if(pc[a[i].u][a[i].v]==a[i].w) addedge(a[i].u,a[i].v,a[i].w),addedge(a[i].v,a[i].u,a[i].w);
	}

	SPFA1(1);
	SPFA2(n);
	int ans=INF;
	REP(i,1,r) {
		int d1=dis1[a[i].u],d2=dis2[a[i].v];
		if(dis1[a[i].u]>dis1[a[i].v]) swap()
		int s=a[i].w+dis1[a[i].u]+dis2[a[i].v];
		if(s>dis1[n]&&ans>s) ans=s;
	}

	printf("%d\n",ans);
}
