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

const int MAXN=800000+10,MOD=1e9+7;

int f[10][MAXN],g[MAXN],a[MAXN];

int main() {
file("2");
	int n=read(),d=read(),s=0;
	REP(i,1,n) {
		a[i]=read();
		s^=a[i];
	}
	sort(a+1,a+1+n);
	f[0][0]=1;
	REP(i,1,n) {
		REP(j,0,2*a[i])  if(j>=MAXN) break; else g[j]=(f[0][j]+f[d-1][j^a[i]])%MOD;
		DREP(k,d-1,0) REP(j,0,2*a[i]) if(j>=MAXN) break; else f[k][j]=(f[k][j]+f[k-1][j^a[i]])%MOD;
		REP(j,0,2*a[i]) if(j>=MAXN) break; else f[0][j]=g[j];
	}
	if(n%d==0) f[0][s]+=MOD-1;

	printf("%d\n",f[0][s]%MOD);
	return 0;
}
