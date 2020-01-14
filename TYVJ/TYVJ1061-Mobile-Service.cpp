#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

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

const int MAXN=1000+1,MAXL=200+1,INF=0x3f3f3f3f;

int c[MAXL][MAXL],p[MAXN],f[2][MAXL][MAXL];

int main() {
	int l=read(),n=read();
	REP(i,1,l) REP(j,1,l) c[i][j]=read();
	REP(i,1,n) p[i]=read();
	
	int o=0;
	memset(f[o],127,sizeof(f[o]));
	p[0]=3;
	f[0][1][2]=0;

	REP(i,0,n) {
		memset(f[o^1],127,sizeof(f[o^1]));
		REP(x,1,l) REP(y,1,l) {
			f[o^1][x][y]=min(f[o^1][x][y],f[o][x][y]+c[p[i]][p[i+1]]);
			f[o^1][p[i]][y]=min(f[o^1][p[i]][y],f[o][x][y]+c[x][p[i+1]]);
			f[o^1][x][p[i]]=min(f[o^1][x][p[i]],f[o][x][y]+c[y][p[i+1]]);
		}
		o^=1;
	}

	int ans=INF;

	REP(i,1,l) REP(j,1,l) {
		if(i==j) continue;
		ans=min(ans,f[o][i][j]);
	}

	DE("%.2f MB\n",(sizeof(c)+sizeof(p)+sizeof(f))*1.0/1048576);
	printf("%d\n",ans);
	return 0; 
}

