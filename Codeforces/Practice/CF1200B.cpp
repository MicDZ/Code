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

ll read() {
	ll x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const ll INF=0x3f3f3f,MAXN=100+5,MAXM=1000000+10;

ll h[MAXN];

int main() {
	ll t=read();
	while(t--) {
		ll sum=0,n=read(),m=read(),k=read();
		
		REP(i,1,n) h[i]=read();
		
		bool flag=0;
		if(n!=1)
		for(int i=1; i<=n-1&&!flag; i++) {
			int goal=h[i+1]-k;goal=max(goal,0);
			if(h[i]>goal) m+=h[i]-goal;
			else m-=(goal-h[i]);
			if(m<0) {
				puts("NO");
				flag=1;
			}
		}
		if(!flag) puts("YES");

	}
	return 0;
}

