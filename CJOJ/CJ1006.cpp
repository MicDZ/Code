#include<bits/stdc++.h>
using namespace std;
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define ll long long
int read() {
    int x=0,f=1,ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

const int MAXN=100+10;

int a[15],dp[MAXN];

int main() {
	REP(i,1,10) a[i]=read();
	int n=read();
	memset(dp,1,sizeof(dp));
	
	dp[0]=0;

	REP(i,1,10) REP(j,i,n) dp[j]=min(dp[j-i]+a[i],dp[j]);
	
	printf("%d\n",dp[n]);
}
