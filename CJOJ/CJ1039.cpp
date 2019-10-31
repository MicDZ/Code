#include<bits/stdc++.h>
using namespace std;
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define ll long long
int read() {
    int x=0,f=1,ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
const int MAXN=100000+10;
int a[MAXN],dp[MAXN][2];

int main() {
	int n=read();
	REP(i,1,n) a[i]=read();
	
	REP(i,1,n) {
		if(i==1) {dp[1][0]=1;dp[1][1]=1;continue;}
		if(a[i]>a[i-1]) dp[i][1]=dp[i-1][0]+1;
		else dp[i][1]=dp[i-1][1];
		if(a[i]<a[i-1]) dp[i][0]=dp[i-1][1]+1;
		else dp[i][0]=dp[i-1][0];
	}//第i个波峰为1波谷为0
	
	printf("%d\n",max(dp[n][1],dp[n][0]));
	return 0;
}
