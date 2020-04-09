#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
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

const int MAXN=1000000+10;

struct stack {
	int a[MAXN],tp;
	int top() {return a[tp];}
	int size() {return tp;}
	void pop() {if(tp) tp--;}
	void push(int x) {a[++tp]=x;}
} s;

int p[MAXN],b[MAXN];

int main() {
	int n=read();
	REP(i,1,n) p[i]=read();
	int m=read();
	REP(i,1,m) {
		int x=read();
		b[x]=-1;
	}
	DREP(i,n,1) {
		if(b[i]==-1||p[i]!=s.top()) s.push(p[i]),b[i]=-1;
		else s.pop(),b[i]=1;
	}

	if(s.size()) puts("NO"); 
	else {
		puts("YES");
		REP(i,1,n) printf("%d ",p[i]*b[i]);
	}
	return 0;
}
