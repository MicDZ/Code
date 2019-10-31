#include<bits/stdc++.h>
using namespace std;
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define ll long long
int read() {
    int x=0,f=1,ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

const int MAXN=200000+10;

struct minister{
	ll a,b;
}m[MAXN];

bool cmp(minister x,minister y) {
	if(min(x.a,y.b)==min(x.b,y.a)) return x.a<y.a;
	else return min(x.a,y.b)<min(x.b,y.a);
}

long long ans[MAXN];

int main() {
	int t=read();
	while(t--) {
		int n=read();
		REP(i,1,n) m[i].a=read(),m[i].b=read();
		sort(m+1,m+1+n,cmp);
		ll s=0;
		REP(i,1,n) {
            s+=m[i].a;
            ans[i]=max(ans[i-1],s)+m[i].b;
        }
        printf("%lld\n",ans[n]);
	}
}

