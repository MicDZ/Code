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

const int MAXN=100000+10;

struct luohan {
	int a,b;
} a[MAXN];

bool cmp(luohan a,luohan b) {
	return a.a+a.b<b.a+b.b;
}

signed main() {
	int n=read();
	REP(i,1,n) a[i]=(luohan){read(),read()};
	sort(a+1,a+1+n,cmp);

	int ans=0,sum=0;
	REP(i,1,n) 
		if(a[i].b>=sum) ans++, sum+=a[i].a;

	printf("%lld\n",ans);
	return 0;
}
