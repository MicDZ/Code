#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define DE(...) fprintf(stderr,__VA_ARGS__);
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define ll long long

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int INF=0x3f3f3f,MAXN=50000+10;
int fa[MAXN];

struct soilder {
	int u,v,w;
}a[MAXN];

bool cmp(soilder a,soilder b) {
	return a.w>b.w;
}

int find(int x) {
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

void link(int x,int y) {
	fa[find(x)]=find(y);
}

int main() {
	int t=read();
	while(t--) {
		int n=read(),m=read(),r=read();
		REP(i,1,r) {
			a[i].u=read()+1;
			a[i].v=read()+1+n;
			a[i].w=read();
		}
		
		REP(i,1,n+m) fa[i]=i;	
		
		sort(a+1,a+1+r,cmp);

		int ans=(n+m)*10000,cnt=0;

		REP(i,1,r) {
			if(find(a[i].u)==find(a[i].v)) continue;
			link(a[i].u,a[i].v);
			ans-=a[i].w;
			cnt++;
			if(cnt==n+m-1) break;
		}

		printf("%d\n",ans);
	}
	return 0;
}

