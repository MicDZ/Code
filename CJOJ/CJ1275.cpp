#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;
#define REP(i,e,s) for(register int i=e; i<=s; i++)
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=500+10,MAXM=50000+10;

struct edge {
	int u,v,w;
}a[MAXM];

bool cmp(edge a,edge b) {
	return a.w<b.w;
}
int fa[MAXN];

int find(int x) {
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int link(int x,int y) {
	fa[find(x)]=find(y);
}
int main() {
	int n=read(),m=read();
	REP(i,1,n) fa[i]=i;
	REP(i,1,m) {
		a[i].u=read();
		a[i].v=read();
		a[i].w=read();
		link(a[i].u,a[i].v);
	}
	
	int s=read(),t=read();
	
	if(find(s)!=find(t)) {puts("IMPOSSIBLE");return 0;}

	
	sort(a+1,a+1+m,cmp);
	
	
	int maxx=0,minn=0;
	REP(i,1,m) {
		REP(j,1,n) fa[j]=j;
		int now=0;
		for(now=i; now<=m; now++) {
		//	now=j;
			if(find(a[now].u)==find(a[now].v)) continue;
			link(a[now].u,a[now].v);
			if(find(s)==find(t)) break;
		}
		if(find(s)!=find(t)) break;
		if(maxx*a[i].w>=a[now].w*minn) maxx=a[now].w,minn=a[i].w;
	}
	int g=__gcd(maxx,minn);
	if(minn/g!=1)
	printf("%d/%d\n",maxx/g,minn/g);
	else printf("%d\n",maxx/g);
	return 0;
}
