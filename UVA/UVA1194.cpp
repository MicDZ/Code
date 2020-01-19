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

const int MAXN=10000+10;

int head[MAXN],_next[MAXN<<1],to[MAXN<<1],cnt;

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

int vis[MAXN],f[MAXN];

bool dfs(int u) {
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(vis[v]) continue;
		vis[v]=1;
		if(!f[v]||dfs(f[v])) {
			f[v]=u;
			return 1;
		}
	}
	return 0;
}

int main() {
	int n;
	while(~scanf("%d",&n)&&n) {
		int m=read(),k=read();
		memset(head,0,sizeof(head));cnt=0;
		REP(i,1,k) {
			read();
			int x=read(),y=read();
			addedge(x,y);	

		}
		memset(f,0,sizeof(f));
		int ans=0;
		REP(i,1,n) {
			memset(vis,0,sizeof(vis));
			ans+=dfs(i);
		}
		printf("%d\n",ans);
	}
	return 0;
}

