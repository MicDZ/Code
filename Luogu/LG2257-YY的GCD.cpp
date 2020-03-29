#include<iostream>
#include<cstdio>
#include<cstring>
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a)	freopen(a".in","r",stdin);freopen(a".out","w",stdout)
using namespace std;
#define ll long long
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=1e7+10,N=1e7;

int mu[MAXN],vis[MAXN],prime[MAXN],g[MAXN],cnt;

ll sum[MAXN];
void get_mu() {
	mu[1]=1;
	REP(i,2,N) {
		if(!vis[i]) {mu[i]=-1;prime[++cnt]=i;}
		for(int j=1; j<=cnt&&prime[j]*i<=N; j++) {
			vis[i*prime[j]]=1;
			if(i%prime[j]==0) break;
			else mu[prime[j]*i]=-mu[i];
		}
	}
	
	REP(j,1,cnt) for(int i=1; i*prime[j]<=N; i++) g[i*prime[j]]+=mu[i];
	REP(i,1,N) sum[i]=sum[i-1]+1ll*g[i];
}

int main() {
	int t=read();
	get_mu();
	while(t--) {
		int n=read(),m=read();
		if(n>m) swap(n,m);
		ll ans=0;
		for(int l=1,r; l<=n; l=r+1) {
			r=min(n/(n/l),m/(m/l));
			ans+=1ll*(n/l)*(m/l)*(sum[r]-sum[l-1]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

