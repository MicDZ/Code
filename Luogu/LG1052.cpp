#include<bits/stdc++.h>
using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int INF=0x3f3f3f;
int a[110],b[110],stone[350010],dp[350010];

int main() {
	int l=read(),s=read(),t=read(),m=read();
	REP(i,1,m) a[i]=read();
	sort(a+1,a+1+m);
	
	REP(i,1,m) b[i]=(a[i]-a[i-1])%2520;
	REP(i,1,m) a[i]=a[i-1]+b[i],stone[a[i]]=1;
	
	int len=a[m]+t;

	REP(i,1,len) dp[i]=INF;
	dp[0]=0;

	REP(i,1,len) REP(j,s,t) {
		if(i-j>=0) dp[i]=min(dp[i],dp[i-j]);
		dp[i]+=stone[i];
	}

	int ans=INF;

	REP(i,a[m],len) ans=min(ans,dp[i]);

	printf("%d\n",ans);
}
