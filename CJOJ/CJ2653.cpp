#include<bits/stdc++.h>
using namespace std;
#define REP(i,e,s) for(register int i=e; i<=s; i++)

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=200000+10,INF=0x3f3f3f;

int a[MAXN][2],drop[MAXN],tim[MAXN],n,m,dis[MAXN];

queue<pair<int,int> > q;

void bfs() {
	while(!q.empty()) {
		int u=q.front().first,s=q.front().second;q.pop();
		REP(i,0,1) {
			int v=a[u][i];
			if(drop[v])
		}
	}
}

int main() {
	n=read(),m=read();
	memset(drop,1,sizeof(drop));
	REP(i,1,n) {
		a[i][0]=read();
		a[i][1]=read();
	}

	REP(i,1,m) {
		int x=read(),p=read();
		drop[x]=p;
		tim[x]=i;
	}

	q.push(make_pair(1,-1));
	memset(dis,-1,sizeof(dis));

	bfs();

	return 0;
}
