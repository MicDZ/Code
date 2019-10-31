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

const int MAXN=100000+10;

int c[MAXN],n;

void add(int x,int v) {
	while(x<=n) {
		c[x]+=v;
		x+=lowbit(x);
	}
}

int ask(int x) {
	int ans=0;
	while(x) {
		ans+=c[x];
		x-=lowbit(x);
	}
	return ans;
}

int main() {
	n=read();
	REP(i,1,n) {int x=read();add(i,x);}
	int m=read();

	REP(i,1,m) {
		string a;
		cin>>a;
		if(a=="SUM") {int l=read(),r=read();printf("%d\n",ask(r)-ask(l-1));}
		if(a=="ADD") {int x=read(),v=read();add(x,v);}
	}
	return 0;
}
