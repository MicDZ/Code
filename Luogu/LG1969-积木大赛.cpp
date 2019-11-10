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

const int MAXN=100000+10;

int a[MAXN];

struct SegmentTree {
	int lf[MAXN<<2],rg[MAXN<<2],maxx[MAXN<<2],pos[MAXN<<2];
	#define l(x) lf[x]
	#define r(x) rg[x]
	#define len(x) (rg[x]-lf[x]+1)
	#define maxx(x) maxx[x]
	#define add(x) add[x]
	#define pos(x) pos[x]
	#define INF 0x3f3f3f3f
	void build(int p,int l,int r) {
		l(p)=l,r(p)=r;
		if(l==r) {maxx(p)=a[l]; pos[p]=l; return;}
		int mid=(l+r)>>1;
		build(p*2,l,mid);
		build(p*2+1,mid+1,r);
		int ans=INF;
		if(maxx(p*2)<ans) ans=maxx(p*2),pos[p]=pos[p*2];
		if(maxx(p*2+1)<ans) ans=maxx(p*2+1),pos[p]=pos[p*2+1];
		maxx(p)=ans;
	}
	pair<int,int> ask(int p,int l,int r) {
		if(l(p)>=l&&r(p)<=r) {return make_pair(maxx(p),pos(p));}
		int mid=(l(p)+r(p))>>1;
		int ans=INF,pos;
		pair<int,int> ansl,ansr;
		if(l<=mid) ansl=ask(p*2,l,r);
		if(r>mid) ansr=ask(p*2+1,l,r);
		if(l<=mid&&ansl.first<ans) ans=ansl.first,pos=ansl.second;
		if(r>mid&&ansr.first<ans) ans=ansr.first,pos=ansr.second;
		return make_pair(ans,pos);
	}
} s;

int ans;
void calc(int l,int r) {
	if(l<r) return ;
	pair<int,int> x=s.ask(1,l,r);
	if(x.first>=0) return;
	ans++;
	int pos=s.ask(1,l,r).second;
	calc(l,pos);
	calc(pos+1,r);
}

int main() {
	int n=read();
	REP(i,1,n) a[i]=-read();
	s.build(1,1,n);
	calc(1,n);	
	printf("%d\n",ans);
	return 0;
}

