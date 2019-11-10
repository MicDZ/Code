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
const int MAXN=20000000+5+10;

int p[MAXN];
int seed,n,k,S;
int getrand() {
	seed=((seed*12321)^9999)%32768;
	return seed;
}
void generateData() {
	k=read(),seed=read(),S=read();
	int t=0;
	n=k*2 + 1;
	memset(p,0,sizeof(p));
	REP(i,1,n){
		p[i]=(getrand()/128)%2;
		t+=p[i];
	}
	int i = 1;
	while(t>k) {
		while(p[i]==0) ++i;
		p[i]=0;
		--t;
	}
	while(t<k) {
		while(p[i]==1) ++i;
		p[i]=1;
		++t;
	}
}

int a[MAXN],s[MAXN];

pair<int,int> b[MAXN];
int cnt;
int calc(int k) {
	nth_element(b+1,b+k,b+cnt+1);
	return b[k].second;
}

int main() {
	generateData();
	REP(i,1,n) if(p[i]) a[i]=1; else a[i]=-1;
	REP(i,1,n) s[i]=s[i-1]+a[i];
	REP(i,1,n) if(!p[i]) b[++cnt]=make_pair(s[i],i);
	printf("%d\n%d\n%d\n",calc(k+1),calc(k-S+1),calc(S+1));
	return 0;
}

