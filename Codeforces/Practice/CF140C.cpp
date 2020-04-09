#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define ll long long
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
//#define int ll

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=100000+10;

struct edge {
	int a,b,c,tot;
} ans[MAXN];

int r[MAXN],cnt[MAXN],scn[MAXN];

priority_queue<pair<int,int> > q;
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	int n=read();
	REP(i,1,n) r[i]=read();
	
	sort(r+1,r+1+n);
	int last=-1,tot=0;
	REP(i,1,n) {
		if(r[i]==last) cnt[tot]++;
		else {
			last=r[i];
			tot++;
			cnt[tot]++;
			scn[tot]=last;
		}
	}

	REP(i,1,tot) q.push(make_pair(cnt[i],scn[i]));
	int cnt=0,cntt=0;
	while(q.size()>=3) {
		int a,b,c,x,y,z;
		a=q.top().first,x=q.top().second;q.pop();
		b=q.top().first,y=q.top().second;q.pop();
		c=q.top().first,z=q.top().second;q.pop();
		if(c<=0) break;
		a-=c,b-=c;
		q.push(make_pair(a,x));
		q.push(make_pair(b,y));
		cnt+=c;
		cntt++;
		ans[cntt].a=x;
		ans[cntt].b=y;
		ans[cntt].c=z;
		ans[cntt].tot=c;
	}
	
	printf("%d\n",cnt);
	REP(i,1,cnt) {
		REP(j,1,ans[i].tot) {
			int out[4]={0,ans[i].a,ans[i].b,ans[i].c};
			sort(out+1,out+1+3,cmp);
			printf("%d %d %d\n",out[1],out[2],out[3]);
		}
	}
	return 0;
}