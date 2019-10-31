#include<bits/stdc++.h>
using namespace std;
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=200000+10;

int n,m,a[MAXN],head[MAXN],_next[MAXN],to[MAXN],cnt,fa[MAXN][20],dept[MAXN],ans[MAXN],apd[MAXN],apdi[MAXN];

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

void dfs(int x) {
	if(apd[a[x]]<=dept[x]) {
		apd[a[x]]=dept[x];
		apdi[a[x]]=x;
	}
	for(int i=head[x]; i; i=_next[i]) {
		int y=to[i];
		//if(fa[x][0]==y) continue;
		fa[y][0]=x;
		dept[y]=dept[x]+1;
		dfs(y);
		
	}
}

int lca(int u,int v) {
	if(dept[u]<dept[v]) swap(u,v);
	int h1=dept[u]-dept[v];
	DREP(i,17,0)
		if((1<<i)&h1) u=fa[u][i];
	if(u==v) return u;


	DREP(i,18,0) 	
		if(fa[u][i]!=fa[v][i]) {
			u=fa[u][i];
			v=fa[v][i];
		}
	return fa[u][0];
}


int main() {
	int n=read(),k=read();
	int _root;
	REP(i,1,n) {
		a[i]=read();
		int v=read();
		addedge(v,i);
		if(v==0) _root=i;
	}
	dept[_root]=1;
	dfs(_root);

	REP(j,1,17) REP(i,1,n)
		fa[i][j]=fa[fa[i][j-1]][j-1];	

	//printf("%d %d\n",fa[2][0],fa[5][0]);

	REP(i,1,n) { 
		//printf("%d %d %d\n",i,apdi[a[i]],lca(i,apdi[a[i]]));
		ans[a[i]]=max(ans[a[i]],apd[a[i]]+dept[i]-2*dept[lca(apdi[a[i]],i)]);
	}
	

	REP(i,1,k) printf("%d\n",ans[i]);
	return 0;
}
/*
6 2 
1 3 
2 1 
1 0 
2 1 
2 1 
1 5
*/
