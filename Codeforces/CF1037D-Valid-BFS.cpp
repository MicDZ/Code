#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<set>
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

const int MAXN=200000+10,INF=0x3f3f3f;

int head[MAXN],_next[MAXN<<1],to[MAXN<<1],cnt;

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

int a[MAXN],have[MAXN],vis[MAXN],now=1;

bool able=1;

queue<int> q;

void bfs(int st) {
	q.push(st);now++;
	set<int> s;
	while(!q.empty()) {
		int u=q.front();q.pop();
		vis[u]=1;
		for(int i=head[u]; i; i=_next[i]) if(!vis[to[i]]) s.insert(to[i]);
		while(!s.empty()) {
			if(s.count(a[now])) {
				s.erase(a[now]);
				q.push(a[now]);
				now++;
			}
			else {
			able=0;
				puts("No");
				return;	
			}
		}
	}
}

int main() {
	int n=read();
	REP(i,1,n-1) {
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}

	REP(i,1,n) a[i]=read();
	bfs(1);

	if(able) puts("Yes");
	return 0;
}
