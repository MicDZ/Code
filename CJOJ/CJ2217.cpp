#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,e,s) for(register int i=e; i<=s; i++)

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int MAXN=1000+10,MOD=12345;
ll ans[MAXN];

int main() {
	int n=read();
	ans[1]=1;ans[2]=3;
	REP(i,3,n) {
		ans[i]=(ans[i-2]*2%MOD+ans[i-1])%MOD;
	}

	printf("%lld\n",ans[n]%MOD);
	return 0;
}
