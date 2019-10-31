//////////////////////////////////////////////
// Author: MicDZ 
// Email: micdzcn@gmail.com 
// Last modified: 2019-07-31 09:16
// Filename: LG1576.cpp
//////////////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int MAXN=200000+10,INF=0x3f3f3f;
int head[MAXN],to[MAXN],_next[MAXN],cnt;
double weigh[MAXN],dist[MAXN];

void addedge(int u,int v,double w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	weigh[cnt]=w;
	to[cnt]=v;
}
bool inq[MAXN];
queue<int> q;

void SPFA(int s) {
	inq[s]=1;
	q.push(s);
	dist[s]=1;
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		inq[u]=0;
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(dist[v]<dist[u]*weigh[i]) {
				dist[v]=dist[u]*weigh[i];
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
	REP(i,1,m) {
		int u=read(),v=read();
		double w=read();
		addedge(u,v,1.0-w*1.0/100);
		addedge(v,u,1.0-w*1.0/100);
	}


	int s=read(),t=read();
	SPFA(s);

	printf("%.8lf",100/dist[t]);
	return 0;
}
