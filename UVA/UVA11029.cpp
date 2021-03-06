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

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MOD=1000;

ll qpow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1)
            ans=ans*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return ans;
}

int main(){
    int t=read();
    while(t--){
		ll a=read(),b=read();
        ll ans2=qpow(a,b);

        double k=(double)b*log10(a);
        ll ans1=floor(pow(10.0,(k-(long long)k))*100.0);
        printf("%lld...%03lld\n",ans1,ans2);
    }
    return 0;
}