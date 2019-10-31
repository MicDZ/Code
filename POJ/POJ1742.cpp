#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>

using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int MAXN=100+10;
int a[MAXN],dp[MAXN],num[100000+10];

int main() {
	int n=read(),m=read();
	if(n==0&&m==0) return 0;
	REP(i,1,n) a[i]=read();
	REP(i,1,n) num[i]=read();
	
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	REP(i,1,n) REP(j,0,m) {
		if(dp[j]>=0) dp[j]=num[i];
		else {
			if(j<a[i]||dp[j-a[i]]<=0) dp[j]=-1;
			else dp[j]=dp[j-a[i]]-1;
		}
	}
	int ans=0;
	REP(i,1,m) 
		if(dp[i]>=0) ans++; 
	printf("%d\n",ans);
	main();
	return 0;
}
