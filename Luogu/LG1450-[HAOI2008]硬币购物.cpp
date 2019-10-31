#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define int ll
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define ll long long
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define calc(a) c[a]*(d[a]+1)
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=100000+10;

int dp[MAXN],c[5],d[5];

signed main() {
	REP(i,1,4) c[i]=read();
	dp[0]=1;
	REP(i,1,4) REP(j,c[i],MAXN) dp[j]+=dp[j-c[i]];
	int m=read();
	while(m--) {
		REP(i,1,4) d[i]=read();
		int s=read(),ans=dp[s];
		REP(i,1,4) if(s>=calc(i)) ans-=dp[s-calc(i)];
		REP(i,1,4) REP(j,i+1,4) if(s>=calc(i)+calc(j)) ans+=dp[s-calc(i)-calc(j)];
		REP(i,1,4) REP(j,i+1,4) REP(k,j+1,4) if(s>=calc(i)+calc(j)+calc(k)) ans-=dp[s-calc(i)-calc(j)-calc(k)];
		if(s>=calc(1)+calc(2)+calc(3)+calc(4)) ans+=dp[s-calc(1)-calc(2)-calc(3)-calc(4)];
		printf("%lld\n",ans);
	}
	return 0;
}
