#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;
#define int ll
#define REP(i,e,s) for(register int i=(e); i<=(s); i++)
#define DREP(i,e,s) for(register int i=(e); i>=(s); i--)
#define ll long long
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define lowbit(x) x&(-x)
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=500000+10;

struct bitree {
	int c[MAXN],n;
	void change(int x,int d) {
		while(x<=n) {
			c[x]+=d;
			x+=lowbit(x);
		}
	}
	int ask(int x) {
		int ans=0;
		while(x) {
			ans+=c[x];
			x-=lowbit(x);
		}
		return ans;
	}
} s;

signed main() {
	int n=read(),m=read();s.n=n;
	REP(i,1,n) s.change(i,read());
	REP(i,1,m) {
		int op=read();
		if(op==1) {
			int x=read(),k=read();
			s.change(x,k);
		}
		if(op==2) {
			int x=read(),y=read();
			printf("%lld\n",s.ask(y)-s.ask(x-1));
		}
	}
	return 0;
}

