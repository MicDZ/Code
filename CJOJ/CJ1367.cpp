#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define REP(i,e,s) for(register int i=e; i<=s; i++)
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int MAXN=1500+10;
int s[MAXN][MAXN],fa[MAXN];

struct edge{
	int u,v,w;
}a[MAXN*MAXN];

bool cmp(edge a,edge b) {
	return a.w<b.w;
}

int find(int x) {
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}

void link(int x,int y) {
	fa[find(x)]=find(y);
}

int main() {
	int n=read();
	REP(i,1,n) fa[i]=i;
	REP(i,1,n) REP(j,1,n) s[i][j]=read();
	int cnt=0;
	REP(i,1,n) REP(j,i+1,n) a[++cnt].u=i,a[cnt].v=j,a[cnt].w=s[i][j];
	sort(a+1,a+1+cnt,cmp);

	int tot=0,ans=0;
	REP(i,1,cnt) {
		if(find(a[i].u)!=find(a[i].v)) {
			tot++;
			ans+=a[i].w;
			link(a[i].u,a[i].v);
		}
		
		if(tot==n-1) {
			printf("%d\n",ans);
			return 0;
		}
	}

}
