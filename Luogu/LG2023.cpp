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


ll read() {
	ll x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int INF=0x3f3f3f,MAXN=1000000+10;

struct SegmentTree {
	ll l,r;
	ll sum,add,times;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define sum(x) tree[x].sum
	#define add(x) tree[x].add
	#define times(x) tree[x].times
	#define len(x) (r(x)-l(x)+1)
} tree[MAXN<<2];

int n,m;
ll mod,a[MAXN];

void build(int p,int l,int r) {
	l(p)=l,r(p)=r;
	add(p)=0,times(p)=1;
	if(l==r) {
		sum(p)=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	sum(p)=(sum(p*2)+sum(p*2+1))%mod;
}

void spread(int p,int l,int r) {   
	int m=(l+r)/2;
	sum(p*2)=((sum(p*2)*times(p))%mod+(add(p)*(m-l+1)%mod))%mod;
	sum(p*2+1)=((sum(p*2+1)*times(p))%mod+(add(p)*(r-m))%mod)%mod;
	times(p*2)=(times(p*2)*times(p))%mod;
	times(p*2+1)=(times(p*2+1)*times(p))%mod;
	add(p*2)=((add(p*2)*times(p))%mod+add(p))%mod;
	add(p*2+1)=((add(p*2+1)*times(p))%mod+add(p))%mod;
	add(p)=0;
	times(p)=1;			
}

void plu(int p,int l,int r,ll d) {
	if(l(p)>r||r(p)<l) return ;	
	if(l(p)>=l&&r(p)<=r) {
		add(p)=(add(p)+d)%mod;
		sum(p)=(sum(p)+len(p)*d)%mod;
		return ;
	}

	int mid=(l(p)+r(p))>>1;
	spread(p,l(p),r(p));
	if(l<=mid) plu(p*2,l,r,d);
	if(r>mid) plu(p*2+1,l,r,d);

	sum(p)=(sum(p*2)+sum(p*2+1))%mod;
}

void mul(int p,int l,int r,ll d) {
	if(l(p)>r||r(p)<l) return; 
	if(l(p)>=l&&r(p)<=r) {
		times(p)=(times(p)*d)%mod;
		sum(p)=(sum(p)*d)%mod;
		add(p)=(add(p)*d)%mod;
		return ;
	}

	int mid=(l(p)+r(p))>>1;
	spread(p,l(p),r(p));
	if(l<=mid) mul(p*2,l,r,d);
	if(r>mid) mul(p*2+1,l,r,d);
	sum(p)=(sum(p*2)+sum(p*2+1))%mod;
}

ll ask(int p,int l,int r) {
	if(r<l(p)||l>r(p)) return 0;
	if(l(p)>=l&&r(p)<=r) return sum(p)%mod;
	spread(p,l(p),r(p));
	int mid=(l(p)+r(p))>>1;
	
	ll ans=0;

	if(l<=mid) ans=(ans+ask(p*2,l,r))%mod;
	if(r>mid) ans=(ans+ask(p*2+1,l,r))%mod; 

	return ans%mod;
}

int main() {
	//file("t");
	n=read(),mod=read();
	
	REP(i,1,n) a[i]=read();

	build(1,1,n);
    m=read();
	REP(i,1,m) {
		int op=read();
		if(op==1) {
			int x=read(),y=read(),k=read();
			mul(1,x,y,k);
		}
		if(op==2) {
			int x=read(),y=read(),k=read();
			plu(1,x,y,k);
		}
		if(op==3) {
			int x=read(),y=read();
			printf("%lld\n",ask(1,x,y));
		}
	}
	return 0;
}
