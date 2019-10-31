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
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int INF=0x3f3f3f3f,MAXN=100000+10;
int h;
struct airen {
	int a,b;
} a[MAXN];

bool cmp(airen a,airen b) {
	return a.a+a.b<b.a+b.b;
}
int dp[MAXN];
int main() {
	int n=read();
	REP(i,1,n) a[i].a=read(),a[i].b=read();
	h=read();
	sort(a+1,a+1+n,cmp);
	int sum=0,ans=0;

	REP(i,1,n) sum+=a[i].a;
	REP(i,1,n) dp[i]=-INF;
	
	dp[0]=sum;
	REP(i,1,n) DREP(j,i,1) if(a[i].b+dp[j-1]>=h) dp[j]=max(dp[j],dp[j-1]-a[i].a);
	DREP(i,n,0)	
		if(dp[i]>=0) {
			ans=i;
			break;
		}
	printf("%d\n",ans);
	return 0;
}
