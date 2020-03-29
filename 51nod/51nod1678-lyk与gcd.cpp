#include<iostream>
#include<cstdio>
#include<cstring>
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a)	freopen(a".in","r",stdin);freopen(a".out","w",stdout)
using namespace std;
#define ll long long

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=1e5+10;

int mu[MAXN],sum[MAXN],cnt[MAXN],a[MAXN],fla[MAXN],n,q;

void init() {
	fla[0]=fla[1]=1;
	REP(i,2,n) if(!fla[i]) {
		cnt[i]=1;
		for(int j=2; i*j<=n; j++) {
			fla[i*j]=1,cnt[i*j]++;
			if(j%i==0) mu[i*j]=1;
		}
	}
}

void add(int i,int x) {
	for(int j=1; j*j<=i; j++) if(i%j==0) {
		sum[j]+=x-a[i];
		if(j*j!=i) sum[i/j]+=x-a[i];
	}
	a[i]=x;
} 

int ask(int i) {
	ll res=0;
	for(int j=1; j*j<=i; j++) if(i%j==0) {
		if(j>1&&!mu[j]) {
			if(cnt[j]&1) res+=sum[j];
			else res-=sum[j];
		}
		if(j*j!=i&&!mu[i/j]) {
			if(cnt[i/j]&1) res+=sum[i/j];
			else res-=sum[i/j];
		}
	}
	return sum[1]-res;
}

int main() {
	n=read(),q=read();
	init();
	REP(i,1,n) add(i,read());
	while(q--) {
		int op=read();
		if(op==1) {
			int p=read(),v=read();
			add(p,v);
		}
		else printf("%d\n",ask(read()));
	}
	return 0;
}

