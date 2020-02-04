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

const int MAXN=100000+10,MAXM=200000+10;

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

int g[MAXN];

void tarjan(int u) {
	dfn[u]=low[u]=++tot;
	s.push(u);
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(!dfn[v]) {
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(!id[v]) low[u]=min(low[u],low[v]);
	}
	if(dfn[u]==low[u]) {
		color++;
		int v;
		do {
			v=s.top();
			g[color]++;
			id[v]=color;
			s.pop();
		}while(u!=v);
	}
}

int in[MAXN],out[MAXN];

int u[MAXM],v[MAXM];

int main() {
	int n=read(),m=read();
	REP(i,1,m) {
		u[i]=read(),v[i]=read();
		addedge(u[i],v[i]);
	}
	REP(i,1,n) if(!dfn[i]) tarjan(i);

	REP(i,1,m) if(id[u[i]]!=id[v[i]]) in[id[v[i]]]++,out[id[u[i]]]++;
	
	int num1=0,num2=0;
	REP(i,1,color) {
		if(in[i]==0) num1++;
		if(out[i]==0) num2++;
	}

	int ans1=0,ans2=max(num1,num2);
	REP(i,1,color) ans1=max(ans1,g[i]);
	printf("%d\n%d",ans1,ans2);
	return 0;
}

