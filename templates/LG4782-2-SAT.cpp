#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<stack>
#include<vector>

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

const int MAXN=2e6+10;

int head[MAXN],_next[MAXN],to[MAXN],cnt;

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

int ins[MAXN],dfn[MAXN],low[MAXN],tot;
stack<int> s;

int color,id[MAXN];

void tarjan(int u) {
	dfn[u]=low[u]=++tot;
	s.push(u);ins[u]=1;
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(!dfn[v]) {
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(ins[v]) 
			low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]) {
		color++;
		int v;
		do {
			v=s.top();s.pop();
			id[v]=color;
			ins[v]=0;
		} while(u!=v);
	}
}

int main() {
	int n=read(),m=read();
	REP(i,1,m) {
		int u=read(),opu=read(),v=read(),opv=read();
		addedge(u+n*(opu&1),v+n*(opv^1));
		addedge(v+n*(opv&1),u+n*(opu^1));
	}
	REP(i,1,2*n) if(!dfn[i]) tarjan(i);
	
	REP(i,1,n) if(id[i]==id[i+n]) {
		puts("IMPOSSIBLE");
		return 0;
	}
	puts("POSSIBLE");
	REP(i,1,n) {
		printf("%d ",id[i]<id[i+n]);
	}
	return 0;
}

