#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;
#define int ll
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

const int MAXN=200000+10;

multiset<int> s;

struct edge {
	int in,b;
} a[MAXN];

bool operator <(edge a,edge b) {
	return a.b>b.b;
}

signed main() {
	freopen("data.in","r",stdin);
	int n=read();
	REP(i,1,n) {
		s.insert(read());
		a[i]=(edge){read(),read()};
	}
	sort(a+1,a+1+n);
	ll ans=0;
	REP(i,1,n) {
		ans+=1ll*a[i].b*a[i].in;
		multiset<int>::iterator it=s.lower_bound(a[i].in);
		if(it==s.begin()) continue;
		it--;
		ans-=1ll*(*it)*a[i].b;
		s.erase(it);
	}

	printf("%lld\n",ans);
	return 0;
}

