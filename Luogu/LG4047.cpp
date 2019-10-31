#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
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

const int MAXN=1000+10;

int x[MAXN],y[MAXN],fa[MAXN];

double dist(int a,int b) {
	return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}

struct edge	{
	int u,v;
	double w;
}e[MAXN*MAXN];

bool cmp(edge a,edge b) {
	return a.w<b.w;
}

int find(int x) {
	if(fa[x]==x) return fa[x];
	return fa[x]=find(fa[x]);
}

int link(int x,int y) {
	fa[find(x)]=find(y);
}

int main() {
	int n=read(),k=read();
	REP(i,1,n) x[i]=read(),y[i]=read();
	REP(i,1,n) fa[i]=i;
	int cnt=0;
	REP(i,1,n) REP(j,1,n) {
		cnt++;
		e[cnt].u=i;
		e[cnt].v=j;
		e[cnt].w=dist(i,j);
	}

	sort(e+1,e+1+cnt,cmp);
	int tot=0;double minn=0x3f3f3f;
	REP(i,1,cnt) {
		if(find(e[i].u)==find(e[i].v)) continue;
		link(e[i].u,e[i].v);
		minn=min(minn,e[i].w);
		if(tot==k-1) break;
	}

	printf("%.2lf",minn);
	return 0;
}
