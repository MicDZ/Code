#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;
#define ll long long
#define REP(i,e,s) for(register ll i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define DE(...) fprintf(stderr,__VA_ARGS__);
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)

ll read() {
    ll x=0,f=1,ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

const ll INF=0x3f3f3f,MAXN=4200+10;

ll f[MAXN],a[2][MAXN];

int main() {
	ll n=read(),p=read();

	a[0][0]=a[1][0]=f[0]=1;

	REP(i,1,n) REP(j,1,i) {
		if(j&1) f[i]=(f[i]+f[j-1]%p*f[i-j]%p*a[i&1^1][j-1])%p;
		a[i&1][j]=(a[i&1^1][j]+a[i&1^1][j-1])%p;	
	}
	printf("%lld\n",2*f[n]%p);
	return 0;
}
