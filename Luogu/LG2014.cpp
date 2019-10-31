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

const int MAXN=300+10;
int n,m,dp[MAXN][MAXN],_next[MAXN],to[MAXN],head[MAXN],score[MAXN],cnt;
void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

void dfs(int x) {
	dp[x][0]=0;
	for(int i=head[x]; i; i=_next[i]) {
		int y=to[i];
		dfs(y);
		DREP(t,m,0) DREP(j,t,0) 
			if(t-j>=0) dp[x][t]=max(dp[x][t],dp[x][t-j]+dp[y][j]);
	}
	if(x!=0) DREP(i,m,1) dp[x][i]=dp[x][i-1]+score[x];
}

int main() {
	n=read(),m=read();
	REP(i,1,n) {
		int fa=read();
		score[i]=read();
		addedge(fa,i);
	}

	dfs(0);

	printf("%d\n",dp[0][m]);
}
