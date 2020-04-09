#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define ll long long

ll read() {
	ll x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int MAXN=200000+10;

ll n,k,a[MAXN];

bool check(ll x) {
	int cnt=0;
	REP(i,(n+1)/2,n) {
		if(a[i]>=x) return 1;
		if(x-a[i]>k-cnt) return 0;
		cnt+=x-a[i];
	}
	return 1;
}

int main() {
	n=read(),k=read();
	REP(i,1,n) a[i]=read();
	sort(a+1,a+1+n);
	
	ll l=1,r=2000000000+1;
	while(l<r) {
		int mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid;
	}

	printf("%d\n",r-1);
	return 0;
}
