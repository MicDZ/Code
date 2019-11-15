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

const int MAXN=2000+10,MAXM=6000+10,INF=0x3f3f3f3f;

int n,m;

int head[MAXN],_next[MAXM],to[MAXM],weigh[MAXM],cnt;

void addedge(int u,int v,int w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
}

int inq[MAXN],pd[MAXN],dist[MAXN];

queue<int> q;

bool SPFA(int s) {
	REP(i,1,n) dist[i]=INF,inq[i]=0,pd[i]=0;
	while(!q.empty()) q.pop();
	q.push(s);dist[s]=0;inq[s]=1;
	while(!q.empty()) {
		int u=q.front();q.pop();inq[u]=0;
		if(pd[u]>=n) return 1;
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(dist[v]>dist[u]+weigh[i]) {
				dist[v]=dist[u]+weigh[i];
				if(!inq[v]) {
					inq[v]=1;
					q.push(v);
					pd[u]++;if(pd[u]>=n) return 1;
				}
			}
		}
	}
	return 0;
}

int main() {
	file("SPFA-负环");
	int t=read();
	while(t--) {
		n=read(),m=read();
		REP(i,1,n) head[i]=0;cnt=0;
		REP(i,1,m) {
			int u=read(),v=read(),w=read();
			if(w<0) addedge(u,v,w);
			else addedge(u,v,w),addedge(v,u,w);
		}
		if(SPFA(1)) puts("YE5");
		else puts("N0");
	}
	return 0;
}

