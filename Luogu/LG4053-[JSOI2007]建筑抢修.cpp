#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<algorithm>

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

const int MAXN=200000+10;

struct building {
	int t1,t2;
} a[MAXN];

priority_queue<int> q;

bool cmp(building x,building y) {
	return x.t2<y.t2;
}

signed main() {
	//file("1");
	int n=read();
	REP(i,1,n) a[i].t1=read(),a[i].t2=read();
	
	sort(a+1,a+1+n,cmp);
	int time=0,ans=0;
	REP(i,1,n) {
		if(a[i].t1+time>a[i].t2) {
			if(a[i].t1<q.top()) {
                time-=q.top();
				q.pop();
                q.push(a[i].t1);
                time+=a[i].t1;
            }
		}
		else {
			time+=a[i].t1;
			ans++;
			q.push(a[i].t1);

		}
	}
//	DE("%lld\n",ans);
	printf("%lld\n",ans);
	return 0;
}
