//http://hzwer.com/7738.html
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define ll long long
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define lowbit(x) x&(-x)
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=100000+10;

int c[MAXN],x[MAXN],y[MAXN];

struct candy {
	int x,y,c,id;
} a[MAXN];

bool cmp1(candy a,candy b) {
	return a.x<b.x;
}

bool cmp2(candy a,candy b) {
	return a.y<b.y;
}

int syn[MAXN],id[MAXN];

int ans;

int n,k,w[MAXN],pre[MAXN],l[MAXN],r[MAXN];

void add(int x,int d) {
	while(x<=n) {
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

void solve() {
	w[0]=0,w[n+1]=n+1;
	memset(c,0,sizeof(c));
	memset(pre,0,sizeof(pre));
	sort(a+1,a+1+n,cmp1);
	REP(i,1,n) add(a[i].x,1);
	
	//DE("in");
	REP(i,1,n) {
		int x=a[i].id,y=pre[a[i].c];
		l[x]=y,r[x]=n+1;
		if(y) r[y]=x;
		ans=max(ask(w[x]-1)-ask(w[y]),ans);
		pre[a[i].c]=x;
	}
	REP(i,1,k) ans=max(ans,ask(n+1)-ask(w[pre[i]]));
	sort(a+1,a+1+n,cmp2);
	int j=1;
	REP(i,1,n) {
		int x=a[i].id;
		while(j<=n&&a[j].y==a[i].y) {
			add(a[j].x,-1);
			j++;
		}
		l[r[x]]=l[x],r[l[x]]=r[x];
		ans=max(ans,ask(w[r[x]]-1)-ask(w[l[x]]));
	}	
}

int main() {
	int t=read();
	while(t--) {
		n=read(),k=read();
		REP(i,1,n) a[i]=(candy){read(),read(),read(),i};
		REP(i,1,n) syn[i]=a[i].x;
		sort(syn+1,syn+1+n);
		int num=unique(syn+1,syn+1+n)-syn-1;
		REP(i,1,n) w[i]=a[i].x=lower_bound(syn+1,syn+1+num,a[i].x)-syn;
		
		ans=0;
		solve();
		REP(i,1,n) a[i].y=-a[i].y;
		solve();
		printf("%d\n",ans);
	}
	return 0;
}
