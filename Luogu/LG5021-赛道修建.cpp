#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>
#include<queue>
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

const int MAXN=500000+10;

int head[MAXN],_next[MAXN<<1],to[MAXN<<1],weigh[MAXN<<1],cnt;

void addedge(int u,int v,int w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
}

int able[MAXN],fa[MAXN];

int n,m,ans;
multiset<int> s[MAXN];

queue<int> q;

int dist[MAXN],pos;

int bfs(int s) {
	memset(dist,127,sizeof(dist));
	q.push(s);dist[s]=0;
	while(!q.empty()) {
		int u=q.front();q.pop();
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(fa[u]==v) continue;
			fa[v]=u;
			if(dist[v]>dist[u]+weigh[i]) {
				dist[v]=dist[u]+weigh[i];
				q.push(v);
			}
		}
	}

	int _max=0;
	REP(i,1,n) if(dist[i]>_max) _max=dist[i],pos=i;
	return _max;
}

int dfs(int u,int x) {
	int val=0;
	s[u].clear();
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(fa[u]==v) continue;
		fa[v]=u;
		val=dfs(v,x)+weigh[i];
		if(val>=x) ans++;
		else s[u].insert(val);
	}
	int maxx=0;
	while(!s[u].empty()) {
		int now=*s[u].begin();
		if(s[u].size()==1) return max(maxx,now);
		multiset<int>:: iterator it=s[u].lower_bound(x-now);

		if(it==s[u].begin()&&s[u].count(*it)==1) it++;
		if(it==s[u].end()) {
			maxx=max(maxx,now);
			s[u].erase(s[u].find(now));
		}
		else {
			s[u].erase(it);
			s[u].erase(s[u].find(now));
			ans++;
		}
	}
	return maxx;
}

int check(int lim) {
	ans=0;
	dfs(1,lim);
	return ans>=m;
}

int main() {
//file("a");
	n=read(),m=read();
	int l=1,r;
	REP(i,1,n-1) {
		int u=read(),v=read(),w=read();
		addedge(u,v,w);
		addedge(v,u,w);
	}
	bfs(1);
	r=bfs(pos);
	while(l<r) {
		int mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}

	printf("%d\n",l);
	return 0;
}
