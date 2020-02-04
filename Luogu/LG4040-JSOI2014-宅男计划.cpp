#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<stack>
#define int ll
using namespace std;

#define REP(i,e,s) for(register int i=(e); i<=(s); i++)
#define DREP(i,e,s) for(register int i=(e); i>=(s); i--)
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define ll long long

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int m,f,n;

const int MAXN=200+10;

struct edge{
	int p,t;
} a[MAXN];

bool operator<(edge a,edge b) {
	return a.t<b.t;
}

int g(int c) {
	int r=m-c*f,sum=0,res=0;
	REP(i,1,n) {
		int t=min(a[i].t-sum,r/(a[i].p*c));
		sum+=t;res+=t*c;r-=t*a[i].p*c;
		if(sum<a[i].t) {
			res+=r/a[i].p;
			break;
		}
	}
	return res;
}

stack<edge> s;

signed main() {
	m=read(),f=read(),n=read();
	REP(i,1,n) a[i].p=read(),a[i].t=read()+1;
	sort(a+1,a+1+n);
	REP(i,1,n) {
		while(s.size()&&a[i].p<=s.top().p) s.pop();
		s.push(a[i]);
	}
	n=s.size();
	DREP(i,n,1) a[i]=s.top(),s.pop();
	int l=1,r=m/f;
	while(r>=l+5) {
		int a=(l+l+r)/3,b=(l+r+r)/3;
		if(g(a)<g(b)) l=a+1;
		else r=b-1;
	}
	int maxx=0;
	REP(i,l,r) maxx=max(maxx,g(i));

	printf("%lld\n",maxx);
	return 0;
}

