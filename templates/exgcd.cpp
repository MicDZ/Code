#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define REP(i,e,s) for(register int i=(e); i<=(s); i++)
#define DREP(i,e,s) for(register int i=(e); i>=(s); i--)
#define ll long long
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
ll read() {
	ll x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll x,y;

void exgcd(ll a,ll b,ll &x,ll &y) {
	if(b==0) {
		x=1,y=0;
		return ;
	}
	exgcd(b,a%b,y,x);
	y-=x*(a/b);
}

int main() {
	ll a=read(),b=read();

	exgcd(a, b, x, y);
	printf("%lld\n",(x+b)%b);
	return 0;
}

