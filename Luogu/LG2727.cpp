#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100+10
ll read() {
    ll x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int N,L,dp[MAXN][MAXN];
ll I;

int main() {
	N=read(),L=read(),I=read();
	//cin>>N>>L>>I;
	
	for(int i=0; i<=N; i++) {
		dp[i][0]=1;
		dp[0][i]=1;
		//dp[i][i]=1;
	}
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++) {
			if(j<=i)
				dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
			else 
				dp[i][j]=dp[i][i];
		}

	for(int i=N; i>=1; i--) {
		if(I>dp[i-1][L]) {
			cout<<1;
			I-=dp[i-1][L];
			L--;
		}
		else cout<<0;
	}
	cout<<endl;
}

