#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define DE(...) fprintf(stderr,__VA_ARGS__);
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define ll long long

ll read() {
	ll x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const ll INF=0x3f3f3f,MAXN=400000+10;

ll a[MAXN];

ll gcd(ll a,ll b){
    ll t;
    while(b) {
        t=a;
        a=b;
        b=t%b;
        }
    return a;
}

ll count(ll n){
    ll s=1;
    for(ll i=2; i*i<=n; i++) {
        if(n%i==0){
            ll a=0;
            while(n%i==0) {
                n/=i;
                a++;
            }
            s=s*(a+1);
        }
    }
    if(n>1) s=s*2;
    return s;
}

int main() {
	ll n=read();
    REP(i,1,n) a[i]=read();
    ll ans=gcd(a[1],a[2]);
    REP(i,3,n) ans=gcd(ans,a[i]);

    printf("%lld\n",count(ans));
    return 0;
}

