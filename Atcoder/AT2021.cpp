#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>

using namespace std;
#define ll long long
#define REP(i,e,s) for(register ll i=e; i<=s; i++)
#define DREP(i,e,s) for(register ll i=e; i>=s; i--)
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define int ll

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=400+10,MOD=1e9+7;

int a[MAXN],b[MAXN],_pow[MAXN][MAXN],sum[MAXN][MAXN],f[MAXN][MAXN];

signed main() {
	int n=read(),c=read();
	REP(i,1,n) a[i]=read();
	REP(i,1,n) b[i]=read();
	
	REP(i,1,400) {
		_pow[i][0]=1;
		REP(j,1,400) _pow[i][j]=(_pow[i][j-1]*i)%MOD;
	}

	REP(i,1,400) REP(j,0,400) sum[i][j]=(sum[i][j]+sum[i-1][j]+_pow[i][j])%MOD;
	f[0][0]=1;	
	REP(i,1,n) REP(j,0,c) REP(k,0,j) 
		f[i][j]=(f[i][j]+f[i-1][j-k]*(sum[b[i]][k]-sum[a[i]-1][k]+MOD)%MOD)%MOD;
	
	printf("%lld",f[n][c]);
	return 0;
}
