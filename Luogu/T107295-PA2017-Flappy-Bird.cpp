#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define ll long long
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=5e5+10,INF=0x3f3f3f;

int x[MAXN],low[MAXN],up[MAXN];

int main() {
	file("data");
	int n=read(),X=read();
	REP(i,1,n) x[i]=read(),low[i]=read(),up[i]=read();
	
	int a=0,b=0;

	REP(i,1,n) {
		a=min(a+(x[i]-x[i-1]),up[i]-1);
		b=max(b-(x[i]-x[i-1]),low[i]+1);
		if((a&1)!=(x[i]&1)) a--;
		if((b&1)!=(x[i]&1)) b++;

		if(a<b) {
			puts("NIE");
			return 0;
		}
	}
	
	printf("%d\n",(x[n]+b+1)/2-1);
	return 0;
}
