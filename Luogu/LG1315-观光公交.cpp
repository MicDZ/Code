#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define int ll
using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define ll long long
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %dist\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=100000+10;

int dist[MAXN];

struct tour {
	int t,a,b;
} a[100000+10];

int arr[MAXN],last[MAXN],_left[MAXN];
int num[1000+10];
signed main() {
	int n=read(),m=read(),k=read();
	REP(i,1,n-1) dist[i]=read();
	REP(i,1,m) a[i]=(tour){read(),read(),read()},last[a[i].a]=max(last[a[i].a],a[i].t),_left[a[i].b]++;
	while(k--) {
		REP(i,1,n) arr[i]=max(arr[i-1],last[i-1])+dist[i-1];
		int x=0,maxx=0,p;
		DREP(i,n,2) {
			int x=0;

			if(dist[i-1]) {
				REP(j,i,n) {
					x+=_left[j];
					if(arr[j]<=last[j]) break;
				}
			}
			if(x>maxx) maxx=x,p=i-1;
		}
		
		//REP(i,1,n-1) if(num[i]>num[p]) p=i;
		dist[p]--;
	}

	int ans=0;
	REP(i,1,n) arr[i]=max(arr[i-1],last[i-1])+dist[i-1];
	//REP(i,1,n) ans+=_left[i]*arr[i];
		REP(i,1,m) ans-=a[i].t;
	REP(i,1,n) ans+=_left[i]*arr[i];
	printf("%lld\n",ans);
	return 0;
}
