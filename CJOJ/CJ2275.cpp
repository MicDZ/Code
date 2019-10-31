#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<stack>
#include<vector>

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

const int INF=0x3f3f3f,MAXN=1000000+10;

int n,m,a[MAXN],sum[MAXN],head[MAXN],to[MAXN],_next[MAXN],cnt;

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

int head_c[MAXN],to_c[MAXN],_next_c[MAXN],cnt_c;

void addedge_c(int u,int v) {
	cnt_c++;
	_next_c[cnt_c]=head_c[u];
	head_c[u]=cnt_c;
	to_c[cnt_c]=v;
}


int dfn[MAXN],c[MAXN],tot,ins[MAXN],low[MAXN],times;

stack<int> s;
vector<int> scc[MAXN];

void tarjan(int u) {
	times++;
	dfn[u]=low[u]=times;
	s.push(u);ins[u]=1;
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		if(!dfn[v]) {
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(ins[v]) low[u]=min(low[u],low[v]);
	}
	
	if(dfn[u]==low[u]) {
		tot++;int v;
		do {
			v=s.top();s.pop();
			ins[v]=0;
			c[v]=tot;
			sum[tot]+=1;
			scc[tot].push_back(v);
		}while(u!=v);
	}	
	
}

vector<int> ans[MAXN];
int have[MAXN];

int main() {
	n=read();
	int u,v;
	while(~scanf("%d%d",&u,&v)&&(u||v)) addedge(u,v);
	REP(i,1,n) if(!dfn[i]) tarjan(i);
	int cnt=0;
	REP(i,1,n) {
		if(!have[c[i]]) 
			have[c[i]]=++cnt;
		ans[have[c[i]]].push_back(i);
	}
	
	printf("%d\n",tot);

	REP(i,1,cnt) {
		REP(j,0,ans[i].size()-1) printf("%d ",ans[i][j]);
		puts("");
	}
}
