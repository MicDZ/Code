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

const int MAXN=200000+10;
const ll INF=0x3f3f3f3f3f;

struct SegmentTree {
	int l,r;
	ll dat;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define dat(x) tree[x].dat
}tree[MAXN<<2];

int a[MAXN];

void build(int p,int l,int r) {
	l(p)=l,r(p)=r;
	if(l==r) {
		dat(p)=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	dat(p)=max(dat(p*2),dat(p*2+1));
}

void change(int p,int x,ll d) {
	if(l(p)==r(p)) {
		dat(p)=d;
		return ;
	}
	int mid=(l(p)+r(p))>>1;
	if(x<=mid) change(p*2,x,d);
	else change(p*2+1,x,d);
	dat(p)=max(dat(p*2),dat(p*2+1));
}

ll ask(int p,int l,int r) {
	if(l<=l(p)&&r>=r(p)) return dat(p);
	int mid=(l(p)+r(p))>>1;
	ll ans=-INF;

	if(l<=mid) ans=max(ans,ask(p*2,l,r));
	if(r>mid) ans=max(ans,ask(p*2+1,l,r));
	return ans;
}

int main() {
	int n,m;
	while(~scanf("%d%d",&n,&m)) {

		memset(a,0,sizeof(a));
		memset(tree,0,sizeof(tree));

		REP(i,1,n) a[i]=read();
		build(1,1,n);
		REP(i,1,m) {
			char op[3];
			scanf("%s",op+1);
			int x=read(),y=read();

			if(op[1]=='Q') 
				printf("%lld\n",ask(1,x,y));
			else {
				change(1,x,-a[x]);
				a[x]=y;
				change(1,x,y);
			}
		}
	}
	return 0;
}
