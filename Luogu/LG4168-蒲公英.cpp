#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;

#define REP(i,e,s) for(register int i=(e); i<=(s); i++)
#define DREP(i,e,s) for(register int i=(e); i>=(s); i--)
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

const int MAXN=40000+10;

int n,m,gap,a[MAXN],pos[MAXN];

int ask(int l,int r) {
	
}

int main() {
	n=read(),m=read(),gap=sqrt(n);
	REP(i,1,n) a[i]=read();
	REP(i,1,n) pos[i]=(i-1)/gap+1;
	int last=0;
	REP(i,1,m) {
		int l=(read()+last-1)%n+1,r=(read()+last-1)%n+1;
		if(l>r) swap(l,r);
		last=ask(l,r);
	}
	return 0;
}

