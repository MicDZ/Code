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
const int MAXN=10010000;

int a[MAXN],dp[MAXN],ans[MAXN],prin[MAXN];

int main() {
	int n=read();
	REP(i,1,n) a[i]=read();
	dp[1]=1;
	REP(i,2,n) {
		dp[i]=1;
		REP(j,1,i-1) if(a[j]<=a[i]) {
			if(dp[j]+1>=dp[i]) ans[i]=j;
			dp[i]=max(dp[j]+1,dp[i]);
		}
	}
	int s=0,id;
	REP(i,1,n) if(dp[i]>s) s=dp[i],id=i;
	printf("max = %d\n",s);
	int k=1;
	while(id) {
		prin[k]=a[id];
		id=ans[id];
		k++;
	}

	DREP(i,k-1,1) printf("%d ",prin[i]);
	puts("");
}

