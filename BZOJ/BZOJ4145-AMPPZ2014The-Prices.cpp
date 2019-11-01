#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define int ll
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
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

const int MAXN=100+10,MAXM=16+5;

int d[MAXN],c[MAXN][MAXM],f[MAXN][1<<16];

signed main() {
	int n=read(),m=read();
	REP(i,1,n) {
		d[i]=read();
		REP(j,1,m) c[i][j]=read();
	}
	int full=(1<<m)-1;
	memset(f,63,sizeof(f));
	f[0][0]=0;
	REP(i,1,n) {
		REP(j,0,full) f[i][j]=min(f[i][j],f[i-1][j]+d[i]);
		REP(j,0,full) REP(k,0,m-1) {
			if(!(j&(1<<k))) f[i][j|(1<<k)]=min(f[i][j|1<<k],f[i][j]+c[i][k+1]);
		}
		REP(j,0,full) f[i][j]=min(f[i][j],f[i-1][j]);
	}

	printf("%lld\n",f[n][full]);
	return 0;
}
