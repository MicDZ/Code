#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
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

const int MAXN=50000+10;

int c[MAXN],f[MAXN],q[MAXN],a[MAXN],b[MAXN];

double calc(int i,int j) {
	int yi=f[i]+b[i]*b[i],yj=f[j]+b[j]*b[j];
	return 1.0*(yi-yj)/(b[i]-b[j]);
}

signed main() {
	int n=read(),L=read()+1,l=1,r=1;
	REP(i,1,n) c[i]=read()+c[i-1];
	REP(i,0,n) a[i]=c[i]+i;
	REP(i,0,n) b[i]=a[i]+L;

	REP(i,1,n) {
		while(l<r&&calc(q[l],q[l+1])<2*a[i]) l++;
		f[i]=f[q[l]]+(a[i]-b[q[l]])*(a[i]-b[q[l]]);
		while(l<r&&calc(i,q[r-1])<calc(q[r-1],q[r])) r--;
		q[++r]=i;
	}

	printf("%lld\n",f[n]);
	return 0;
}
