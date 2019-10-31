#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define ll long long

ll read() {
	ll x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll x,y;

ll exgcd(ll a,ll b) {
	if(b==0) {x=1,y=0;return a;}
	ll g=exgcd(b,a%b);
	ll oldx=x,oldy=y;
	x=oldy;
	y=oldx-a/b*oldy; 
	return g;
}

int main() {
	ll x0=read(),y0=read(),m=read(),n=read(),l=read();
	ll a=n-m,b=l,c=x0-y0;
	if(a<0) a=-a,c=-c;
	//(m-n)t-lk=y-x
	ll g=exgcd(a,b);
	b=l/g;
	if(c%g) {puts("Impossible"); return 0;}
	printf("%lld\n",((x*(c/g))%b+b)%b); 
}
