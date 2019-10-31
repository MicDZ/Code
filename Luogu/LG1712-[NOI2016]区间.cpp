#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
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

const int MAXN=1000000+10,INF=0x3f3f3f3f;

int q[MAXN];

struct edge {
	int l,r,len;
} a[MAXN];

bool cmp(edge a,edge b) {
	return a.len<b.len;
}

struct SegmentTree {
	int l,r,maxx,add;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define maxx(x) tree[x].maxx
	#define add(x) tree[x].add
} tree[MAXN<<2];

void build(int p,int l,int r) {
	l(p)=l,r(p)=r;
	if(l==r) {maxx(p)=0; return ;}
	int mid=(l+r)>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
}

void spread(int p) {
	if(add(p)) {
		add(p*2)+=add(p);
		add(p*2+1)+=add(p);
		maxx(p*2)=maxx(p*2)+add(p);
		maxx(p*2+1)=maxx(p*2+1)+add(p);
		add(p)=0;
	}
}

void change(int p,int l,int r,int d) {
	if(l(p)>=l&&r(p)<=r) {
		add(p)+=d;
		maxx(p)=maxx(p)+d;
		return ;
	}
	
	spread(p);
	
	int mid=(l(p)+r(p))>>1;
	if(l<=mid) change(p*2,l,r,d);
	if(r>mid) change(p*2+1,l,r,d);
	maxx(p)=max(maxx(p*2),maxx(p*2+1));
}


signed main() {
file("data");
	int n=read(),m=read(),cnt=0;
	REP(i,1,n) a[i].l=read(),a[i].r=read(),a[i].len=a[i].r-a[i].l,q[++cnt]=a[i].l,q[++cnt]=a[i].r;
	
	sort(q+1,q+1+cnt);
	
	int num=unique(q+1,q+1+cnt)-q-1;
	
	sort(a+1,a+1+n,cmp);
	int st=INF,ed=0;	
	REP(i,1,n) {
		a[i].l=lower_bound(q+1,q+1+num,a[i].l)-q;
		a[i].r=lower_bound(q+1,q+1+num,a[i].r)-q;
		
	}
	
	build(1,1,num);
	
	int l=0,r=0,ans=INF;

	while(r<n) {
		while(maxx(1)<m&&r<=n) {
			r++;
			change(1,a[r].l,a[r].r,1);
		}
		if(maxx(1)<m) break;
		while(maxx(1)>=m&&r>=l) {
			l++;
			change(1,a[l].l,a[l].r,-1);
			ans=min(ans,a[r].len-a[l].len);
		}
	}

	printf("%lld \n",ans==INF?-1:ans);

	return 0;
}
