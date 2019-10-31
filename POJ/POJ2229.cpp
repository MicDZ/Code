#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)

const int MAXN=10000000+10;

int read() {
    int x=0,f=1,ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int dp[MAXN];

int main() {
	int n=read();
	dp[0]=dp[1]=1;
	REP(i,1,n) {
		if(i&1)dp[i]=dp[i-1];
		else dp[i]=dp[i-2]+dp[i/2];
		dp[i]=dp[i]%int(1e9);
	}
	printf("%d\n",dp[n]);
	return 0;
}
