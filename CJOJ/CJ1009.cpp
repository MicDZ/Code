#include<bits/stdc++.h>
using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define ll long long
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

char c[50];
ll a[50][50],dp[50][50];
int main() {
	ll n=read(),k=read();
	scanf("%s",c+1);
	REP(i,1,n) REP(j,i,n) 
		a[i][j]=a[i][j-1]*10+c[j]-'0';
	REP(i,1,n) dp[i][0]=a[1][i];
	REP(i,1,n) REP(j,1,k) REP(m,1,i)
		dp[i][j]=max(dp[i][j],dp[m][j-1]*a[m+1][i]);

	printf("%lld\n",dp[n][k]);	
	return 0;
}
