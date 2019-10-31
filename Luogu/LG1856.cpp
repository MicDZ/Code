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

const int INF=0x3f3f3f,MAXN=20000+10;

struct edge {
	int l,r,h,f;
} ver[MAXN],hor[MAXN];

struct SegmentTree {
	int l,r,dat,len; 
	#define l(x) tree[x].l
	#define r(x) tree[x].r
	#define dat(x) tree[x].dat
	#define len(x) tree[x].len
} tree[MAXN<<2];

void build(int p,int l,int r) {
	l(p)=l,r(p)=r;
	if(l==r) return ;

	int mid=(l+r)>>1;

	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
}

int change(int p,int l,int r,int x,int y,int d) {
	if(l>=x&&r<=y) {dat(p)+=d;/*DEBUG(dat(p));*/}
	else {
		int mid=(l+r)>>1;
		if(x<mid) change(p*2,l,mid,x,y,d);
		if(y>mid) change(p*2+1,mid,r,x,y,d);
	}

	if(dat(p)) len(p)=r-l;
	else if(r-l==1) len(p)=0;
	else len(p)=len(p*2)+len(p*2+1);

}

int cnt;

bool cmp(edge a,edge b) {
	if(a.h==b.h) return a.f>b.f;
	return a.h<b.h;
}

int main() {
	int n=read(),maxx=0;
	REP(i,1,n) {
		int x1=read()+10001,y1=read()+10001,x2=read()+10001,y2=read()+10001;
		
		maxx=max(maxx,max(x1,max(y1,max(x2,y2))));
		
		ver[++cnt]=(edge){y1,y2,x1,1};
		hor[cnt]=(edge){x1,x2,y1,1};
		ver[++cnt]=(edge){y1,y2,x2,-1};
		hor[cnt]=(edge){x1,x2,y2,-1};
	}
	
	build(1,1,maxx);
	//DE("in\n");
	sort(ver+1,ver+1+cnt,cmp);
	sort(hor+1,hor+1+cnt,cmp);
	int ans=0;
	//DEBUG(maxx);
	REP(i,1,cnt) {
		int s1=len(1),s2;
		change(1,1,maxx,ver[i].l,ver[i].r,ver[i].f);
		//DE("-------------\n");
		//DEBUG(s1);
		s2=len(1);
		//DEBUG(s2);
		ans+=abs(s1-s2);
	}
	

	REP(i,1,cnt) {
		int s1=len(1),s2;
		change(1,1,maxx,hor[i].l,hor[i].r,hor[i].f);
		//DE("-------------\n");
		//DEBUG(s1);
		s2=len(1);
		//DEBUG(s2);
		ans+=abs(s1-s2);
	}

	printf("%d\n",ans);
	
	return 0;
}
