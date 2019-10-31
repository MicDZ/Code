#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<stack>

using namespace std;
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define DE(...) fprintf(stderr,__VA_ARGS__);
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define ll long long

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int INF=0x3f3f3f,MAXN=40000+10;

map<string,int> list;

int head[MAXN],to[MAXN],_next[MAXN],cnt;

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

int dfn[MAXN],tot,ins[MAXN],c[MAXN],low[MAXN],times;
stack<int> s;

void tarjan(int u) {
	dfn[u]=low[u]=++times;
	s.push(u);
	ins[u]=1;
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(!dfn[v]) {
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(ins[v]) low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]) {
		tot++;
		while(1) {
			c[s.top()]=tot;
			ins[s.top()]=0;
			
			if(s.top()==u) break;
			s.pop();
		}
		s.pop();
	}
}

int main() {
	int n=read();
	string girl,boy;
	REP(i,1,n) {
		cin>>girl>>boy;
		list[girl]=i;
		list[boy]=i+n;
		addedge(i,i+n);
	}
	int m=read();
	REP(i,1,m) {
		cin>>girl>>boy;
		addedge(list[boy],list[girl]);
	}

	REP(i,1,n*2) if(!dfn[i]) tarjan(i);

	REP(i,1,n) {
		if(c[i]==c[i+n]) puts("Unsafe");
		else puts("Safe");
	}
	return 0;
}

