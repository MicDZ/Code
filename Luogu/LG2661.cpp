

#include<bits/stdc++.h>
using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define INF 0x3f3f3f3f

#define ll int
inline char nc(){	static char buf[100000], *p1 = buf, *p2 = buf;	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;}
inline ll read(){	
	char ch = nc();	
	ll sum = 0;
	while (!(ch >= '0'&&ch <= '9'))	{
		ch = nc();	
		if (ch == EOF)  return EOF;	
	}	
	while (ch >= '0'&&ch <= '9') {
		sum = sum * 10 + ch - 48;
		ch = nc();
		if (ch == EOF)  return EOF;	
	}	
	return sum;
}


#define MAXN 200000+10
ll fa[MAXN];

ll dist[MAXN];

inline ll find(ll x) {
	if(fa[x]!=x) {
		int l=fa[x];
		fa[x]=find(fa[x]);
		dist[x]+=dist[l];
	}
	return fa[x];
}

inline void link(ll a,ll b) {
	fa[find(a)]=find(b);
}


int main() {
	ll n=read();
	REP(i,1,n) fa[i]=i;
	ll minn=INF;
	REP(i,1,n) {
		ll a=read();
		if(find(i)!=find(a)) {
			link(i,a);
			dist[i]=dist[a]+1;
		}
		else minn=min(minn,dist[i]+dist[a]+1);
	}
	printf("%d\n",minn);
}
