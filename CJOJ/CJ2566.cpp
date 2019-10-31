#include<bits/stdc++.h>
using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)

int read() {
    int x=0,f=1,ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

const int MAXN=100000+10,INF=(1<<30);

int d[MAXN],s,n,m,l,r;

bool check(int x) {
	int cnt=0,last=0;
	REP(i,1,n+1) {
		//if(mark) {mark=0;continue;}
		if(d[i]-last<x) {cnt++;}
		else last=d[i];
	}
	return cnt<=m;
}

int main() {
	s=read(),n=read(),m=read(),l=INF,r=-INF;
    REP(i,1,n) d[i]=read();
	sort(d+1,d+1+n);
	d[0]=0,d[n+1]=s;
	l=0,r=s;
	while(l<=r) {
		int mid=(l+r)/2;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	
	printf("%d\n",r);
	
	return 0;
}

