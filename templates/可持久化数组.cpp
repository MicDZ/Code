#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

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

const int MAXN=1000000+10;

int cnt,a[MAXN],rt[MAXN*20];

struct Presistable_SegmentTree {
	int lc,rc,val;
	#define lc(x) tree[x].lc
	#define rc(x) tree[x].rc
	#define val(x) tree[x].val
} tree[MAXN];

void build(int &p,int l,int r) {
	p=++cnt;
	if(l==r) {val(p)=a[l];return ;}
	int mid=(l+r)>>1;
	build(lc(p),l,mid);
	build(rc(p),mid+1,r);
}

void change(int &p,int pre,int l,int r,int x,int d) {
	p=++cnt;lc(p)=lc(pre);rc(p)=rc(pre);val(p)=val(pre);
	if(l==r) {val(p)=d;return ;}
	int mid=(l+r)>>1;
	if(x<=mid) change(lc(p),lc(pre),l,mid,x,d);
	else change(rc(p),rc(pre),mid+1,r,x,d);
}

int ask(int p,int l,int r,int x) {
	if(l==r) return val(p);
	int mid=(l+r)>>1;
	if(x<=mid) return ask(lc(p),l,mid,x);
	else return ask(rc(p),mid+1,r,x);
}

int main() {
	int n=read(),m=read();
	REP(i,1,n) a[i]=read();
	build(rt[0],1,n);
	REP(i,1,m) {
		int pre=read(),op=read(),x=read();
		if(op==1) {
			int v=read();
			change(rt[i],rt[pre],1,n,x,v);
		}
		else printf("%d\n",ask(rt[pre],1,n,x)),rt[i]=rt[pre];
	}
	return 0;
}
