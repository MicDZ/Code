#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define int ll
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
		return ;
	}
	int mid=(l+r)>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
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


int f[MAXN],pre[MAXN],last[MAXN];

signed main() {
	int n=read(),m=read();
	REP(i,1,n) f[i]=read();
	REP(i,1,m) a[i]=read();
	build(1,1,n);
	int ans=0;
	REP(i,1,n) {
		pre[i]=last[f[i]],last[f[i]]=i;

		if(pre[i]) change(1,pre[i],-a[f[i]]);
	
		if(pre[pre[i]]) change(1,pre[pre[i]],0);
		change(1,i,a[f[i]]);
		ans=max(ans,res(1));
	}

	printf("%lld\n",ans);
	return 0;
}

