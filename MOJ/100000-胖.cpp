#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;
#define int ll
#define REP(i,e,s) for(register int i=(e); i<=(s); i++)
#define DREP(i,e,s) for(register int i=(e); i>=(s); i--)
#define ll long long
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=100+10,MOD=1e9+7;
int n=2;
struct matrix {
	int a[MAXN][MAXN];
	matrix() {memset(a,0,sizeof(a));}
} ;

matrix operator * (matrix a,matrix b) {
	matrix ans;
	REP(k,1,n) REP(i,1,n) REP(j,1,n) ans.a[i][j]=(ans.a[i][j]+a.a[i][k]*b.a[k][j]%MOD)%MOD;
	return ans;
}

matrix qpow(matrix a,int b) {
	matrix ans;
	REP(i,1,n) ans.a[i][i]=1;
	while(b) {
		if(b&1) ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;
}

int int_qpow(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1) ans=ans*a%MOD;
		a=a*a%MOD;
		b>>=1;
	}
	return ans;
}

signed main() {
	int n=read();
	int x=read(),a=read(),b=read();	
	matrix s,ans;
	s.a[1][1]=(a*int_qpow(x,MOD-2)+1)%MOD;
	s.a[1][2]=1;
	s.a[2][1]=(b*int_qpow(x,MOD-2))%MOD;
	s.a[2][2]=0;
	ans=qpow(s,n-1);

	printf("%lld\n",ans.a[1][1]);
	return 0;
}

