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

#define int ll 
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=10000+10,MAXM=1000000+10;

double a[MAXN];

bool cmp(double a,double b) {return a>b;}

signed main() {
	int n=read(),m=read();
	REP(i,1,n) a[i]=read();
	REP(i,1,m) {
		int u=read(),v=read(),w=read();
		a[u]+=w/2.;
		a[v]+=w/2.;
	}
	sort(a+1,a+1+n,cmp);

	double ans=0;
	for(int i=1; i<=n; i+=2) ans+=a[i]-a[i+1];
	
	printf("%.lf\n",ans);
	return 0;
}

