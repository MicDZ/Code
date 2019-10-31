#include<bits/stdc++.h>
using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)

int read() {
    int x=0,f=1,ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

const int MAXN=1000+10,INF=1<<30;

int n,m,a[MAXN],dp[MAXN];

bool have[MAXN];

int work(int k) {
	dp[1]=1;dp[0]=0;
	int ans=0;bool mark=0;
	for(int j=1; ; j++) {
		dp[j]=-1;
		REP(i,1,k) 
			if(j-a[i]>=0&&dp[j-a[i]]+1<=m) {
				if(dp[j]==-1||dp[j]>dp[j-a[i]]+1) {
					dp[j]=dp[j-a[i]]+1;
					mark=1;
				}
			}
		//		ans=max(ans,j);
		if(!mark) return j-1;
		mark=0;	
	}
}

int ans=0,ans_a[MAXN];

void dfs(int k/*,int max_now*/) {
		//printf("%d %d\n",max_now,work(k));
	int now=work(k-1);
	if(k==n+1) {
		//printf("%d %d\n",max_now,work(n));
		if(ans<now) {REP(i,1,n) ans_a[i]=a[i];ans=now;}
		return ;
	}
	REP(i,1,now+1) {
		if(i<a[k-1]) continue;
		a[k]=i;
		dfs(k+1);
	}
}

int main() {
	n=read(),m=read();
	a[1]=1;
	dfs(2/*,2*/);
//	REP(i,1,n) printf("%d ",ans_a[i]);puts("");
	printf("%d\n",ans);
}
