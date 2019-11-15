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

const int MAXN=1e7+10;

int a[MAXN],n,A,B,C;

void geta() {
	scanf("%d%d%d%d%d",&n,&A,&B,&C,a+1);
	for (int i=2;i<=n;i++)
	a[i] = ((long long)a[i-1] * A + B) % 100000001;
	for (int i=1;i<=n;i++)
	a[i] = a[i] % C + 1;
}

int main() {
	geta();
	double ans;

	REP(i,2,n) ans+=min(a[i],a[i-1])*1./(a[i]*a[i-1]);
	ans+=min(a[1],a[n])*1./(a[1]*a[n]);
	printf("%.3lf\n",ans);
	return 0;
}

