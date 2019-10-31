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

const int MAXN=500+10;

int n,m,a[MAXN][MAXN],l[MAXN][MAXN],vis[MAXN][MAXN],r[MAXN][MAXN];

int dx[]={0,1,-1,0,0},
	dy[]={0,0,0,1,-1};

void dfs(int x,int y) {
	vis[x][y]=1;
	REP(i,1,4) {
		int xx=x+dx[i],yy=y+dy[i];
		if(xx>n||xx<1||yy>m||yy<1||a[xx][yy]>=a[x][y]) continue; 
		if(!vis[xx][yy]) dfs(xx,yy);
		l[x][y]=min(l[x][y],l[xx][yy]);
		r[x][y]=max(r[x][y],r[xx][yy]);
	}
}

int main() {
	n=read(),m=read();
	memset(l,127,sizeof(l));
	REP(i,1,n) REP(j,1,m) a[i][j]=read();
	REP(i,1,m) l[n][i]=r[n][i]=i;
	REP(i,1,m) if(!vis[1][i]) dfs(1,i);
	int cnt=0;
	REP(i,1,m) {
		if(!vis[n][i]) cnt++;
	}
	if(cnt) {
		printf("%d\n%d\n",0,cnt);
		return 0;
	}
	int _left=1;
    while(_left<=m) {
        int maxx=0;
        REP(i,1,m)
			if(l[1][i]<=_left)
                maxx=max(maxx,r[1][i]);
        cnt++;
        _left=maxx+1;
    }
	printf("%d\n%d\n",1,cnt);
	return 0;
}
