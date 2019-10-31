#include<bits/stdc++.h>
using namespace std;
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define ll long long
int read() {
    int x=0,f=1,ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
const int MAXN=100+10;

int n,m,a[MAXN][MAXN],dis[MAXN][MAXN],ans;
int dx[]={0,1,-1,0,0},
	dy[]={0,0,0,1,-1};
void dfs(int x,int y,int l) {
	if(dis[x][y]>l) return ;
	dis[x][y]=l;
	ans=max(ans,l);
	REP(i,1,4) {
		int xx=dx[i]+x,yy=dy[i]+y;
		if(a[xx][yy]>=a[x][y]||xx<1||xx>n||yy<1||yy>m) continue;
		dfs(xx,yy,l+1);
	}
}

int main() {
	n=read(),m=read();

//	memset(dis,-1,sizeof(dis));
	
	REP(i,1,n) REP(j,1,m) a[i][j]=read();
	
	REP(i,1,n) REP(j,1,m) {
	//	if(dis[i][j]==-1) dis[i][j]=1;
		dfs(i,j,1);
	}

	printf("%d\n",ans);

	return 0;
}
