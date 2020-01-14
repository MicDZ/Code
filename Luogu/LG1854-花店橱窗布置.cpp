#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

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

const int MAXN=2000+10;

int a[MAXN][MAXN],dp[MAXN][MAXN],pre[MAXN][MAXN];

void print(int x,int y) {
	if(pre[x][y]==y) {printf("%d ",y);return ;}
	print(x-1,pre[x][y]);
	printf("%d ",y);
}

int main() {
	int n=read(),m=read();
	REP(i,1,n) REP(j,1,m) a[i][j]=read();
	REP(i,1,m-n) dp[1][i]=a[1][i],pre[1][i]=i;

	REP(i,2,n) REP(j,i,m+i-n) REP(k,1,j-1) 
		if(dp[i-1][k]+a[i][j]>dp[i][j]) {
			dp[i][j]=dp[i-1][k]+a[i][j];
			pre[i][j]=k;
		}
	
	int ans=0,k;

	REP(i,n,m) if(dp[n][i]>ans) {
		ans=dp[n][i];
		k=i;
	}

	printf("%d\n",ans);
	print(n,k);
	return 0;
}

