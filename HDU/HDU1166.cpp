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


ll read() {
	ll x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int INF=0x3f3f3f,MAXN=100000+10;

ll a[MAXN];

struct SegmentTree {
	int l,r;
	ll dat,add;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define dat(x) tree[x].dat
	#define add(x) tree[x].add
	#define len(x) (r(x)-l(x)+1)
}tree[MAXN<<2];

void build(int p,int l,int r) {
	l(p)=l,r(p)=r;add(p)=0;
	if(l==r) {
		dat(p)=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	dat(p)=dat(p*2)+dat(p*2+1);
}

void change(int p,int x,int d) {
	if(l(p)==r(p)) {
		dat(p)+=d;
		return ;
	}
	int mid=(l(p)+r(p))>>1;
	if(x<=mid) change(p*2,x,d);
	if(x>mid) change(p*2+1,x,d);
	dat(p)=dat(p*2)+dat(p*2+1);
}

ll ask(int p,int l,int r) {
	if(l(p)>=l&&r(p)<=r) return dat(p);
	int mid=(l(p)+r(p))>>1;
	ll ans=0;
	if(l<=mid) ans+=ask(p*2,l,r);
	if(r>mid) ans+=ask(p*2+1,l,r);
	return ans;
}

int main() {
	file("HDU1166");
	int T=read();
	REP(t,1,T) {
		printf("Case %d:\n",t);
		memset(tree,0,sizeof(tree));
		int n=read();
		REP(i,1,n) a[i]=read();
		build(1,1,n);
		char op[10];
		scanf("%s",op+1);
		while(op[1]!='E') {
			if(op[1]=='A') {
				int x=read(),y=read();
				change(1,x,y);
			}
			if(op[1]=='S') {
				int x=read(),y=read();
				change(1,x,-y);
			}
			if(op[1]=='Q') {
				int x=read(),y=read();
				printf("%lld\n",ask(1,x,y));
			}
			scanf("%s",op+1);
		}
	}	
	return 0;
}