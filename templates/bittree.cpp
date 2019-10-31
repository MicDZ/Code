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
#define lowbit(x) x&(-x)

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int INF=0x3f3f3f,MAXN=100000+10;

int n,m,c[MAXN];

void add(int p,int x) {
	while(p<=n) {
		c[p]+=x;
		p+=lowbit(p);
	}
}

int ask(int p) {
	int ans=0;
	while(p) {
		ans+=c[p];
		p-=lowbit(p);
	}
	return ans;
}

int main() {
	n=read(),m=read();
	REP(i,1,n) add(i,read());
	
	REP(i,1,m) printf("%d\n",ask(read()));
	return 0;
}

