#include<bits/stdc++.h>
using namespace std;
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define ll long long

ll read() {
	ll x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int main() {
	ll n=read(),m=read();
	if(m>n) swap(n,m);
	if(n==1) {printf("%lld\n",m*(m-1)); return 0;}
	if(n==2) {printf("%lld\n",2*m*(n+m-1)); return 0;}
	else {
		printf("%lld\n",/*3*m*n*n-4*m*n+m*m*n-2*(n*n*n-n)/3*/(m-2+n)*m*n+2*n*(n-1)*(3*m-n-1)/3);
		return 0;
	}
	return 0;
}
/*
100 223
10907100
*/
