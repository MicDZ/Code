#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define DREP(i,e,s) for(register ll i=e; i>=s; i--)
#define REP(i,e,s) for(register ll i=e; i<=s; i++)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)


ll read() {
	ll x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0') {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const ll MAXN=6000+10,INF=0x3f3f3f3f3f3f3f3f;
ll w[MAXN],v[MAXN],l[MAXN],dp[MAXN*1000];
int main() {
	ll n=read(),m=n,t=read();
	REP(i,1,n) {
		w[i]=read();
		v[i]=read();
		l[i]=read();
		if(l[i]==0) {
			n--;
			i--;
		}
	}
	REP(i,1,n) {
		int maxx=log(l[i])/log(2);
		REP(j,1,maxx-1) {
			m++;
			w[m]=(1<<j)*w[i];
			v[m]=(1<<j)*v[i];
			//cout<<w[m]<<" "<<v[m]<<endl;
			l[i]-=(1<<j);
		}
		l[i]-=1;
		if(l[i]>0) {
			m++;
			w[m]=l[i]*w[i];
			v[m]=l[i]*v[i];		
			//cout<<w[m]<<" "<<v[m]<<endl;
		}
	}
	REP(i,1,m) DREP(j,t,w[i]) dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
	ll ans=-INF;
	REP(i,1,t) ans=max(ans,dp[i]);
	printf("%lld\n",ans);
}
