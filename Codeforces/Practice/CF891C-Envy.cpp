#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

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

const int MAXN=500000+10;

struct edge {
	int u,v,w,id;
} a[MAXN],p[MAXN];

bool cmp1(edge a,edge b) {
	return a.w<b.w;
}

bool cmp2(edge a,edge b) {
	return a.id<b.id;
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
	REP(i,1,m) a[i]=(edge){read(),read(),read(),i};

	sort(a+1,a+1+m,cmp1);

	REP(i,1,n) fa[i]=i;
	
	for(int i=1,j=1; i<=m; i=j=j+1) {
		while(j<m&&a[j].w==a[j+1].w) j++;
		REP(k,i,j) a[k].u=find(a[k].u),a[k].v=find(a[k].v);
		REP(k,i,j) {
			if(find(a[k].u)==find(a[k].v)) continue;
			link(a[k].u,a[k].v);
		}
	}

	sort(a+1,a+1+m,cmp2);

	int q=read();

	REP(t,1,q) {
		bool flag=1;
		int w=read();
		REP(i,1,w) p[i]=a[read()];
		sort(p+1,p+1+w,cmp1);
		for(int i=1,j=1; i<=w; i=j=j+1) {
			while(j<w&&p[j].w==p[j+1].w) j++;
			REP(k,i,j) fa[p[k].u]=p[k].u,fa[p[k].v]=p[k].v;
			REP(k,i,j) {
				if(find(p[k].u)==find(p[k].v)) flag=0;
				link(p[k].u,p[k].v);
			}
		}	
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}
