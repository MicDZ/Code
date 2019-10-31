#include<bits/stdc++.h>
using namespace std;

const int MAXN=400000+10;
#define REP(i,e,s) for(register int i=e; i<=s; i++)
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int head[MAXN],_next[MAXN],to[MAXN],weigh[MAXN],cnt,dis[MAXN];
bool vis[MAXN];
void addedge(int u,int v,int w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
}

typedef pair<int,int> p;
priority_queue <p,vector<p>,greater<p> > q;


int main() {
		//freopen("test.in","r",stdin);
	int n=read(),m=read();
	REP(i,1,m) {
		int u=read(),v=read(),w=read();
		addedge(u,v,w);
		addedge(v,u,w);
	}

	memset(dis,127,sizeof(dis));
	dis[1]=0;
	q.push(make_pair(0,1));
	int tot=0,sum=0;  
	while(!q.empty()&&tot<n) {
		int d=q.top().first,u=q.top().second;
		//puts("in");
		q.pop();
		if(vis[u]) continue;
		tot++; sum+=d;
		vis[u]=1;
		for(int i=head[u]; i; i=_next[i]) if(weigh[i]<dis[to[i]]) {
			dis[to[i]]=weigh[i];
			q.push(make_pair(dis[to[i]],to[i]));
		}
	}

	printf("%d\n",sum);
	return 0;
} 
