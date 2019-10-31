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

const int MAXN=2000000+10;
struct SegmentTree {
	int l,r;
	ll sum,add;
	#define l(x) h[x].l
	#define r(x) h[x].r
	#define sum(x) h[x].sum
	#define add(x) h[x].add
}h[MAXN<<2];

int a[MAXN];

void build(int x,int l,int r) {
	l(x)=l,r(x)=r;
	if(l==r) {
		sum(x)=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	sum(x)=sum(x*2)+sum(x*2+1);
}

void spread(ll x) {
	if(add(x)) {
		sum(x*2)+=add(x)*(r(x*2)-l(x*2)+1);
		sum(x*2+1)+=add(x)*(r(x*2+1)-l(x*2+1)+1);
		add(x*2)+=add(x);
		add(x*2+1)+=add(x);
		add(x)=0;
	}
}

void change(int x,int l,int r,ll p) {
	if(l(x)>=l&&r(x)<=r) {
		sum(x)+=(r(x)-l(x)+1)*p;
		add(x)+=p;
		return ;
	}
	spread(x);
	int mid=(l(x)+r(x))>>1;
	if(l<=mid) change(x*2,l,r,p);
	if(r>mid) change(x*2+1,l,r,p);
	sum(x)=sum(x*2)+sum(x*2+1);}

ll ask(int x,int l,int r) {
	if(l(x)>=l&&r(x)<=r) return sum(x);
	spread(x);
	int mid=(l(x)+r(x))>>1;
	ll ans=0;
	if(l<=mid) ans+=ask(x*2,l,r);
	if(r>mid) ans+=ask(x*2+1,l,r);
	return ans;
}

int main() {
	int t=read();
	REP(tt,1,t) {
		memset(h,0,sizeof(h));
		memset(a,0,sizeof(a));
		int n=read(),m=read();
		REP(i,1,n) a[i]=read();
		build(1,1,n);
		REP(i,1,m) {
			char op[5];
			scanf("%s",op+1);
			if(op[1]=='Q') {
				int a=read()+1,b=read()+1;
				printf("%lld\n",ask(1,a,b));
			}
			else if(op[1]=='C') {
				int a=read()+1,b=read()+1,c=read();
				change(1,a,b,c);
			}
		}
	}	
return 0;
}