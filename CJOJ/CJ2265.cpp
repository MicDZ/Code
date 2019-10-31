#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;
#define ll long long
#define REP(i,e,s) for(register ll i=e; i<=s; i++)
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

const int INF=0x3f3f3f;

const int MAXN=200000+10;

struct SegmentTree {
	int l,r,v,dat,add,ld,rd;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define len(x) (tree[x].r-tree[x].l+1)
	#define add(x) tree[x].add
	#define dat(x) tree[x].dat
	#define v(x) tree[x].v
	#define ld(x) tree[x].ld
	#define rd(x) tree[x].rd
}tree[MAXN<<2];

void build(int p,int l,int r) {
	l(p)=l,r(p)=r;
	if(l==r) return ;
	int mid=(l(p)+r(p))>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
}

void spread(int p) {
	if (add(p)) {
		ld(p)=rd(p)=v(p)=1;
		dat(p)=len(p);
	} 
	else {
		ld(p)=ld(p*2);
		rd(p)=rd(p*2+1);
		dat(p)=dat(p*2)+dat(p*2+1);
		v(p)=v(p*2)+v(p*2+1);
		if(rd(p*2)&&ld(p*2+1)) v(p)--;
	}
}


void change(int p,int l,int r,int d) {
	if(l(p)>=l&&r(p)<=r) {
		add(p)+=d;
		if(l(p)==r(p)) {
			if(add(p)) dat(p)=rd(p)=ld(p)=v(p)=1;
			else dat(p)=rd(p)=ld(p)=v(p)=0;
		}
		else spread(p);
	}
	else {
		int mid=(l(p)+r(p))>>1;
		if(l<=mid) change(p*2,l,r,d);
		if(r>mid) change(p*2+1,l,r,d);

		spread(p);
	}
}

int main() {
	file("testdata");
	int l=read(),n=read();
	build(1,1,l+1);
	
	REP(i,1,n) {
		int op=read(),a=read()+1,t=read();
		if(op==1) 
			change(1,a,a+t-1,1);
		else change(1,a,a+t-1,-1);

		printf("%d %d\n",v(1),dat(1));
	}

	return 0;
}
