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
#define lowbit(x) (x&-x)

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=100000+10;

struct query {
	int x,v,w,id;
} q[MAXN<<1];

int n,m,a[MAXN],p[MAXN];ll ans[MAXN];

bool operator <(query a,query b) {
	return a.x<b.x;
}

struct bitree {
	
	int c[MAXN];
	void add(int x,int v) {
		while(x<=n) {
			c[x]+=v;
			x+=lowbit(x);
		}
	}
	int ask(int x) {
		int ans=0;
		while(x) {
			ans+=c[x];
			x-=lowbit(x);
		}
		return ans;
	}
} s;
void CDQ(int l,int r) {
	if(l==r) return ;
	int mid=(l+r)>>1;
	CDQ(l,mid),CDQ(mid+1,r);
	sort(q+l,q+mid+1),sort(q+mid+1,q+r+1);
	int i=l;
	REP(j,mid+1,r) {
		while(i<=mid&&q[i].x<=q[j].x) s.add(q[i].v,q[i].w),i++;
		ans[q[j].id]+=q[j].w*(s.ask(n)-s.ask(q[j].v));
	}
	REP(j,l,i-1) s.add(q[j].v,-q[j].w);
	i=mid;
	DREP(j,r,mid+1) {
		while(i>=l&&q[i].x>=q[j].x) s.add(q[i].v,q[i].w),i--;
		ans[q[j].id]+=q[j].w*s.ask(q[j].v-1);
	}
	DREP(j,mid,i+1) s.add(q[j].v,-q[j].w);
}

int main() {
	file("LG3157-动态逆序对");
	n=read(),m=read();
	REP(i,1,n) {
		a[i]=read(),p[a[i]]=i;
		q[i]=(query){i,a[i],1};
	}
	REP(i,1,m) {
		int x=read();
		q[i+n]=(query){p[x],x,-1,i};
	}
	CDQ(1,n+m);
	REP(i,1,m) ans[i]=ans[i-1]+ans[i];
	REP(i,0,m-1) printf("%lld\n",ans[i]);
}

