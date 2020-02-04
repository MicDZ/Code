#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;
#define int ll
#define REP(i,e,s) for(register int i=(e); i<=(s); i++)
#define DREP(i,e,s) for(register int i=(e); i>=(s); i--)
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define ll long long

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=200000+10,MAXM=1000000+10;

int head[MAXN],_next[MAXM],to[MAXM],weigh[MAXM],cnt;

void addedge(int u,int v,int w=0) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
}

int n,s[MAXN],k[MAXN];

queue<int> q;
vector<int> g[MAXN];
bool inq[MAXN];

void SPFA() {
	REP(i,1,n) q.push(i),inq[i]=1;
	while(!q.empty()) {
		int u=q.front();q.pop();inq[u]=0;
		int sum=s[u];
		for(int i=head[u]; i; i=_next[i]) sum+=k[to[i]];
		if(sum>=k[u]) continue;
		k[u]=sum;
		REP(i,0,(int)g[u].size()-1) {
			if(!inq[g[u][i]]) {
				q.push(g[u][i]);
				inq[g[u][i]]=1;
			}
		}
	}
}

signed main() {
	freopen("data.in","r",stdin);
	n=read();
	REP(i,1,n) {
		s[i]=read(),k[i]=read();int r=read();
		REP(j,1,r) {
			int u=read();
			addedge(i,u);
			g[u].push_back(i);
		}
	}
	SPFA();

	printf("%lld\n",k[1]);
	return 0;
}

