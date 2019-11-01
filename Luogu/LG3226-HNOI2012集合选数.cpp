#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define int ll
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

const int MAXN=100000+10,MOD=1000000001;

int n,a[25][25],vis[MAXN],c,r[MAXN],dp[25][2048+10];

int work() {
	memset(dp,0,sizeof(dp));
	REP(s,0,(1<<r[1])-1) dp[1][s]=!((s<<1)&s);
	REP(i,2,c) {
		REP(s,0,(1<<r[i])-1) {
			if((s<<1)&s) continue;
			REP(t,0,(1<<r[i-1])-1) {
				if((t<<1)&t) continue;
				if(t&s) continue;
				dp[i][s]=(dp[i][s]+dp[i-1][t])%MOD;
			}
		}
	}

	int ans=0;
	REP(s,0,(1<<r[c])-1) ans=(ans+dp[c][s])%MOD;
	return ans;

}

int calc(int x) {
	for(int i=1; ; i++) {
		if(i==1) a[1][1]=x;
		else a[i][1]=2*a[i-1][1];
		if(a[i][1]>n) {
			c=i-1;
			break;
		}
		vis[a[i][1]]=1;
		for(int j=2; ; j++) {
			a[i][j]=a[i][j-1]*3;
			if(a[i][j]>n) {
				r[i]=j-1;
				break;
			}
			vis[a[i][j]]=1;
		}
	}
	return work();
}

signed main() {
	n=read();int ans=1;
	REP(i,1,n) 
		if(!vis[i]) ans=ans*calc(i)%MOD;
	printf("%lld\n",ans);
	return 0;
}
