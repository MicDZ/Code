#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

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

const int MAXN=500+10;

int head[MAXN],_next[MAXN<<1],to[MAXN<<1],cnt;

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

int dfn[MAXN],low[MAXN],cut[MAXN],tot;

int root;

void tarjan(int u) {
	dfn[u]=low[u]=++tot;
	int flag=0;
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(!dfn[v]) {
			tarjan(v);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]) {
				flag++;
				if(u!=root||flag>1) cut[u]=1;
			}
		}
		else low[u]=min(low[u],dfn[v]);
	}
}


int cntt,num,T;

int vis[MAXN];
void init() { 
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	cnt=tot=0;
	memset(head,0,sizeof(head));
	memset(cut,0,sizeof(cut));
	memset(vis,0,sizeof(vis));
}


void dfs(int u) {
	vis[u]=T;
	if(cut[u]) return ;
	cntt++;
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(cut[v]&&vis[v]!=T) num++,vis[v]=T;
		if(!vis[v]) dfs(v);
	}
}

int main() {
	int m,_case=0,n=0;
	while(~scanf("%d",&m)&&m) {
		n=T=0;
		init();
		REP(i,1,m) {
			int u=read(),v=read();
			if(u==v) continue;
			n=max(n,max(u,v));
			addedge(u,v);
			addedge(v,u);
		}
		REP(i,1,n) if(!dfn[i]) root=i,tarjan(i);
		
		int ans1=0;
		ll ans2=1;
		REP(i,1,n) {
			if(!vis[i]&&!cut[i]) {
				T++;cntt=num=0;
				dfs(i);
				if(!num) ans1+=2,ans2*=1ll*cntt*(cntt-1)/2;
				if(num==1) ans1++,ans2*=cntt;
			}
		}
		printf("Case %d: %d %lld\n",++_case,ans1,ans2);
	}
	return 0;
}

