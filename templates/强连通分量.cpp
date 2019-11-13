#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
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

const int MAXN=10000+10,MAXM=50000+10;

int head[MAXN],_next[MAXM],to[MAXM],cnt;

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

int dfn[MAXN],low[MAXN],ins[MAXN],tot;

struct stack {
	int tp,s[MAXN];
	int top() {return s[tp];}
	int size() {return tp;}
	void pop() {tp--;}
	void push(int x) {s[++tp]=x;}
} s;

int color,id[MAXN];

vector<int> scc[MAXN];

void tarjan(int u) {
	dfn[u]=low[u]=++tot;
	ins[u]=1;s.push(u);
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(!dfn[v]) {
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(ins[v]) low[u]=min(low[u],low[v]);
	}
	if(dfn[u]==low[u]) {
		color++;
		int v=s.top();s.pop();
		scc[color].push_back(v);
		while(u!=v) {
			s.pop();
			v=s.top();
			scc[color].push_back(v);
			id[v]=color;
		}
	}
}

int in[MAXN];

int main() {
	int n=read(),m=read();
	REP(i,1,m) {
		int u=read(),v=read();
		addedge(u,v);
		in[v]++;
	}
	
	REP(i,1,n) if(!dfn[i]) tarjan(i);
	int rt,cnt=0;
	
	REP(i,1,n) if(!in[i]) {
		rt=i;
		cnt++;
	}
	if(cnt>1) {
		puts("0");
		return 0;
	}
	printf("%d\n",scc[id[rt]].size());	
	return 0;
}

