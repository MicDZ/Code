#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define ll long long
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)

ll read() {
	ll x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll lcm(ll x,ll y) {if(!y) return x;return x/__gcd(x,y)*y;}

const int MAXN=2520+10,MOD=2520;

ll f[20][MAXN][49+5];
int a[MAXN],num[20];


ll dfs(int x,int mod,int _lcm,bool flag) {
	if(!x) return mod%_lcm==0;
	if(!flag&&f[x][mod][a[_lcm]]) return f[x][mod][a[_lcm]];
	ll res=0;
	int maxx;
	if(!flag) maxx=9;else maxx=num[x];
	REP(i,0,maxx) 
		res+=dfs(x-1,(mod*10+i)%MOD,lcm(_lcm,i),flag&&(i==maxx));
	//DE("2");
	if(!flag) f[x][mod][a[_lcm]]=res;
	//DE("1");
	return res;
}

ll solve(ll x) {
	int cnt=0;
	while(x) num[++cnt]=x%10,x/=10;
	return dfs(cnt,0,1,1);
}

int main() {
	int cnt=0;
	REP(i,1,MOD) if(MOD%i==0) a[i]=++cnt;
	int t=read();
	REP(i,1,t) {
		ll l=read(),r=read();
		printf("%lld\n",solve(r)-solve(l-1));
	}
	return 0;
}
