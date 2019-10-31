#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;
#define int ll
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define ll long long
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)

const int MAXN=100000+10,MOD=19260817;

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x*10+ch-'0')%MOD;ch=getchar();}
	return x*f;
}

int a[MAXN],n,m;

int f(int x,int mod) {
	int ans=0,prod=1;
	REP(i,0,n) {
		ans=(ans+prod*a[i])%MOD;
		prod=(prod*x)%MOD;
	}
	return ans;
}

int book[MAXN];

int ans[MAXN],cnt;

signed main() {
	file("data");
	n=read(),m=read();
	
	REP(i,0,n) a[i]=read();

	REP(i,1,m) if(f(i,MOD)==0) ans[++cnt]=i;	
	printf("%lld\n",cnt);
	REP(i,1,cnt) printf("%lld\n",ans[i]);
	return 0;
}
