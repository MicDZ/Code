#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<stack>

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

const int MAXN=1000+10;

int head[MAXN],_next[MAXN<<1],to[MAXN<<1],cnt;

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;	
}

int n,B;

int fa[MAXN];

stack<int> s;

int tot,rt[MAXN],bel[MAXN];
void dfs(int u) {
	int cnr=s.size();
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(fa[u]==v) continue;
		fa[v]=u;
		dfs(v);
		if((int)s.size()>=B+cnr) {
			rt[++tot]=u;
			while((int)s.size()>cnr) bel[s.top()]=tot,s.pop();
		}
	}
	s.push(u);
}


int main() {
	n=read(),B=read();
	REP(i,1,n-1) {
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
	dfs(1);
	if(!tot) rt[++tot]=1;
	while(s.size()) bel[s.top()]=tot,s.pop();
	
	printf("%d\n",tot);
	REP(i,1,n) printf("%d ",bel[i]);puts("");
	REP(i,1,tot) printf("%d ",rt[i]);
	return 0;
}

