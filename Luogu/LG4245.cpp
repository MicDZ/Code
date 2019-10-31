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
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=2333+10,MOD=2333;

ll lucas(ll n,ll m) {
	if(n<MOD&&m<MOD) return c[n][m];
	return c[n%MOD][m%MOD]*lucas(n/MOD,m/MOD)%MOD;
}

ll f(ll n,ll k) {
	if(k<0) return 0;
	if(n==0||k==0) return 1;
	if(n<MOD&&k<MOD) return ff[n][k];
	return (ff[n%MOD][MOD-1]*f(n/MOD,k/MOD-1)+lucas(n/MOD,k/MOD)*ff[n%MOD][k%MOD]%MOD)%MOD;
}

int main() {
	int t=read();
	
	c[0][0]=1;
	REP(i,1,MOD) c[i][i]=1,c[i][0]=1;
	
	REP(i,1,MOD) 

	REP(i,1,t) {
		
	}
	return 0;
}
