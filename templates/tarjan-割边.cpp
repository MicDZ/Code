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

const int MAXN=100000+10,MAXM=500000+10;

int head[MAXN],_next[MAXM<<1],to[MAXM<<1],cnt=1;

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

int dfn[MAXN],low[MAXN],tot;

int bridge[MAXN];

void tarjan(int u,int in_edge) {
	dfn[u]=low[u]=++tot;
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(!dfn[v]) {
			tarjan(v,i);
			if(dfn[u]<low[v]) 
				bridge[i]=bridge[i^1]=1;
			low[u]=min(low[u],dfn[v]);
		}
		else if((in_edge^1)!=i) low[u]=min(low[u],dfn[v]);
	}
}

int main() {
	file("tarjan-割边");
	int n=read(),m=read();
	REP(i,1,m) {
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}

	REP(i,1,n) if(!dfn[i]) tarjan(i,0);
	
	for(int i=2; i<=2*m; i+=2) {
		if(bridge[i]) printf("%d %d\n",to[i],to[i^1]);
	}
	return 0;
}

