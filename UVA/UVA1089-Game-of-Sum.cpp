#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
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

int a[MAXN],sum[MAXN],f[MAXN][MAXN];

int dp(int x,int y) {
	if(f[x][y]) return f[x][y];
	
	int m=0;

	REP(i,x+1,y) m=min(m,dp(i,y));
	REP(i,x,y-1) m=min(m,dp(x,i));

	return f[x][y]=sum[y]-sum[x-1]-m;
}

int main() {
	int n=read();
	while(n) {
		memset(f,0,sizeof(f));
		REP(i,1,n) a[i]=read(),sum[i]=sum[i-1]+a[i];
			
		printf("%d\n",2*dp(1,n)-sum[n]);
		n=read();
	}
	
	return 0;
}
