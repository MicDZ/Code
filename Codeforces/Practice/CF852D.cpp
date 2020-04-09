#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>

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

int n,m,p,k,s,t;

const int MAXN=5000+10,MAXM=200000+10,INF=0x3f3f3f3f;	

int cur[MAXM],head[MAXM],_next[MAXM<<1],to[MAXM<<1],weigh[MAXM<<1],cnt=1;

void add(int u,int v,int w) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
	weigh[cnt]=w;
}

void addedge(int u,int v) {
	add(u,v,1);
	add(v,u,0);
}

int a[MAXN][MAXN];

int x[MAXM];

queue<int> q;
int dept[MAXM];

bool bfs() {
	q.push(s);
	REP(i,1,n+n+2) dept[i]=-1;
	dept[s]=0;
	while(!q.empty()) {
		int u=q.front();q.pop();
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(weigh[i]&&dept[v]==-1) {
				dept[v]=dept[u]+1;
				q.push(v);
			}
		}

	}
	return dept[t]!=-1;
}

int dfs(int u,int minn) {
	if(!minn||u==t) return minn;
	int ft=0,sum=0;
	for(int i=cur[u]; i; i=_next[i]) {
		cur[u]=i;
		int v=to[i];
		if(dept[v]!=dept[u]+1||!weigh[i]) continue;
		ft=dfs(v,min(minn-sum,weigh[i]));
		if(!ft) continue;
		
		weigh[i]-=ft;
		weigh[i^1]+=ft;
		sum+=ft;
		if(!minn) return ft;
	}

	return sum;
}

bool check(int mid) {
	
	s=n+n+1,t=n+n+2;
	REP(i,1,n+n+2) head[i]=0;cnt=1;
	
	REP(i,1,p) addedge(s,x[i]);
	REP(i,1,p) {
		REP(j,1,n) {
			if(a[x[i]][j]<=mid) addedge(x[i],j+n);
		}
	}

	REP(i,1,n) addedge(i+n,t);

	
	int ans=0;
	while(bfs()) {
		REP(i,1,n+n+2) cur[i]=head[i];
		while(1) {
			int x=dfs(s,INF);
			if(!x) break;
			ans+=x;
		}
	}
	return ans>=k;	
}

int main() {
	//file("CF852D");
	n=read(),m=read(),p=read(),k=read();
	REP(i,1,p) x[i]=read();
	REP(i,1,n) REP(j,1,n) a[i][j]=INF;
	
	REP(i,1,m) {
		int u=read(),v=read(),w=read();
		a[u][v]=a[v][u]=min(a[u][v],w);
	}
		
	REP(k,1,n) REP(i,1,n) REP(j,1,n) a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	REP(i,1,n) a[i][i]=0;
	
	int l=0,r=1731312;
	while(l<r) {
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}

	printf("%d\n",l==1731312?-1:r);
	return 0;
}

