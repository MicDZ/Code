#include<bits/stdc++.h>
using namespace std;
#define MAXN 2000+10
#define MAXM 2000000+10

#define INF 0x3f3f3f

int read() {
     int x=0,f=1;
     char ch=getchar();
     while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
     while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
     return x*f;
}

int next[MAXM],head[MAXN],to[MAXM],weigh[MAXM],cnt,have[MAXN][MAXN];

void addedge(int u,int v,int w) {
	cnt++;
	to[cnt]=v;
	next[cnt]=head[u];
	head[u]=cnt;
	weigh[cnt]=w;
}

int last[MAXN];

int d[MAXN],inq[MAXN];

bool after_first_spfa=0;

void SPFA() {
	memset(d,INF,sizeof(d));
	memset(inq,0,sizeof(inq));
	queue<int> q;
	q.push(1); d[1]=0;
	inq[1]=1;
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		inq[u]=0;
		for(int i=head[u]; i; i=next[i]) {
			int v=to[i],w=weigh[i];
			if(!have[u][v]&&d[u]+w<d[v]) {
				d[v]=d[u]+w;
				if(!after_first_spfa)last[v]=u;
				if(!inq[v]) {
					inq[v]=1;
					q.push(v);
				}
			}
		}
	}
}

int main() {
	int n=read(),m=read();
	for(int i=1; i<=m; i++) {
		int u=read(),v=read(),w=read();
		addedge(u,v,w);
		addedge(v,u,w);
	}
	SPFA();
	after_first_spfa=1;
	int ans=0;
	for(int i=n; i>1; i=last[i]) {
		int u=last[i];
		have[i][u]=1;
		have[u][i]=1;
		SPFA();
		ans=max(ans,d[n]);
		//cout<<d[n]<<endl;
		have[i][u]=0;
		have[u][i]=0;
	}
	cout<<ans<<endl;
}
