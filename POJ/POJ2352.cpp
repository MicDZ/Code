#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define lowbit(x) (x&(-x))
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int MAXN=32000+10;
int c[MAXN],maxx;

int ask(int x) {
	int ans=0;
	while(x) {
		ans+=c[x];
		x-=lowbit(x);
	}
	return ans;
}

void update(int x) {
	while(x<=MAXN) {
		c[x]+=1;
		x+=lowbit(x);
	}
}

int ans[MAXN];

int main() {
	int n;
	while(~scanf("%d",&n)) {
		REP(i,1,n) {
			int x=read(),y=read();
			int t=ask(x+1);
			ans[t]++;
			update(x+1);
		}
		REP(i,0,n-1) printf("%d\n",ans[i]);
	}

	return 0;
}
