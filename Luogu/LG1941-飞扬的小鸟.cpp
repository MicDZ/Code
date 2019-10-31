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

const int MAXN=10000+10,INF=0x3f3f3f3f;

int high[MAXN],low[MAXN],flag[MAXN],f[MAXN][2000+10],x[MAXN],y[MAXN];

int main() {
	int n=read(),m=read(),k=read();
	
	REP(i,1,n) x[i]=read(),y[i]=read();

	REP(i,1,n) high[i]=m+1;

	REP(i,1,k) {
		int x=read(),h1=read(),h2=read();
		high[x]=h2;
		low[x]=h1;
		flag[x]=1;
	}

	REP(i,1,n) REP(j,1,m) f[i][j]=INF; 	
	REP(i,1,m) f[0][i]=0;
	
	REP(i,1,n) {
		REP(j,x[i]+1,x[i]+m) f[i][j]=min(f[i-1][j-x[i]]+1,f[i][j-x[i]]+1);
		REP(j,m+1,x[i]+m) f[i][m]=min(f[i][m],f[i][j]);
		REP(j,1,m-y[i]) f[i][j]=min(f[i][j],f[i-1][j+y[i]]);
		REP(j,1,low[i]) f[i][j]=INF;
		REP(j,high[i],m) f[i][j]=INF;
	}

	int ans=INF;
	REP(i,1,m) 
		ans=min(ans,f[n][i]);
	
	if(ans<INF) {
		puts("1");
		printf("%d\n",ans);
	}
	else {
		puts("0");
		int pos=0,now=INF;
		DREP(i,n,1) {
			REP(j,1,m){/*DE("%d\n",f[i][j]);*/ if(f[i][j]<INF) {pos=i;now=j;break;}}
			if(now<m) break;
		}

		ans=0;
		REP(i,1,pos) if(flag[i]) ans++;
		printf("%d\n",ans);
	}
	return 0;
}
