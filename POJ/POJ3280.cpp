#include<iostream>
#include<cstdio>

using namespace std;
#define REP(i,e,s) for(register int i=e; i<=s; i++)
int read() {
    int x=0,f=1,ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

const int MAXN=2000+10;
char a[MAXN];
int dp[MAXN][MAXN],del[MAXN],add[MAXN];
int main() {
	int n=read(),m=read();
	REP(i,1,m) a[i]=getchar();
	getchar();
	REP(i,1,n) {
		char x;scanf("%c",&x);
		add[x]=read();
		del[x]=read();
	}
	REP(l,2,m) for(int i=1; l+i-1<=m; i++) {
		int j=i+l-1;
		if(a[i]==a[j]) dp[i][j]=dp[i+1][j-1];
		else dp[i][j]=min(dp[i+1][j]+min(add[a[i]],del[a[i]]),dp[i][j-1]+min(add[a[j]],del[a[j]]));
	}

	printf("%d\n",dp[1][m]);
	return 0;
}
