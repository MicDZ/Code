#include<bits/stdc++.h>
using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)

const int MAXN=200000+10,INF=0x3f3f3f;

int f[MAXN];
struct point {
	int u,v,s;
} a[MAXN];
int read(){
    int f=1,x=0,ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int find(int x) {
	if(f[x]==x)return f[x];
	return f[x]=find(f[x]);
}
int link(int x,int y) {
	f[find(x)]=find(y);
}
bool cmp(point a,point b) {
	return a.s<b.s;
}
int main() {
	int n=read(),m=read();
	REP(i,1,m)
	a[i].u=read(),a[i].v=read(),a[i].s=read();
	sort(a+1,a+1+m,cmp);
	REP(i,1,n) f[i]=i;
	int ans=0,s=0,maxx=-INF;
	REP(i,1,m) {
		if(find(a[i].u)!=find(a[i].v)) {
			link(a[i].u,a[i].v),ans+=a[i].s;
			s++;
			if(a[i].s>maxx)maxx=a[i].s;
			if(s==n-1) {
				printf("%d %d\n",n-1,maxx);
				return 0;
			}
		}
	}
	return 0;
}


