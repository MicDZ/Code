#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

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

const int MAXN=500+10;

int n,m,a[MAXN],b[MAXN],dp[MAXN][MAXN],ans[MAXN][MAXN];

void print(int j) {
	if(!j) return ;
	print(ans[n][j]);
	printf("%d ",b[j]-1);
}

int main() {
	n=read(),m;
	REP(i,1,n) a[i]=read()+1;
	m=read();
	REP(i,1,m) b[i]=read()+1;
	
	REP(i,1,n) REP(j,1,m) {
	ans[i][j]=ans[i-1][j];
		if(a[i]!=b[j]) dp[i][j]=dp[i-1][j];
		else {
			REP(k,0,j-1) 
				if(b[k]<a[i]) {
					if(dp[i-1][k]+1>dp[i][j]) {
						dp[i][j]=dp[i-1][k]+1;
						ans[i][j]=k;
					}
				}
		}
	}

	int pos=0,ans=0;
	REP(i,1,m) if(dp[n][i]>ans) ans=dp[n][i],pos=i;
	printf("%d\n",ans);
	print(pos);
	return 0;
}
