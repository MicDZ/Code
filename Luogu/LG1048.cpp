#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define DE(...) fprintf(stderr,__VA_ARGS__);
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define ll long long

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int INF=0x3f3f3f,MAXN=1000+10;

int w[MAXN],v[MAXN],dp[MAXN];

int main() {
	int k=read(),n=read();
	REP(i,1,n) w[i]=read(),v[i]=read();
	REP(i,1,n) DREP(j,k,w[i]) dp[j]=max(dp[j-w[i]]+v[i],dp[j]);
	REP(i,1,k) DEBUG(dp[i]);
	printf("%d\n",dp[k]);
	return 0;
}

