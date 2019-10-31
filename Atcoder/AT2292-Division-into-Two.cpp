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
#define lowbit(x) x&(-x)
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=100000+10,MOD=1e9+7,INF=0x3f3f3f3f;

struct bitree {
	int c[MAXN],n;
	void add(int x,int d) {
		while(x<=n) {
			c[x]=(c[x]+d)%MOD;
			x+=lowbit(x);
		}
	}
	int ask(int x) {
		int ans=0;
		while(x) {
			ans=(ans+c[x])%MOD;
			x-=lowbit(x);
		}
		return ans;
	}
} f[2];

int s[MAXN];

signed main() {
	int n=read(),k[2]={read(),read()};
	REP(i,1,n) s[i]=read();
	f[0].n=n,f[1].n=n;
	f[0].add(1,1),f[1].add(1,1);
	int lst[2]={1,1};
	REP(i,1,n-1) {
		REP(j,0,1) {
			int pos=upper_bound(s+1,s+n,s[i+1]-k[j])-s;
			f[j].add(i+1,f[j^1].ask(min(i,pos)));
		}
		REP(j,0,1) {
			if(s[i+1]-s[i]<k[j]) {
				REP(k,lst[j],i) f[j].add(k,MOD-f[j].ask(k));
				lst[j]=i+1;
			}
		}
	}
	printf("%lld\n",(f[0].ask(n)+f[1].ask(n))%MOD);
	return 0;
}
