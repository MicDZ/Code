#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a)	freopen(a".in","r",stdin);freopen(a".out","w",stdout)
using namespace std;

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=50+10,INF=0x3f3f3f3f;

struct edge {
	int s,t;
} a[MAXN];

bool cmp1(edge a,edge b) {
	return a.s<b.s;
}

bool cmp2(edge a,edge b) {
	return a.t<b.t;
}

int n,l,ans;

void calc(int pos) {
	sort(a+1,a+pos+1,cmp2);
	sort(a+pos+1,a+n+1,cmp2);
	int leng=0;
	REP(i,1,pos) leng+=a[i].s+a[i].t;
	REP(i,pos+1,n) leng+=l-a[i].s+l-a[i].t;	
	int sum1=0,sum2=0;

	REP(i,pos+1,n) {
		sum1=0;
		REP(j,1,pos) if(a[j].t>=a[i].t) sum1+=2*(l-a[j].t);
		ans=min(ans,leng+sum1+sum2);
		sum2+=2*a[i].t;
	}
}

bool pd(int l,int r,int _l,int _r) {
	int n1=0,n2=INF;
	REP(i,l,r) n1=max(n1,a[i].t);
	REP(i,_l,_r) n2=min(n2,a[i].t);
	return n1<n2;
}

int main() {
	int t=read();
	while(t--) {
		ans=INF;
		n=read(),l=read();
		REP(i,1,n) a[i]=(edge){read(),read()};
		REP(i,0,n) { 
			sort(a+1,a+1+n,cmp1);
			calc(i);
		}
		sort(a+1,a+1+n,cmp1);
		int si=0;
		REP(i,0,n) {
			si+=a[i].t+a[i].s;
			if(pd(1,i,i+1,n)) {
				int j=i+1,tot=0;
				for(; j<=n; j++) if(!pd(i+1,j,j+1,n)) {break;}
	//			DE("%d\n",j);
				REP(k,i+1,j-1) tot+=abs(a[k].t-a[k].s);
				REP(k,j,n) tot+=l-a[k].s+l-a[k].t;
				ans=min(ans,si+tot);
			}
		}

		printf("%d\n",ans);
	}
	return 0;
}
