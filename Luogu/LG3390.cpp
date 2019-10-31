#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define ll long long

ll read() {
	ll x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int MOD=1e9+7;
struct mat {
	ll m[110][110];
};
ll n,p;

mat mul(mat a,mat b) {
	mat c;
	REP(i,1,n) REP(j,1,n) c.m[i][j]=0;
	REP(i,1,n) REP(j,1,n) REP(k,1,n) c.m[i][j]=c.m[i][j]%MOD+a.m[i][k]*b.m[k][j]%MOD;
	return c;
}
mat a,e;
mat qpow(mat a,ll b) {
	mat ans=e;
	while(b) {
		if(b&1) ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}


int main() {
	n=read(),p=read();
	REP(i,1,n) REP(j,1,n) a.m[i][j]=read();
	REP(i,1,n) e.m[i][i]=1;

	mat ans=qpow(a,p);

	REP(i,1,n) {REP(j,1,n) printf("%lld ",ans.m[i][j]%MOD);puts("");}
	return 0;
}
