#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>

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

const int MAXN=1000000+10,INF=0x3f3f3f3f;

int n,x;

int a[MAXN];
map<int,int> f;

	queue<pair<int,int> > q;
namespace luangao {
	int greedy() {
		int ans=0,now=x;
		DREP(i,n,1) {
			if(a[i]==0) continue;
			ans+=now/a[i];
			now-=now/a[i]*a[i];
		}
		if(now!=0) return INF;
		return ans;
	}


	int bfs() {
		q.push(make_pair(0,0));
		while(!q.empty()) {
			pair<int,int> u=q.front();q.pop();
			if(u.first==x) return u.second;
			REP(i,1,n) {
				if(u.first<x&&!f[u.first+a[i]]) f[u.first+a[i]]=1,q.push(make_pair(u.first+a[i],u.second+1));
				if(u.first>x&&!f[u.first-a[i]]) f[u.first-a[i]]=1,q.push(make_pair(u.first-a[i],u.second+1));
			}
			if(q.size()>1000000) return INF;
		}
		return INF;
	}

	void main() {
		x=read();
		while(scanf("%lld",&a[n+1])!=EOF) n++;
		sort(a+1,a+1+n);
		f[0]=1;
		if(!x) puts("0");
		else printf("%lld\n",min(bfs(),greedy()));
	}

}

signed main() {
	luangao::main();
}


