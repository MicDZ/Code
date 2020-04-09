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

const int MAXN=200000+10;

int a[MAXN],b[MAXN],fa[MAXN],pre[MAXN];

int main() {
	int n=read(),m=read(),q=read();
	REP(i,1,n) a[i]=read(),pre[a[i]]=a[i-1];
	pre[a[1]]=a[n];
	REP(i,1,m) {
		b[i]=read();
		fa[b[i]]=i;
		b[i]=fa[pre[b[i]]];
	}
	REP(i,1,m) fa[i]=i;

	for(int k=n-1; k; k>>=1) {
		if(k&1) DREP(j,m,1) fa[j]=b[fa[j]];
		DREP(j,m,1) b[j]=b[b[j]];
	}
	REP(i,1,m) fa[i]=max(fa[i],fa[i-1]);
	while(q--) printf("%d",read()<=fa[read()]);
	return 0;
}
