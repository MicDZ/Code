#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<set>

using namespace std;
#define int ll
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

const int MAXN=32767+10;

multiset<int> s;

int a[MAXN];

signed main() {
	file("LG2234-HNOI2002-营业额统计");
	int n=read();
	REP(i,1,n) scanf("%lld",&a[i]);
	
	int ans=0;

	REP(i,1,n) {
		multiset<int>::iterator it;
		it=s.lower_bound(a[i]);
		int num=0;
		if(*it==a[i]) ;		
		else if(!s.empty()) {
			num=abs(a[i]-*it);
			if(it!=s.begin())
			it--;
			if(it!=s.end()) num=min(num,abs(a[i]-*it));
			s.insert(a[i]);
		}
		else num=a[i],s.insert(a[i]);
		ans+=num;
		
	}

	printf("%lld\n",ans);
	return 0;
}

