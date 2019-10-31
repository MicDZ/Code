#include<bits/stdc++.h>
using namespace std;
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define ll long long
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int main() {
	ll n=read(),m=read();
	if(n==0&&m==0) return 0;
	if(n>m) swap(n,m);
	printf("%lld\n",n*m*(n+m-2)+2*n*(n-1)*(2*n-1)/3+2*n*(n-1)*(m-n));
	main();
}
