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

int n,k;

struct edge {
	int a,b,c,w,f;
} a[MAXN],t[MAXN];

bool operator <(edge x,edge y) {
	if(x.a!=y.a) return x.a<y.a;
	if(x.b!=y.b) return x.b<y.b;
	return x.c<y.c;
}

bool operator ==(edge x,edge y) {
	return (x.a==y.a&&x.b==y.b&&x.c==y.c);
}


int c[MAXN];

void update(int x,int d) {
	while(x<=k) {
		c[x]+=d;
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

int tot;

void CDQ(int l,int r) {
	int mid=(l+r)>>1;
	if(l==r) return ;
	CDQ(l,mid);CDQ(mid+1,r);
	int p=l,q=mid+1,tot=l;
	while(p<=mid&&q<=r) {
		if(a[p].b<=a[q].b) update(a[p].c,a[p].w),t[tot++]=a[p++];
		else a[q].f+=ask(a[q].c),t[tot++]=a[q++];
	}
	while(p<=mid) update(a[p].c,a[p].w),t[tot++]=a[p++];
	while(q<=r) a[q].f+=ask(a[q].c),t[tot++]=a[q++];
	REP(i,l,mid) update(a[i].c,-a[i].w);
	REP(i,l,r) a[i]=t[i];
}

int ans[MAXN];

int main() {
	file("三维偏序-CDQ");
	n=read(),k=read();
	REP(i,1,n) a[i]=(edge){read(),read(),read(),1};
	sort(a+1,a+1+n);
	int cnt=1;
	REP(i,2,n) {
		if(a[i]==a[cnt]) a[cnt].w++;
		else a[++cnt]=a[i];
	}

	CDQ(1,cnt);
	REP(i,1,cnt) ans[a[i].f+a[i].w-1]+=a[i].w;
	REP(i,0,n-1) printf("%d\n",ans[i]);
	return 0;
}

