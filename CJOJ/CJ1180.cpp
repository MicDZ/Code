#include<bits/stdc++.h>
using namespace std;
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define INF 0x3f3f3f
#define ll long long

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int MAXN=10000+10,MAXM=130000+10;

ll last[MAXN];;
ll n,m,s,t,nn;
int aa[MAXN],_next[MAXM],to[MAXM],weigh[MAXM],cnt,head[MAXN];

void addedge(int u,int v,int w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
}

ll inq[MAXN],d[MAXN];
void spfa() {
	queue<ll> q;
	memset(inq,0,sizeof(inq));
	REP(i,1,n) d[i]=INF;

	d[s]=0;
	inq[s]=1;
	q.push(s);
	while(!q.empty()) {
		ll u=q.front();
		q.pop();
		inq[u]=0;
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i],w=weigh[i];
			if(d[v]>d[u]+w) {
				d[v]=d[u]+w;
				if(!inq[v]) {
					inq[v]=1;
					q.push(v);
				}
			}
		}
	}
	//cout<<d[t]<<endl;
}


int main() {
	memset(last,-1,sizeof(last));
	nn=read(),n=read(),m=read();
	REP(i,1,nn) aa[i]=read();
	REP(i,1,m) {
		long long u=read(),v=read(),w=read();
		addedge(u,v,w);
		addedge(v,u,w);
	}
	int ans=INF;
	REP(i,1,n) {
		s=i;
		spfa();
		int s=0;
		REP(j,1,nn) 
			s+=d[aa[j]];
		ans=min(ans,s);
	}
	printf("%d\n",ans);
}

