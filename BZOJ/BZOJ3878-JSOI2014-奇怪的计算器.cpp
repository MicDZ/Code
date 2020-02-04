#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

#define REP(i,e,s) for(register int i=(e); i<=(s); i++)
#define DREP(i,e,s) for(register int i=(e); i>=(s); i--)
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define ll long long
#define int ll
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=1e5+10;

char op[MAXN];
int a[MAXN],L,R; 

pair<int,int> x[MAXN];
struct SegmentTree {
	ll minn,maxx,tag1,tag2,tag3;
#define len(x) (rg[x]-lf[x]+1)
#define maxx(x) s[x].maxx
#define minn(x) s[x].minn
#define tag1(x) s[x].tag1
#define tag2(x) s[x].tag2
#define tag3(x) s[x].tag3
} s[MAXN<<2];

void f(int p,int l,int r,int tag1,int tag2,int tag3) {
	tag1(p)*=tag1;tag2(p)*=tag1;tag3(p)*=tag1;minn(p)*=tag1;maxx(p)*=tag1;
	tag2(p)+=tag2;tag3(p)+=tag3;
	minn(p)+=x[l].first*tag2+tag3;maxx(p)+=x[r].first*tag2+tag3;
	
}

void pushup(int p) {
	minn(p)=minn(p*2);
	maxx(p)=maxx(p*2+1);
}
void pushdown(int p,int l,int r,int mid) {
	f(p*2,l,mid,tag1(p),tag2(p),tag3(p));
	f(p*2+1,mid+1,r,tag1(p),tag2(p),tag3(p));
	tag1(p)=1,tag2(p)=tag3(p)=0;
}
void build(int p,int l,int r) {
	tag1(p)=1,tag2(p)=tag3(p)=0;
	if(l==r) { minn(p)=maxx(p)=x[l].first; return ;}
	int mid=(l+r)>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	pushup(p);
}
void chanminn(int p,int l,int r) {
	if(l==r) {f(p,l,r,0,0,L); return ;}
	int mid=(l+r)>>1;
	pushdown(p,l,r,mid);
	if(minn(p*2+1)<L) f(p*2,l,mid,0,0,L),chanminn(p*2+1,mid+1,r);
	else chanminn(p*2,l,mid);
	pushup(p);
}
void chanmaxx(int p,int l,int r) {
	if(l==r) {f(p,l,r,0,0,R); return ;}
	int mid=(l+r)>>1;
	pushdown(p,l,r,mid);
	if(maxx(p*2)>R) f(p*2+1,mid+1,r,0,0,R),chanmaxx(p*2,l,mid);
	else chanmaxx(p*2+1,mid+1,r);
	pushup(p);
}
int ans[MAXN];
void calc(int p,int l,int r) {
	if(l==r) {ans[x[l].second]=minn(p); return ;}
	int mid=(l+r)>>1;
	pushdown(p,l,r,mid);
	calc(p*2,l,mid);
	calc(p*2+1,mid+1,r);
}
signed main() {
	int n=read();
	L=read(),R=read();
	REP(i,1,n) {
		cin>>op[i];
		a[i]=read();
	}
	int m=read();
	REP(i,1,m) x[i].first=read(),x[i].second=i;
	sort(x+1,x+1+m);
	build(1,1,m);
	REP(i,1,n) {
		if(op[i]=='+') f(1,1,m,1,0,a[i]); 
		if(op[i]=='-') f(1,1,m,1,0,-a[i]);
		if(op[i]=='*') f(1,1,m,a[i],0,0);
		if(op[i]=='@') f(1,1,m,1,a[i],0);
		if(minn(1)<L) chanminn(1,1,m);
		if(maxx(1)>R) chanmaxx(1,1,m);
	}
	calc(1,1,m);
	REP(i,1,m) printf("%lld\n",ans[i]);
	return 0;
}

