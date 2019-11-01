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
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=100000+10;

struct card {
	int x,y;
} a[MAXN];

int have[MAXN],mark1[MAXN],mark2[MAXN];

priority_queue<int> exsit[MAXN];

int main() {
	int n=read(),k=read();
	REP(i,1,k) {
		a[i].x=read();
		a[i].y=read();
		if(a[i].x>a[i].y) swap(a[i].x,a[i].y);
	}
	
	REP(i,1,k) exsit[a[i].x].push(i),exsit[a[i].y].push(-i);

	int q=read();
	while(q--) {
		int l=read(),r=read();
		bool flag=0;
		REP(i,l,r) {
			if(exsit[i].size()==1) {
				have[abs(exsit[i].top())]=1;
			}
			if(exsit[i].empty()) {
				flag=1;
				break;
			}
		}
		if(flag) puts("No");
		else puts("Yes");
	}
	return 0;
}
