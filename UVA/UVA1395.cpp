//////////////////////////////////////////////
// Author: MicDZ 
// Email: me@micdz.cn 
// Last modified: 2019-07-31 18:17
// Filename: UVA1395.cpp
//////////////////////////////////////////////
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;
#define REP(i,e,s) for(register int i=e; i<=s; i++)
ll read() {
    ll x=0,f=1,ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

const int MAXN=20000+10,INF=0x3f3f3f3f;
ll n,m;
struct edge {
    ll u,v,w;
}a[MAXN];

bool cmp(edge a,edge b) {
    return a.w<b.w;
}
ll fa[MAXN];

ll find(ll x) {
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void link(ll x,ll y) {
    fa[find(x)]=find(y);
}
ll id;
bool kruskal(ll s) {
	REP(j,0,n) fa[j]=j;
    int cnt=0;
    REP(i,s,m) {
    	//  now=j;
    	if(find(a[i].u)==find(a[i].v)) continue;
    	link(a[i].u,a[i].v);
		cnt++;
		id=i;
    	if(cnt==n-1) return 1;
	}

	return 0;
}

int main() {
	while(scanf("%d%d",&n,&m)&&(n||m)){
	
   		REP(i,1,m) {
        	a[i].u=read();
        	a[i].v=read();
        	a[i].w=read();
        //link(a[i].u,a[i].v);
    	}
    
   		sort(a+1,a+1+m,cmp);
    
    	ll ans=INF;
    	REP(i,1,m) {
			if(kruskal(i)) ans=min(ans,a[id].w-a[i].w);
		}
		if(ans==INF) puts("-1");
		else printf("%d\n",ans);
	}
    return 0;
}
