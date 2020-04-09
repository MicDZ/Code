#include<bits/stdc++.h>
using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int MAXN=100000+10;
int _next[MAXN],head[MAXN],to[MAXN],cnt,dept[MAXN];

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

double ans=0;

void dfs(int now,int dis) {
	dept[now]=min(dept[now],dis);
	for(int i=head[now]; i; i=_next[i]) {
		int v=to[i];
		if(dept[v]!=dept[0]) continue;
		dfs(v,dis+1);
	}
}
	
int main() {
	int n=read();
	memset(dept,1,sizeof(dept));
	REP(i,1,n-1) {
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
	dfs(1,1);
	//REP(i,1,n) printf("%d ",dept[i]);
	REP(i,1,n) ans+=1.0/dept[i];

	printf("%.12llf",ans);
}
