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
const int MAXN=20+5;
ll dp[MAXN][MAXN];
int dx[]={0,-1,-2,-1,-2},
	dy[]={0,2,1,-2,-1};


int main() {
	int m=read(),n=read();

	REP(i,1,n) REP(j,1,m) {
		if(i==1&&j==1) dp[i][j]=1;
		else REP(k,1,4) dp[i][j]+=dp[i+dx[k]][j+dy[k]];
	}

	cout<<dp[n][m];
}
