#include<bits/stdc++.h>
using namespace std;
#define MAXN 2000+10
#define INF 0x3f3f3f
#define file(a) freopen(a".in","r",stdin),freopen(a".out","w",stdout)
#define MOD 1234567

long long read() {
    long long x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

long long qpow(long long a,long long b) {
	long long ans=1;
    a%=MOD;
    while(b) {
        if(b%2==1) ans=ans*a%MOD;
        b/=2;
        a=a*a%MOD;
    }
    return ans;
}

int main() {
	long long n=read();
	cout<<qpow(2,n-1)%MOD;
	return 0;
}
