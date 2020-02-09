#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;
#define int ll
#define REP(i,e,s) for(register int i=(e); i<=(s); i++)
#define DREP(i,e,s) for(register int i=(e); i>=(s); i--)
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define ll long long
#define log2(x) ((int)(log(x)/log(2)))
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=100000+10;

int a[MAXN],f[25][MAXN],lg[MAXN];

int gcd(int a,int b) {return b?gcd(b,a%b):a;}

int ask(int l,int r) {
	return gcd(f[lg[r-l+1]][l],f[lg[r-l+1]][r-(1<<lg[r-l+1])+1]);
}

signed main() {
	freopen("data.in","r",stdin);
	int n=read();
	REP(i,1,n) lg[i]=log2(i);
	REP(i,1,n) f[0][i]=read();
	REP(i,1,lg[n]) REP(j,1,n+1-(1<<i)) f[i][j]=gcd(f[i-1][j],f[i-1][j+(1<<(i-1))]);
	int ans=0;
	REP(i,1,n) for(int j=i,_next; j<=n; j=_next+1) {
		int l=j,r=n;
		while(l<=r) {
			int mid=(l+r)>>1;
			if(ask(i,mid)==ask(i,j)) _next=mid,l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,(_next-i+1)*ask(i,_next));
	}

	printf("%lld\n",ans);
	return 0;
}

