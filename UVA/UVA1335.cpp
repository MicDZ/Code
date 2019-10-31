#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<stack>
#include<algorithm>

using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define ll long long
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=100000+10;

int n,a[MAXN],maxx[MAXN],minn[MAXN];

bool check(int x) {
	REP(i,2,n) {
		maxx[i]=min(a[i],a[1]-minn[i-1]);
		minn[i]=max(0,a[1]+a[i]+a[i-1]-maxx[i-1]-x);
	}

	return !minn[n];
}

int main() {
	while(scanf("%d",&n)&&n) {
		int l=0,r;
		REP(i,1,n) a[i]=read(),l=max(l,a[i]+a[i-1]);
		if(n==1) {printf("%d\n",a[1]);continue;}
		maxx[1]=minn[1]=a[1];
		r=300000;
		while(l<r) {
			int mid=(l+r)>>1;
			if(check(mid)) r=mid;
			else l=mid+1;
		}

		printf("%d\n",r);
	}
	return 0;
}