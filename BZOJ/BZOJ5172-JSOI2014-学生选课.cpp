#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

#define REP(i,e,s) for(register int i=(e); i<=(s); i++)
#define DREP(i,e,s) for(register int i=(e); i>=(s); i--)
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define ll long long
#define pos(x,y) (y*(n+1)+x)
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=2000+10;

int n,a[MAXN],f[MAXN][MAXN],mark[MAXN][2];

vector<int> g[MAXN*3];

int tot,ins[MAXN*3],dfn[MAXN*3],low[MAXN*3],id[MAXN*3],color;

stack<int> s;

void tarjan(int u) {
	dfn[u]=low[u]=++tot;
	s.push(u);ins[u]=1;
	REP(i,0,(int)g[u].size()-1) {
		int v=g[u][i];
		if(!dfn[v]) {
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(ins[v]) 
			low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]) {
		color++;
		int v;
		do {
			v=s.top();s.pop();
			id[v]=color;
			ins[v]=0;
		} while(u!=v);
	}
}

bool check(int mid) {
	REP(i,0,3*n+10) g[i].clear(),tot=dfn[i]=id[i]=low[i]=color=0;
	while(s.size()) s.pop();
	REP(i,1,n) REP(j,i+1,n) {
		if(f[i][j]<=mid) continue;
		if(mark[i][0]==mark[j][0]) g[pos(i,mark[i][0])].push_back(pos(j,mark[j][1])),
								   g[pos(j,mark[j][0])].push_back(pos(i,mark[i][1]));
		if(mark[i][0]==mark[j][1]) g[pos(i,mark[i][0])].push_back(pos(j,mark[j][0])),
								   g[pos(j,mark[j][1])].push_back(pos(i,mark[i][1]));
		if(mark[i][1]==mark[j][0]) g[pos(i,mark[i][1])].push_back(pos(j,mark[j][1])),
								   g[pos(j,mark[j][0])].push_back(pos(i,mark[i][0]));
		if(mark[i][1]==mark[j][1]) g[pos(i,mark[i][1])].push_back(pos(j,mark[j][0])),
								   g[pos(j,mark[j][1])].push_back(pos(i,mark[i][0]));
	}
	REP(i,1,n) REP(j,0,2) if(!dfn[pos(i,j)]&&a[i]!=j) tarjan(pos(i,j));
	REP(i,1,n) if(id[pos(i,mark[i][0])]==id[pos(i,mark[i][1])]) return 0;
	return 1;
}

int main() {
	n=read();
	REP(i,1,n) {
		a[i]=read();
		mark[i][0]=(a[i]==0?1:0);
		mark[i][1]=(a[i]==2?1:2);
		REP(j,1,n-1) {
			int x=read();
			f[i][x]=j;
		}
	}
	REP(i,1,n) REP(j,i+1,n) f[i][j]=max(f[i][j],f[j][i]);
	int l=1,r=n;
	while(l<r) {
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	
	printf("%d\n",r);
	return 0;
}

