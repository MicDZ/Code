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

const int MAXN=20000+10,MAXM=100000+10;

int head[MAXN],_next[MAXM<<1],to[MAXM<<1],cnt;

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

int cut[MAXN];

int dfn[MAXN],low[MAXN],tot,root;
int ans;

void tarjan(int u) {
	dfn[u]=low[u]=++tot;
	int son_num=0;
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(!dfn[v]) {
			tarjan(v);
			if(dfn[u]<=low[v]) {
				son_num++;
				if(u!=root||son_num>1) cut[u]=1; 
			}
			low[u]=min(low[u],low[v]);
		}
		else low[u]=min(low[u],dfn[v]);
	}
}
 
int main() {
	int n=read(),m=read();
	REP(i,1,m) {
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}

	REP(i,1,n) if(!dfn[i]) root=i,tarjan(i);

	REP(i,1,n) ans+=cut[i];
	printf("%d\n",ans);
	REP(i,1,n) if(cut[i]) printf("%d ",i);
	return 0;
}

