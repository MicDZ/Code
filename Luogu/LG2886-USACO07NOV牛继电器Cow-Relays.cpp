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
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=100+10;

int k,n,m,s,t;
struct matrix {
	int a[MAXN][MAXN];
	matrix() {
		memset(a,0x3f,sizeof(a));
	}
    inline int* operator [](const int i) {         
		return a[i];
    }
}g;

int cnt;

matrix operator * (matrix a,matrix b) {
	matrix c;
	REP(i,1,cnt) REP(j,1,cnt) REP(k,1,cnt) c[i][j]=min(c[i][j],a[i][k]+b[k][j]);
	return c;
}

matrix qpow(matrix a,int k) {
	matrix ans;ans=a;
	k-=1;
	while(k) {
		if(k&1) ans=ans*a;
		k>>=1;
		a=a*a;
	}
	return ans;
}

int id[MAXN*10];

signed main() {
	k=read(),m=read(),s=read(),t=read();
	REP(i,1,m) {
		int w=read(),u=read(),v=read();
		if(!id[u]) id[u]=++cnt;
		if(!id[v]) id[v]=++cnt;
		u=id[u],v=id[v];
		g[u][v]=g[v][u]=min(g[u][v],w);
	}

	printf("%d\n",qpow(g,k)[id[s]][id[t]]);
	return 0;
}
