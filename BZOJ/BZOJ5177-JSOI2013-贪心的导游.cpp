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

const int MAXN=1000010,MAXM=MAXN*30;

int n,m,rt[MAXN],a[MAXN],b[MAXN];
int cnt,ls[MAXM],rs[MAXM],sum[MAXM];
void build(int &p,int l,int r) {
	p=++cnt;
	if(l==r) return ;
	int mid=(l+r)>>1;
	build(ls[p],l,mid);
	build(rs[p],mid+1,r);
}
void change(int &p,int u,int l,int r,int x) {
	p=++cnt,ls[p]=ls[u],rs[p]=rs[u],sum[p]=sum[u]+1;	
	if(l==r) return ;
	int mid=(l+r)>>1;
	if(x<=mid) change(ls[p],ls[u],l,mid,x);
	else change(rs[p],rs[u],mid+1,r,x);
}
int ask(int p,int u,int L,int R,int l,int r) {
	if(sum[p]==sum[u]) return 0;
	if(l==r) return l;
	int mid=(l+r)>>1;
	if(L>mid) return ask(rs[p],rs[u],L,R,mid + 1,r);
	if(R<=mid) return ask(ls[p],ls[u],L,R,l,mid);
	int ans=ask(rs[p],rs[u],L,R,mid + 1,r);
	if(!ans) ans=ask(ls[p],ls[u],L,R,l,mid);
	return ans; 
}	

int main() {
	n=read(),m=read();
	REP(i,1,n) a[i]=read();
	build(rt[0],0,1000);
	REP(i,1,n) change(rt[i],rt[i-1],0,1000,a[i]);

	while(m--) {
		int l=read()+1,r=read()+1,p=read();
		int ans=0;
		for(int i=0; i<=1000; i+=p) ans=max(ans,ask(rt[r],rt[l-1],i,min(i+p-1,1000),0,1000)%p);
		printf("%d\n",ans);
	}	
	return 0;
}


