#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

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

const int MAXN=5000+10,INF=0x3f3f3f3f;

int g[MAXN][MAXN];

int dist[MAXN],vis[MAXN];

int main() {
	int n=read(),m=read();
	memset(g,127,sizeof(g));
	REP(i,1,m) {
		int u=read(),v=read(),w=read();
		g[u][v]=g[v][u]=min(g[u][v],w);
	}
	memset(dist,127,sizeof(dist));
	dist[1]=0;
	int ans=0;
	REP(i,1,n) {
		int minp=0,minn=INF;
		REP(j,1,n) {
			if(vis[j]) continue;
			if(dist[j]<minn) {
				minn=dist[j];
				minp=j;
			}
		}
		vis[minp]=1;
		REP(j,1,n) if(g[minp][j]!=g[0][0]) dist[j]=min(dist[j],g[minp][j]);
		ans+=minn;
	}
	printf("%d\n",ans);
	return 0;
}

