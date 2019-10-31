#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

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

const int INF=0x3f3f3f,MAXN=2000000+10;

int head[MAXN],to[MAXN],_next[MAXN],cnt;
void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

int _root,vis[MAXN],dfn[MAXN],low[MAXN],flag[MAXN],times;

void tarjan(int u) {
	int son_num=0;
	times++;
	vis[u]=1;
	dfn[u]=low[u]=times;
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(!vis[v]) {
			son_num++;
			tarjan(v);
			low[u]=min(low[v],low[u]);
			if(u==_root&&u==son_num>=2) flag[u]=1; 
			if(u!=_root&&low[v]>=dfn[u]) flag[u]=1;
		}
		else if(u!=v) low[u]=min(low[u],dfn[v]);
	}
}

int main() {
	int n=read();
	int u,v;
	while(~scanf("%d%d",&u,&v)&&(u||v)) addedge(u,v),addedge(v,u);
	REP(i,1,n) if(!dfn[i]) {times=0;_root=i;tarjan(i);}
	int tot=0;
	REP(i,1,n) if(flag[i]) tot++;
	printf("%d\n",tot);
	REP(i,1,n) if(flag[i]) printf("%d\n",i);
	return 0;
}

