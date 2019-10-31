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

const int MAXN=200000+10;

struct SegmentTree{
	int l,r;
	ll dat,add;

	#define l(x) h[x].l
	#define r(x) h[x].r
	#define dat(x) h[x].dat
	#define add(x) h[x].add
}h[MAXN<<2];

ll a[MAXN];

void build(int x,int l,int r) {
	l(x)=l,r(x)=r;
	if(l==r) {
		dat(x)=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	dat(x)=max(dat(x*2),dat(x*2+1));
}

void change(int x,int ta,ll p) {
	if(l(x)==r(x)) {
		dat(x)=p;
		return ;
	}
	int mid=(l(x)+r(x))>>1;
	if(ta<=mid) change(x*2,ta,p);
	if(ta>mid) change(x*2+1,ta,p);

	dat(x)=max(dat(x*2),dat(x*2+1));
}

ll ask(int x,int l,int r) {
	if(l(x)>=l&&r(x)<=r) return dat(x);

	int mid=(l(x)+r(x))>>1;
	ll ans=0;
	if(l<=mid) ans=ask(x*2,l,r);
	if(r>mid) ans=max(ans,ask(x*2+1,l,r));

	return ans;
}

int main() {
	file("data0");
	ll n=read(),d=read();
	build(1,1,n);

	ll cnt=0;ll t=0;

	REP(i,1,n) {
		char op[4];
		scanf("%s",op+1);
		ll x=read();

		if(op[1]=='A') {
			cnt++;
			change(1,cnt,(x+t)%d);
		}
		else if(op[1]=='Q'){
			if(x==0) {
				puts("0");
				continue;
			}
			t=ask(1,cnt-x+1,cnt)%d;
			printf("%lld\n",t);
		}
	}
	return 0;
}
