#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
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

const int MAXN=1000000+10;

int gcd(int a,int b) {return b?gcd(b,a%b):a;}

struct edge {
	int l,r;
} a[MAXN];

int main() {
	int n=read(),A=read(),B=read();
	REP(i,1,n) a[i].l=read(),a[i].r=read();
	int k=A/gcd(A,B+1)*B;
	REP(i,1,n) {
	
	}
	printf("%d\n",k);
	return 0;
}
