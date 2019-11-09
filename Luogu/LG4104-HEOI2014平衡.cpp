#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;
#define int ll
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

int dp[MAXN*10][11];

signed main() {
	int t=read();
	while(t--) {
		int n=read(),k=read(),p=read();
		
		dp[0][0]=1;

		REP(i,1,n*k) REP(j,1,min(k,i)) {
			dp[i][j]=(dp[i-j][j]+dp[i-j][j-1])%p;
			if(i>n) dp[i][j]=(dp[i][j]-dp[i-n-1][j-1]+p)%p;
		}
		int ans=0;
		REP(i,0,n*k) REP(j,0,k) {
			ans=(ans+dp[i][j]*dp[i][k-j])%p;
			if(j<k) ans=(ans+dp[i][j]*dp[i][k-j-1])%p;
		}

		printf("%lld\n",ans);
	}
	return 0;
}

