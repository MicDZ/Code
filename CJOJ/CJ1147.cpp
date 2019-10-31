#include<bits/stdc++.h>
using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=2000+10;

int a[MAXN][MAXN],cnt[MAXN],vis[MAXN],n,m;

void dfs(int x) {
	printf("%d ",x);
	REP(i,1,n) {
		if(a[x][i]<=0) continue;
		a[x][i]--;
		a[i][x]--;
		dfs(i);
	}
}

int main() {
	n=read(),m=read();
	REP(i,1,m) {
		int u=read(),v=read();
		a[u][v]++;
		a[v][u]++;
		cnt[u]++;
		cnt[v]++;
	}
	
	REP(i,1,n)  
		if(cnt[i]&1) { 
			dfs(i);
			return 0;
		}
	dfs(1);
	return 0;
}
