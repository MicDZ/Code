#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;
#define REP(i,e,s) for(register int i=e; i<=s; i++)
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXM=5000+10,MAXN=500+10;

int _next[MAXN],to[MAXN],head[MAXN],weigh[MAXM],cnt;

void addedge(int u,int v,int w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	weigh[cnt]=w;
	to[cnt]=v;
}

int maxv[MAXN],minv[MAXN];

queue<int> q;

void bfs1() {
	while(!q.empty()) {
		int u=q.front();q.pop();
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(maxv[v]>max(maxv[u],weigh[i])) {
				maxv[v]=max(maxv[u],weigh[i]);
				q.push(v);
			}
		}
	}
}

void bfs2() {
	while(!q.empty()) {
		int u=q.front();q.pop();
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(minv[v]<min(minv[u],weigh[i])) {
				minv[v]=min(minv[u],weigh[i]);
				q.push(v);
			}
		}
	}
}

int main() {
	int n=read(),m=read();
	memset(maxv,1,sizeof(maxv));
	
	REP(i,1,m) {
		int u=read(),v=read(),w=read();
		addedge(u,v,w);
		addedge(v,u,w);
	}
	int s=read(),t=read();
	q.push(s);maxv[s]=0;
	bfs1();
	q.push(s);minv[s]=0;
	bfs2();
	//REP(i,1,n) printf("%d ",maxv[i]);
	int g=__gcd(maxv[t],minv[t]);
	//maxv[t]/=g;minv[t]/=g;
	//REP(i,1,n) printf("%d ",minv[i]);
	if(minv[t]>1000000) puts("IMPOSSIBLE");
	else if(minv[t]==1) printf("%d\n",maxv[t]);
	else printf("%d/%d\n",maxv[t],minv[t]);
	return 0;
}
