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

struct SegmentTree {
	int l,r;
	ll sum,add;
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define sum(x) tree[x].sum
	#define add(x) tree[x].add
}tree[MAXN<<2];

void build(int p,int l,int r) {
	if(l==r) {sum(p)=a[l]; return ;}
	int mid=(l+r)>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	sum(p)=sum(p*2)+sum(p*2+1);
}

void spread(int p) {
	if(add(p)) {
		sum(p*2)+=add(p)*(r(p*2)-l(p*2)+1);
		sum(p*2+1)+=add(p)*(r(p*2+1)-l(p*2+1)+1);
		add(p*2)+=add(p);
		add(p*2+1)+=add(p);
		add(p)=0;
	}
}

void change(int p,int l,int r,int d) {
	if(l<=l(p)&&r>=r(p)) {
		sum(p)+=d*(r(p)-l(p)+1);
		add(p)+=d;
		return ;
	}
	spread(p);
	int mid=()
}

int main() {

	return 0;
}
