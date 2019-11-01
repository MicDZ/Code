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

const int MAXN=40000+10;

int n,son[2][MAXN],a[MAXN],b[MAXN],c[MAXN],f[MAXN][40+5][40+5];

int calc(int u,int _a,int _b) {
	if(u>=n) return c[u]*(a[u]+_a)*(b[u]+_b);
	return f[u][_a][_b];
}

void dfs(int u,int a,int b) {
	if(u>=n) return ;
	dfs(son[1][u],a,b+1);
	dfs(son[0][u],a+1,b);
	REP(i,0,a) REP(j,0,b) f[u][i][j]=min(calc(son[0][u],i,j)+calc(son[1][u],i,j+1),calc(son[1][u],i,j)+calc(son[0][u],i+1,j));
}

signed main() {
	n=read();
	REP(i,1,n-1) {
		int s=read(),t=read();
		if(s<0) s=-s+n-1;
		if(t<0) t=-t+n-1;
		son[0][i]=s,son[1][i]=t;
	}

	REP(i,1,n) a[i+n-1]=read(),b[i+n-1]=read(),c[i+n-1]=read();
	dfs(1,0,0);
	
	printf("%lld\n",f[1][0][0]);
	return 0;
}
