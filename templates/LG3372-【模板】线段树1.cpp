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

#define int ll

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=100000+10;

struct SegmentTree {
	int l,r,sum,add;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define sum(x) tree[x].sum
	#define add(x) tree[x].add
	#define len(x) (tree[x].r-tree[x].l+1)
} tree[MAXN<<2];

int a[MAXN];

void spread(int p) {
	if(add(p)) {
		add(p*2)+=add(p);
		add(p*2+1)+=add(p);
		sum(p*2)+=len(p*2)*add(p);
		sum(p*2+1)+=len(p*2+1)*add(p);
		add(p)=0;
	}
}

void build(int p,int l,int r) {
	l(p)=l,r(p)=r;
	if(l==r) {
		sum(p)=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);

	sum(p)=sum(p*2)+sum(p*2+1);
}

void change(int p,int l,int r,int d) {
	if(l(p)>=l&&r(p)<=r) {
		add(p)+=d;
		sum(p)+=len(p)*d;
		return ;
	}
	spread(p);
	int mid=(l(p)+r(p))>>1;
	
	if(l<=mid) change(p*2,l,r,d);
	if(r>mid) change(p*2+1,l,r,d);

	sum(p)=sum(p*2)+sum(p*2+1);
}

int ask(int p,int l,int r) {
	if(l(p)>=l&&r(p)<=r) return sum(p);
	spread(p);
	int mid=(l(p)+r(p))>>1;
	int ans=0;
	if(l<=mid) ans+=ask(p*2,l,r);
	if(r>mid) ans+=ask(p*2+1,l,r);

	return ans;
}

signed main() {
	int n=read(),m=read();
	REP(i,1,n) a[i]=read();
	build(1,1,n);
	
	REP(i,1,m) {
		int op=read();
		if(op==1) {
			int x=read(),y=read(),k=read();
			change(1,x,y,k);
		}
		if(op==2) {
			int x=read(),y=read();
			printf("%lld\n",ask(1,x,y));
		}
	}
	return 0;
}
