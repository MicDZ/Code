#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;
#define ll long long
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define DE(...) fprintf(stderr,__VA_ARGS__);
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)


int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int INF=0x3f3f3f,MAXN=100000+10;

int a[MAXN];

struct SegmentTree {
	int l,r,dat,add;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define dat(x) tree[x].dat
	#define add(x) tree[x].add
	#define len(x) (r(x)-l(x)+1)
}tree[MAXN<<2];

void build(int p,int l,int r) {
	l(p)=l,r(p)=r;add(p)=0;
	if(l==r) {
		dat(p)=1;
		return ;
	}
	int mid=(l+r)>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	dat(p)=dat(p*2)+dat(p*2+1);
}

void spread(int p) {
	if(add(p)) {
		dat(p*2)=add(p)*len(p*2);
		dat(p*2+1)=add(p)*len(p*2+1);
		add(p*2)=add(p);
		add(p*2+1)=add(p);
		add(p)=0;
	}
}

void change(int p,int l,int r,int d) {
	if(l(p)>=l&&r(p)<=r) {
		add(p)=d;
		dat(p)=add(p)*len(p);
		return ;
	}
	spread(p);
	int mid=(l(p)+r(p))>>1;
	if(l<=mid) change(p*2,l,r,d);
	if(r>mid) change(p*2+1,l,r,d);
	dat(p)=dat(p*2)+dat(p*2+1);
}


int main() {
	int T=read();
	REP(t,1,T) {
		memset(tree,0,sizeof(tree));
		int n=read(),m=read();
		build(1,1,n);
		REP(i,1,m) {
			int x=read(),y=read(),z=read();
			change(1,x,y,z);
		}
		printf("Case %d: The total value of the hook is %d.\n",t,dat(1));
	}	
	return 0;
}