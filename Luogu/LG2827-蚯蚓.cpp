#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
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
const int MAXN=4e6+10;

int a[MAXN],ans[MAXN];

struct edge {
	int first,second;
};

edge _make_pair(int a,int b) {
	return (edge){a,b};
}

queue<edge> x,y,z;

bool cmp(int x,int y) {
	return x>y;
}

int main() {
	file("data");
	int n=read(),m=read(),q=read(),u=read(),v=read(),t=read();
	double p=1.0*u/v;
	REP(i,1,n) a[i]=read();
	sort(a+1,a+1+n,cmp);
	REP(i,1,n) x.push(_make_pair(a[i],0));
	REP(i,1,m) {
		int now=0,time;;
		if(x.size()&&now<x.front().first+(i-1)*q) now=x.front().first+(i-1)*q;
		if(y.size()&&now<y.front().first+(i-1-y.front().second)*q) now=y.front().first+(i-1-y.front().second)*q;
		if(z.size()&&now<z.front().first+(i-1-z.front().second)*q) now=z.front().first+(i-1-z.front().second)*q;

		if(x.size()&&now==x.front().first+(i-1)*q) x.pop();
		else if(y.size()&&now==y.front().first+(i-1-y.front().second)*q) y.pop();
		else if(z.size()&&now==z.front().first+(i-1-z.front().second)*q) z.pop();
		
		if(i%t==0) printf("%d ",now);
		
		y.push(_make_pair(p*now,i));
		z.push(_make_pair(now-floor(p*now),i));
	}
	puts("");
	int cnt=0;
	while(x.size()) {
		ans[++cnt]=x.front().first+(m)*q;
		x.pop();
	}
	while(y.size()) {
		ans[++cnt]=y.front().first+(m-y.front().second)*q;
		y.pop();
	}
	while(z.size()) {
		ans[++cnt]=z.front().first+(m-z.front().second)*q;
		z.pop();
	}

	sort(ans+1,ans+1+cnt,cmp);

	REP(i,1,cnt) {
		if(i%t==0) printf("%d ",ans[i]);
	}

	return 0;
}
