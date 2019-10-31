#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000+10
#define MOD 998244353
#define ll long long
ll read() {
    ll x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

ll ksm(ll a,ll b) {
	ll ans=1;
	a%=MOD;
	while(b) {
		if(b%2==1) ans=ans*a%MOD;
		b/=2;
		a=a*a%MOD;
	}
	return ans%MOD;
}

int main() {
	ll t=read();
	while(t--) {
		ll n=read();
		printf("%lld\n",(ksm(2,n)*2-ksm(2,(n+1)/2)+MOD)%MOD);
	}
    return 0;
}


