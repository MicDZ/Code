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
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=50000+10,INF=0x3f3f3f3f;

int a[MAXN];

struct SegmentTree {
	int l,r,prel,prer,res,sum;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define prel(x) tree[x].prel
	#define prer(x) tree[x].prer
	#define res(x) tree[x].res
	#define sum(x) tree[x].sum
} tree[MAXN<<2];

void pushup(int p) {
	sum(p)=sum(p*2)+sum(p*2+1);
	prel(p)=max(prel(p*2),sum(p*2)+prel(p*2+1));
	prer(p)=max(prer(p*2+1),sum(p*2+1)+prer(p*2));
	res(p)=max(prer(p*2)+prel(p*2+1),max(res(p*2),res(p*2+1)));
}

void build(int p,int l,int r) {
	l(p)=l,r(p)=r;
	if(l==r) {
		prel(p)=prer(p)=res(p)=sum(p)=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	pushup(p);
}

void change(int p,int x,int d) {
	if(l(p)==r(p)) {
		prel(p)=prer(p)=res(p)=sum(p)=d;
		return ;
	}
	int mid=(l(p)+r(p))>>1;
	if(x<=mid) change(p*2,x,d);
	else change(p*2+1,x,d);
	pushup(p);
}

int ans,pre;

void ask(int p,int l,int r) {
	if(l(p)>=l&&r(p)<=r) {
		ans=max(ans,res(p));
		ans=max(ans,pre+prel(p));
		pre=max(prer(p),pre+sum(p));
		return ;
	}
	int mid=(l(p)+r(p))>>1;
	
	if(l<=mid) ask(p*2,l,r);
	if(r>mid) ask(p*2+1,l,r);
}
6.90MB
int main() {
	int n=read();
	REP(i,1,n) a[i]=read();
	build(1,1,n);
	int q=read();
	REP(i,1,q) {
		int op=read(),x=read(),y=read();
		if(op==0) change(1,x,y);
		if(op==1) ans=-INF,pre=-INF,ask(1,x,y),printf("%d \n",ans);
	}
	return 0;
}
