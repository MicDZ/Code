#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

#define REP(i,e,s) for(register int i=(e); i<=(s); i++)
#define DREP(i,e,s) for(register int i=(e); i>=(s); i--)
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define ll long long
#define int ll
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=3000+10;

int f[MAXN][MAXN];

signed main() {
	int n=read(),k=read(),p=read();
	f[0][0]=1;
	REP(i,1,k) REP(j,3*i,n) f[i][j]=(f[i-1][j-3]*(j-1)*(j-2)%p+(j-1)*f[i][j-1]%p)%p;
	
	printf("%lld\n",f[k][n]);
	return 0;
}

