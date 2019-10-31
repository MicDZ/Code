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

const int INF=0x3f3f3f,MAXM=10000+10,MAXN=50+10;

int a[MAXN][MAXN][65],dist[MAXN][MAXN];

int main() {
	int n=read(),m=read();
	
	REP(i,1,n) REP(j,1,n) dist[i][j]=INF;

	REP(i,1,m) {
		int u=read(),v=read();
		a[u][v][0]=1;
		dist[u][v]=1;
	}
	
	REP(x,1,31) REP(i,1,n) REP(k,1,n) REP(j,1,n) {
		if(a[i][k][x-1]&&a[k][j][x-1]) a[i][j][x]=1,dist[i][j]=1;
	} 
		
	REP(k,1,n) REP(i,1,n) REP(j,1,n) dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);

	printf("%d\n",dist[1][n]);

	return 0;
}
