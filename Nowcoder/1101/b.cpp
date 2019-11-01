#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

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

const int MAXN=1000000+10,MAXM=2000000+10,INF=0x3f3f3f3f3f3f;

int head[MAXN],to[MAXM<<1],_next[MAXM<<1],cnt=1;

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

int dept[MAXN],fa[MAXN],edge[MAXN],have[MAXM<<1],num;

vector<int> g[MAXN];
int vis[MAXN],sz[MAXN],sum;
void dfs(int u,int fat) {
	dept[u]=dept[fat]+1;
	vis[u]=1;
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(fat==v) continue;
		if(vis[v]) {
			if(dept[u]<dept[v]) continue;
			sz[++num]=dept[u]-dept[v]+1;
			sum+=sz[num];
			continue;
		}
		dfs(v,u);
	}
}

bool cmp(int a,int b) {
	return a>b;
}

signed main() {
	file("3");
	int n=read(),m=read(),k=read();
	REP(i,1,m) {
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
	
	REP(i,1,n) dept[i]=INF;
	int ans=0;
	
	REP(i,1,n) {
		if(!vis[i]) {
			dfs(i,0);
			ans++;
		}	
	}
	sum=m-sum;
	if(sum>=k) {printf("%lld\n",ans+k);return 0;}
	ans+=sum; k-=sum;
	sort(sz+1,sz+1+num,cmp);
	REP(i,1,num) {
		if(k<=sz[i]) {
			printf("%d\n",ans+k-1);
			return 0;
		}
		ans+=sz[i]-1;k-=sz[i];
	}

	printf("%d\n",ans);
	return 0;
}
