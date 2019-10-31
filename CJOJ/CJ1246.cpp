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

const int MAXN=5000+10;
char a[MAXN],b[MAXN];
int dp[MAXN][MAXN];
int main() {
	scanf("%s",a+1);
	scanf("%s",b+1);
	int n=strlen(a+1)-1,m=strlen(b+1)-1;

	REP(i,2,n+1) REP(j,2,m+1) {
		if(a[i-1]!=b[j-1]) dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		else dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
	}

	printf("%d\n",dp[n+1][m+1]);
	return 0;
}
