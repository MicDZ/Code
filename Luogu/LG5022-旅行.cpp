#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
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

const int MAXN=5000+10,INF=0x3f3f3f;

vector<pair<int,int> > g[MAXN];

int vis[MAXN],ans[MAXN],num;

void dfs(int u) {
	ans[++num]=u;vis[u]=1;
	REP(i,0,(int)g[u].size()-1) {
		int v=g[u][i].first;
		if(vis[v]) continue;
		dfs(v);
	}
}
int ans2[MAXN][MAXN];
void dfs(int u,int cut) {
	ans2[cut][++num]=u;vis[u]=1;
	REP(i,0,(int)g[u].size()-1) {
		int v=g[u][i].first;
		if(vis[v]||g[u][i].second==cut) continue;
		dfs(v,cut);
	}
}

int book[MAXN];

int dept[MAXN],huan[MAXN],fa[MAXN];

int main() {
	//file("travel");
	int n=read(),m=read();
	REP(i,1,m) {
		int u=read(),v=read();
		g[u].push_back(make_pair(v,i));
		g[v].push_back(make_pair(u,i));
	}
	REP(i,1,n) sort(g[i].begin(),g[i].end());

	if(m==n-1) {
		dfs(1);
		REP(i,1,n) printf("%d ",ans[i]);
	}
	if(m==n) {
		REP(i,1,m) {
			num=0;
			REP(j,1,n) vis[j]=0;
			dfs(1,i);
		}
		REP(i,1,m) REP(j,1,n) if(!ans2[i][j]) ans2[i][j]=INF;
		REP(i,1,n) {
			int minn=INF;
			REP(j,1,m) if(!book[j]) minn=min(minn,ans2[j][i]);
			REP(j,1,m) if(ans2[j][i]>minn) book[j]=1;
		}
		int pos;
		REP(i,1,m) if(!book[i]) pos=i;
		REP(i,1,n) printf("%d ",ans2[pos][i]);
	}
	//
	return 0;
}

