#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define int ll
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
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

const int MAXN=100000+10,INF=0x3f3f3f3f3f3f3f;

int _next[MAXN],pre[MAXN],a[MAXN];

struct edge {
	int id,w;
};

bool const operator<(edge a,edge b) {
	return a.w>b.w;
}

priority_queue<edge> q;

bool merged[MAXN];

signed main() {
	int n=read(),k=read();
	REP(i,1,n) a[i]=read();
	REP(i,1,n-1)pre[i]=i-1,_next[i]=i+1;
	REP(i,1,n-1) a[i]=a[i+1]-a[i];
	a[0]=a[n]=INF;
	
	REP(i,1,n-1) q.push((edge){i,a[i]});
	int ans=0;
	while(k--) {
		int u=q.top().id,w=q.top().w;q.pop();
		while(merged[u]) {
			u=q.top().id;
			w=q.top().w;
			q.pop();
		}
		ans+=w;
		a[u]=a[pre[u]]+a[_next[u]]-a[u];
		q.push((edge){u,a[u]});
		merged[pre[u]]=merged[_next[u]]=1;
		pre[u]=pre[pre[u]];
		pre[_next[u]]=u;

		_next[pre[u]]=u;
		_next[u]=_next[_next[u]];	
	}

	printf("%lld\n",ans);
	return 0;
}
