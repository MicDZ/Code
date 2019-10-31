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

const int INF=0x3f3f3f,MAXN=20000+10,MAXM=100000+10;

int fa[MAXN];

struct crime {
	int a,b,c;
}cr[MAXM];

bool cmp(crime x,crime y) {
	return x.c>y.c;
}

int find(int x) {
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

int link(int x,int y) {
	fa[find(x)]=find(y);
}

int mark[MAXN];

int main() {
	int n=read(),m=read();
	REP(i,1,n) fa[i]=i;
	REP(i,1,m) cr[i].a=read(),cr[i].b=read(),cr[i].c=read();

	sort(cr+1,cr+1+m,cmp);

	REP(i,1,m) {
		if(find(cr[i].a)==find(cr[i].b)) {printf("%d\n",cr[i].c); return 0;}
		else {
			if(!mark[cr[i].a]) mark[cr[i].a]=cr[i].b;
			else link(mark[cr[i].a],cr[i].b);

			if(!mark[cr[i].b]) mark[cr[i].b]=cr[i].a;
			else link(mark[cr[i].b],cr[i].a);
		}
	}
	puts("0");
	return 0;
}

