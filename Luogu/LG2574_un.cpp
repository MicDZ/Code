#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define ll long long
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int MAXN=100000+10;

int n,m,a[MAXN];

struct SegmentTree {
	int l,r;
	ll sum,add;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define sum(x) tree[x].sum
	#define add(x) tree[x].add
	#define len(x) (tree[x].r-tree[x].l+1)
}tree[MAXN<<2];

void build(int p,int l,int r) {
	l(p)=l;r(p)=r;
	if(l==r) {sum(p)=a[l]; return ;}
	int mid=(l+r)>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	sum(p)=sum(p*2)+sum(p*2+1);
}

void spread(int p) {
	if(add(p)) {
		
	}
}

void change(int p,int l,int r,int d) {
	if(l<=l(p)&&r>=r(p)) {
		sum(p)+=d*len(p);
		add(p)+=d;
		return ;
	}
	spread(p);
	int mid=(l(p)+r(p))>>1;
	if(l<=mid) change(p*2,l,r,d);
	if(r>mid) change(p*2+1,l,r,d);
	sum(p)=sum(p*2)+sum(p*2+1);
}

ll ask(int p,int l,int r) {
	if(l<=l(p)&&r>=r(p)) return sum(p);
	spread(p);
	int mid=(l(p)+r(p))>>1;
	ll ans=0;
	if(l<=mid) ans+=ask(p*2,l,r);
	if(r>mid) ans+=ask(p*2+1,l,r);
	return ans;
} 

int main() {
	n=read(),m=read();
	REP(i,1,n) scanf("%1d",a+1);
	build(1,1,n);
	REP(i,1,m) {
		int op=read(),x=read(),y=read();
		if(op==0) change(1,x,y,1);
		else printf("%lld\n",ask(1,x,y));
	}
	return 0;
}
