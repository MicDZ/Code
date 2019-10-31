#include<bits/stdc++.h>
using namespace std;
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define ll long long
int read() {
    int x=0,f=1,ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

const int MAXN=500000+10;

struct edge {
	int _next,pre,id;
}a[MAXN];

int main() {
	freopen("1.out","w",stdout);
	int n=read(),m=read();
	REP(i,1,n) {
		a[i]._next=i+1;
		a[i].id=i;
		a[i].pre=i-1;
	}
	a[n]._next=1;
	a[1].pre=n;
	int now=n;
	REP(i,1,n) {
		REP(j,1,m) 
			now=a[now]._next;
		printf("%d ",a[now].id);
		a[a[now].pre]._next=a[a[now]._next].id;
		a[a[now]._next].pre=a[a[now].pre].id;
	}
}
