#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a)	freopen(a".in","r",stdin);freopen(a".out","w",stdout)
using namespace std;

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
#define ll long long
const int MAXN=205+10,MAXM=MAXN*MAXN,INF=0x3f3f3f3f;
/*
int head[MAXN],_next[MAXM],to[MAXM],cnt,weigh[MAXM];

void addedge(int u,int v,int w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}
*/
struct edge {
	int u,v,w;
	#define u(x) a[x].u
	#define v(x) a[x].v
} a[MAXM];

ll f[MAXN][MAXN],dp[MAXN],c[MAXN];
bool cmp(int a,int b) {return dp[a]>dp[b];}

int main() {
	int n=read(),m=read();	
	REP(i,1,n) REP(j,1,n) f[i][j]=INF;REP(i,0,n) f[i][i]=0;
	REP(i,1,m) {
		int u=read(),v=read(),w=read();
		//addedge(u,v,w);
		a[i]=(edge){u,v,w};
		f[u][v]=f[v][u]=min(f[u][v],(ll)w);
	}
	REP(k,1,n) REP(i,1,n) REP(j,1,n) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	ll ans=INF;
	REP(i,1,m) {
		REP(j,1,n) c[j]=j,dp[j]=f[u(i)][j];
		sort(c+1,c+n+1,cmp);
		ll sum=0;
		REP(j,1,n) {
			int v=c[j];
			ll t=f[u(i)][v]+a[i].w+sum;
			if(t>=f[u(i)][v]*2&&t<=(f[u(i)][v]+a[i].w)*2) ans=min(ans,t);
			sum=max(sum,f[v(i)][v]);
		}
	}

	printf("%lf\n",1.*ans/2);
	return 0;
}

