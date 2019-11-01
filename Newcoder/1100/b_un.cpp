#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define ll long long
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)

const int MOD=1e9+7,MAXN=100000+10;

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int head[MAXN],to[MAXN<<1],_next[MAXN<<1],cnt;

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

int n,k;
queue<pair<int,int> > q;


int fa[MAXN],ans[MAXN],have[MAXN],num;

vector<int> g;

void bfs(int s) {
	while(!q.empty()) q.pop();
	q.push(make_pair(s,0));
	num=0;
	g.clear();
	REP(i,1,n) fa[i]=ans[i]=have[i]=0;
	while(!q.empty()) {
		int u=q.front().first,w=q.front().second;q.pop();
	
		if(w>k) return ;
	g.push_back(u);	
		if(!have[u]) num++;
		have[u]=1;
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(fa[u]==v) continue;
			fa[v]=u;
			q.push(make_pair(v,w+1));
			
		}
	}

}

int calc(int s) {
	REP(i,0,(int)g.size()-1) {
		int x=g[i];
		ans[s]++;
		while(fa[x]!=fa[s]) {
			ans[x]++;
			x=fa[x];
		}
	}	
}

int ans1[MAXN],ans2[MAXN];

int main() {
	n=read(),k=read();
	REP(i,1,n-1) {
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
	
	REP(i,1,n) {
		bfs(i);
		ans1[i]=num;
		ans2[i]=1;
		calc(i);
		REP(j,1,n) {
			if(ans[j]!=0) ans2[i]*=ans[j];
		}
	}

	REP(i,1,n) printf("%d ",ans1[i]);puts("");
	REP(i,1,n) printf("%d ",ans2[i]);
	return 0;
}
