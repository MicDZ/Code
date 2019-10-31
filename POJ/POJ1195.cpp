//////////////////////////////////////////////
// Author: MicDZ 
// Email: micdzcn@gmail.com 
// Last modified: 2019-08-01 08:47
// Filename: POJ1195.cpp
//////////////////////////////////////////////
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define lowbit(x) (x&(-x))
#define ll long long
ll read() {
	ll x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const ll MAXN=1024+10;

ll n,c[MAXN][MAXN],a[MAXN][MAXN];

ll ask(ll x,ll y) {
	ll ans=0;
	for(ll i=x; i; i-=lowbit(i))
		for(ll j=y; j; j-=lowbit(j)) 
			ans+=c[i][j];
	return ans;
}

void change(ll x,ll y,ll v) {
	if(a[x][y]+a<0) v=-a[x][y];
	a[x][y]+=v;
	for(ll i=x; i<=n; i+=lowbit(i)) 
		for(ll j=y; j<=n; j+=lowbit(j)) 
			c[i][j]+=v;
}

int main() {
	ll x=read();
	while(1) {
		if(x==0) {
			n=read();
			memset(c,0,sizeof(c));
			memset(a,0,sizeof(a));
		}
		else if(x==1) {
			ll x=read()+1,y=read()+1,a=read();
			change(x,y,a);
		}
		else if(x==2) {
			ll x1=read()+1,y1=read()+1,x2=read()+1,y2=read()+1;
			printf("%lld\n",ask(x2,y2)-ask(x2,y1-1)-ask(x1-1,y2)+ask(x1-1,y1-1));
		}
		else if(x==3) break;
		x=read();
	}
	return 0;
}
