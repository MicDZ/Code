#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;
#define int ll
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

const int MAXN=2000+10,INF=0x3f3f3f3f3f3f3f3f;

int a[MAXN][MAXN];

priority_queue<pair<int,int> > q;
int dist[MAXN],vis[MAXN],id[MAXN];

signed main() {
	int n=read(),cnt=0;
	
	REP(i,1,n) REP(j,i,n) a[i-1][j]=a[j][i-1]=read();

	REP(i,0,n) dist[i]=a[1][i];	
	
	vis[1]=1;
	int ans=0;
	REP(u,1,n) {
		int minn=INF,pos;
		REP(i,0,n) if(!vis[i]&&dist[i]<minn) minn=dist[i],pos=i;
		ans+=minn;vis[pos]=1;
		REP(i,0,n) dist[i]=min(dist[i],a[pos][i]);
	}

	printf("%lld\n",ans);
	return 0;
}
