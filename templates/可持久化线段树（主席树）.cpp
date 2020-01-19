#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

#define REP(i,e,s) for(register int i=(e); i<=(s); i++)
#define DREP(i,e,s) for(register int i=(e); i>=(s); i--)
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

const int MAXN=200000+10,MAXM=MAXN*18;;

int rt[MAXM],a[MAXN],b[MAXN];

struct President_Tree {
	int cnt,ls[MAXM],rs[MAXM],sum[MAXM];
	President_Tree() {
		cnt=0;
	}
	void build(int &p,int l,int r) {
		p=++cnt;
		if(l==r) return ;
		int mid=(l+r)>>1;
		build(ls[p],l,mid);
		build(rs[p],mid+1,r);
	}
	void change(int &p,int l,int r,int u,int x) {
		p=++cnt,ls[p]=ls[u],rs[p]=rs[u],sum[p]=sum[u]+1;	
		if(l==r) return ;
		int mid=(l+r)>>1;
		if(x<=mid) change(ls[p],l,mid,ls[u],x);
		else change(rs[p],mid+1,r,rs[u],x);
	}
	int ask(int x,int y,int l,int r,int k) {
		if(l==r) return l;
		int mid=(l+r)>>1;
		int v=sum[ls[y]]-sum[ls[x]];
		if(v>=k) return ask(ls[x],ls[y],l,mid,k);
		else return ask(rs[x],rs[y],mid+1,r,k-v);
	}
} s;


int main() {
	int n=read(),m=read();
	REP(i,1,n) a[i]=b[i]=read();
	sort(b+1,b+1+n);
	int sz=unique(b+1,b+1+n)-b-1;
	s.build(rt[0],1,sz);
	REP(i,1,n) s.change(rt[i],1,sz,rt[i-1],lower_bound(b+1,b+sz+1,a[i])-b);

	while(m--) {
		int l=read(),r=read(),k=read();
		printf("%d\n",b[s.ask(rt[l-1],rt[r],1,sz,k)]);
	}
	return 0;
}

