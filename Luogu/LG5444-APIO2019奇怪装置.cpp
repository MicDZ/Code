#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;
#define int ll
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

int gcd(int a,int b) {return b?gcd(b,a%b):a;}

struct edge {
	int l,r;
} a[MAXN],b[MAXN];

bool cmp(edge a,edge b) {
	return a.l<b.l;
}

signed main() {
	int n=read(),A=read(),B=read(),cnt=n;
	REP(i,1,n) a[i].l=read(),a[i].r=read();
	int k=A/gcd(A,B+1)*B;
	REP(i,1,cnt) {
		if(a[i].r-a[i].l+1>=k) {
			printf("%lld\n",k);
			return 0;
		}	
		else {
			a[i].l%=k;
			a[i].r%=k;
			if(a[i].l>a[i].r) {
				a[++n].l=0,a[n].r=a[i].r;
				a[i].r=k-1;;
			}
		}
	}
	DE("%lld\n",k);
	REP(i,1,n) DE("%d %d\n",a[i].l,a[i].r);

	sort(a+1,a+1+n,cmp);
	int lf=a[1].l,rg=a[1].r,ans=0;
	a[++n].l=k+1,a[n].r=0;
	REP(i,2,n) {
		if(rg<a[i].l) {
			ans+=rg-lf+1;
			lf=a[i].l;
			rg=a[i].r;
		}
		else rg=max(rg,a[i].r);
	}

	printf("%lld\n",ans);
	return 0;
}
