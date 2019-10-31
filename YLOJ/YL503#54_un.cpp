#include<bits/stdc++.h>
using namespace std;
#define MAXN (int)(2e5+10)
#define INF 0x3f3f3f3f
#define MOD (1000000000+7)
#define ll long long
ll read() {
	ll x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll a[MAXN],f[MAXN],inv[MAXN],size[MAXN],sum[MAXN],fac[MAXN],n,cnt;
ll qpow(ll a,ll b) {
    ll ans=1;
    while(b) {
        if(b&1) ans=ans*a%MOD;
        b>>=1;
        a=a*a%MOD;
    }
    return ans;
} 

void init() {
    f[1]=1;
    for(int i=2; i<=n; i++) 
        f[i]=f[i-1]*(i*(i-1)/2)%MOD;
    
    fac[0]=1;
    for(int i=1; i<=n; i++) 
        fac[i]=fac[i-1]*i%MOD;
    
    for(int i=1; i<=n; i++) {
        if(a[i] != a[i-1]) {
            cnt++;
            size[cnt]=1;
        }
        else size[cnt]++;
    }

    for(int i=1; i<=cnt; i++) 
        sum[i]=sum[i-1]+size[i];

    inv[n]=qpow(fac[n],MOD-2);

    for(int i=n; i>=1; i--) 
        inv[i-1]=inv[i]*i%MOD;
}

ll dp[MAXN];

void calc() {
    dp[1]=f[size[1]];
    for(int i=1; i<=cnt; i++) 
        for(int j=0; j<size[i]; j++) 
            dp[i]=(dp[i]+dp[i-1]*f[size[i]]%MOD*fac[sum[i-1]+j-1]%MOD*inv[j]%MOD*inv[sum[i-1]-1]%MOD*(size[i]-j)%MOD)%MOD;
}

void debug() {
for(int i=1; i<=n; i++) cout<<f[i]<<" ";
puts("");
}

int main() {
    n=read();
    for(int i=1; i<=n; i++) {
        a[i]=read();
    }
    sort(a+1,a+1+n);

    init(); 
    calc();
    //debug();
    
    cout<<dp[cnt]<<endl;
}