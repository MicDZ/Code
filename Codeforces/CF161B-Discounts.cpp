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

const int MAXN=100000+10,INF=0x3f3f3f3f;

struct item {
	int c,t,id;
} a[MAXN];

bool cmp(item a,item b) {
	if(a.t==b.t) return a.c>b.c;
	return a.t<b.t;
}

int main() {
	int n=read(),k=read(),minn=INF;
	REP(i,1,n) a[i]=(item){read(),read(),i};
	REP(i,1,n) minn=min(minn,a[i].c);
	sort(a+1,a+1+n,cmp);
	double ans=0;
	int pos=0;
	for(int i=1; i<=k-1&&a[i].t==1; i++) {
		pos=i;
		if(a[i].t!=1) break;
		ans+=1.0*a[i].c*0.5;
	}
	pos++;
	if(a[k].t==1) ans-=minn*0.5;
	
	REP(i,pos,n) ans+=a[i].c;
	printf("%.1lf\n",ans);
	printf("%d ",n-k+1);
	REP(i,k,n) printf("%d ",a[i].id);
	puts("");
	REP(i,1,k-1) printf("1 %d\n",a[i].id);
		return 0;
}
