#include<bits/stdc++.h>
using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)

const int MAXN=1000+10,MAXM=5000000+10,INF=0x3f3f3f;

int f[MAXN],hd[MAXN],x[MAXN],y[MAXN],cnt,maxx=-INF;

struct edge {
	int u,v,s;
} a[MAXM];

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
bool cmp(edge a,edge b) {
	return a.s<b.s;
}
int dist(int x1,int x2,int y1,int y2) {
	return sqrt(pow((x1-x2),2)+pow((y1-y2),2));
}
int main() {
	int m=read();
	REP(i,1,m) hd[i]=read();
	int n=read();
	REP(i,1,n) x[i]=read(),y[i]=read();
	REP(i,1,n) REP(j,i+1,n) {
		cnt++;
		a[cnt].u=i;
		a[cnt].v=j;
		a[cnt].s=dist(x[i],x[j],y[i],y[j]);
	}

	sort(a+1,a+1+cnt,cmp);
	REP(i,1,MAXN)f[i]=i;
	int ans=0,s=0;
	REP(i,1,cnt) {
		if(find(a[i].u)!=find(a[i].v)) {
			link(a[i].u,a[i].v);
			s++;
			if(a[i].s>maxx)maxx=a[i].s;
			if(s==n-1) {
				int shu=0;
				//cout<<maxx;
				for(int i=1; i<=m; i++)if(hd[i]>=maxx)shu++;
				cout<<shu<<endl;
				return 0;
			}
		}
	}
	cout<<0;
	return 0;
}

