#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;
#define int ll
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

priority_queue<pair<int,int> > q;

signed main() {
	int n=read(),k=read();
	REP(i,1,n) q.push(make_pair(-read(),-1));
	if((n-1)%(k-1)!=0)
		REP(i,1,k-1-((n-1)%(k-1))) q.push(make_pair(0,-1));
	int ans=0;
	while(q.size()>1) {
		int maxh=0,sum=0;
		REP(i,1,k) {
			ans+=-q.top().first;
			sum+=-q.top().first;
			maxh=max(maxh,-q.top().second);
			q.pop();
		}
		q.push(make_pair(-sum,-maxh-1));
	}
	printf("%lld\n%lld\n",ans,-q.top().second-1);
	return 0; 
}
