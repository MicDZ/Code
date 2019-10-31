#include<bits/stdc++.h>
using namespace std;

#define MAXN 4000+10
#define REP(i, s, e) for(register int i=s; i<=e; i++)

int read() {
	char ch=getchar();
	int x=0,f=1;
	while(ch>'9'||ch<'0') {if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,a[MAXN][MAXN],match[MAXN],have[MAXN];

int dfs(int k) {
	
}

int main() {
	freopen("P2071.in","r",stdin);
	freopen("P2071.out","w",stdout);
	n=read();
	REP(i,1,n<<1) {
		int u=read(),v=read();
		a[u][v]=1;
	}

	int ans=0;
	REP(i,1,n<<1) {
		memset(have,0,sizeof(have));
		ans+=dfs(i);
	}
	return 0;
}
