#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

#define REP(i,e,s) for(register int i=(e); i<=(s); i++)
#define DREP(i,e,s) for(register int i=(e); i>=(s); i--)
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define ll long long

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=1000+10;

struct edge {
	int l,r,v1,v2,c;
} a[MAXN];

bool operator <(edge a,edge b) {
	if(a.r==b.r) return a.l<b.l;
	return a.r<b.r;
}

int calc(int l,int r) {
	return (r-l+2)*(r-l+2)/4;
}

int f[MAXN];

int main() {
	int n=read();
	REP(i,1,n) {
		int x=read(),y=read(),w=read();
		a[i]=(edge){x+y+1,x-y-1,w,0,calc(x+y+1,x-y-1)};
	}
	REP(i,1,n) REP(j,1,n) if(a[j].l>=a[i].l&&a[j].r<=a[i].r) a[i].v2+=a[j].v1;
	sort(a+1,a+1+n);
	
	REP(i,1,n) {
		f[i]=a[i].v2-a[i].c;
		int r=1,sum=0;
		REP(j,1,i-1) {
			if(a[i].l<=a[j].r&&a[j].l<a[i].l) {
				while(r<=i&&a[r].r<=a[j].r) {
					if(a[r].l>=a[i].l) sum+=a[r].v1;
					r++;
				}
				f[i]=max(f[i],f[j]+a[i].v2-a[i].c+calc(a[i].l,a[j].r)-sum);
			}
			if(a[j].r<a[i].l) f[i]=max(f[i],f[j]+a[i].v2-a[i].c);
		}
	}

	int ans=0;
	REP(i,0,n) ans=max(ans,f[i]);

	printf("%d\n",ans);
	return 0;
}

