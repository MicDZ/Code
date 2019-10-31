#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>

using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define mark(a,b) a+m*(b-1)
#define ll long long

ll read() {
	ll x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=50+5,MAXM=810000+10;

int n,m,t,head[MAXM],_next[MAXM],to[MAXM],weigh[MAXM],cnt,a[MAXN][MAXN];

int dx[]={0,1,-1,0,0};
int dy[]={0,0,0,-1,1};


void addedge(int u,int v,int w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
}

int inq[MAXM],dist[MAXM];

queue<int> q;

void SPFA(int s) {
	q.push(s);
	inq[s]=1;	
	//dist[s]=0;
	while(!q.empty()) {
		int u=q.front();q.pop();
		inq[u]=0;
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(dist[v]>dist[u]+weigh[i]) {
				dist[v]=dist[u]+weigh[i];
				if(!inq[v]&&dist[v]<=t) {
					inq[v]=1;
					q.push(v);
				}
			}
		}
	}

}

double dis(int x1,int y1,int x2,int y2) {
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main() {
	n=read(),m=read(),t=read();
	REP(i,1,n) REP(j,1,m) scanf("%1d",&a[i][j]);

	REP(i,1,n) REP(j,1,m) {
		REP(k,1,4) {
			int x=i+dx[k],y=j+dy[k];
			if(x<1||x>n||y<1||y>m) continue;
			if(a[x][y]) addedge(mark(i,j),mark(x,y),1);
			else addedge(mark(i,j),mark(x,y),0);
		}
	}
	
	double ans=0;

	REP(i,1,n) REP(j,1,m) {
		REP(x,1,n*m) inq[x]=0,dist[x]=810000;	

		if(a[i][j]) dist[mark(i,j)]=1;
		else dist[mark(i,j)]=0;
		
		SPFA(mark(i,j));

		REP(x,1,n) REP(y,1,m) {
			if(dist[mark(x,y)]<=t) {

				ans=max(ans,dis(i,j,x,y));
			}
		}
	}

	printf("%.6f\n",ans);
	return 0;
}

