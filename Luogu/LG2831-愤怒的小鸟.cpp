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
#define eps 1e-8
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=20+5;

double x[MAXN],y[MAXN];
int dp[(1<<20)+5],line[MAXN][MAXN];

double a,b;
void calc(int i,int j) {
	a=(y[j]-(y[i]*x[j])/x[i])/(x[j]*x[j]-x[i]*x[j]);
	b=y[i]/x[i]-x[i]*a;
}

int lowx[(1<<20)+5];

int main() {
	int t=read();
	while(t--) {
		memset(dp,127,sizeof(dp));
		memset(line,0,sizeof(line));
		dp[0]=0;
		int n=read(),m=read();
		REP(i,1,n)	scanf("%lf%lf",&x[i],&y[i]);
		REP(i,1,n) REP(j,1,n) {
			if(fabs(x[i]-x[j])<eps||x[i]*x[j]==0) continue;
			calc(i,j);
			if(a>-eps) continue;
			REP(k,1,n) if(fabs(a*x[k]*x[k]+b*x[k]-y[k])<=eps) line[i][j]|=(1<<(k-1));
		}
		
		REP(s,0,(1<<n)-1) {
			int i=1;
			while(i<=n&&s&(1<<(i-1))) i++;
			dp[s|(1<<(i-1))]=min(dp[s|(1<<(i-1))],dp[s]+1);
			REP(j,1,n) dp[s|line[i][j]]=min(dp[s|line[i][j]],dp[s]+1);
		}
		printf("%d\n",dp[(1<<n)-1]);
	}
	return 0;
}
