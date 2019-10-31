#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

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

const int MAXN=12+1,INF=0x3f3f3f3f;

int a[MAXN][MAXN],b[4096+10],f[4096+10][MAXN];

int main() {
	int n=read(),m=read();
	int full=(1<<n)-1;
	REP(i,0,n) REP(j,0,n) a[i][j]=i==j?0:INF;
	REP(i,1,m) {
		int u=read()-1,v=read()-1,w=read();
		a[u][v]=a[v][u]=min(w,a[u][v]);
	}
	
	REP(s,0,full) 
		REP(i,0,n-1) 
			if(s&(1<<i))
			REP(j,0,n-1) if(a[i][j]!=INF) b[s]|=(1<<j);
		
	
	REP(i,0,4096) REP(j,0,n) f[i][j]=INF; 
	f[0][0]=0;
	REP(i,0,n-1) f[1<<i][0]=0;

	REP(s,1,full) {
		for(int t=s-1; t&s; t--) {
			t&=s;
			if(b[t]!=(b[t]|s)) continue;
			int res=0;
			REP(i,0,n-1) {
				if(!((s^t)&(1<<i))) continue;
				int minn=INF;
				REP(j,0,n-1) {
					if(!(t&(1<<j))) continue;
					minn=min(minn,a[i][j]);
				}
				res+=minn;
			}
			
			REP(i,1,n-1) {
				if(f[t][i-1]==INF) continue;
				//puts("in");
				f[s][i]=min(f[s][i],f[t][i-1]+res*i);
			}
		}	
	}
	
	int ans=INF;
	REP(i,0,n-1) ans=min(ans,f[full][i]);

	printf("%d\n",ans);
	return 0;
}
