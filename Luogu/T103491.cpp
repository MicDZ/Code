#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

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

const int MAXN=200000+10;

int sta[MAXN];

struct edge {
	int u,v,w;
}a[MAXN];

bool cmp(edge a,edge b) {
	return a.w<b.w;
}

int fa[MAXN];

int find(int x) {
	if(fa[x]==x) return fa[x];
	return fa[x]=find(fa[x]);
}

void link(int x,int y) {
	fa[find(x)]=find(y);
}

int main() {
	int n=read(),s=read(),m=read();

	REP(i,1,s) sta[read()]=1;

	REP(i,1,m) 
		a[i].u=read(),a[i].v=read(),a[i].w=read();

	sort(a+1,a+1+m,cmp);
	
	REP(i,1,n) fa[i]=i;
	
	int num=0;
	
	REP(i,1,m) {
		if(find(a[i].u)==find(a[i].v)) continue;
		link(a[i].u,a[i].v);
		addedge(a[i].u,a[i],v,a[i].w);
	}

	return 0;
}
