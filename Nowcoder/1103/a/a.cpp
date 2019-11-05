#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;
#define int ll
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

const ll MOD=1e9+7,MAXN=6e5+10;
int a[MAXN],b[MAXN],pos[MAXN],pre[MAXN],f[MAXN];

int qpow(int a) {
	int ans=1,b=MOD-2;
	while(b) {
		if(b&1) ans=ans*a%MOD;
		a=a*a%MOD;
		b>>=1;
	}
	return ans;
}

int sum[4];

signed main() {
	file("data");
	int n=read(),k=read();
	REP(i,1,n) b[i]=a[i]=read();
	sort(b+1,b+1+n);
	int num=unique(b+1,b+1+n)-b-1;
	REP(i,1,n) a[i]=lower_bound(b+1,b+1+num,a[i])-b;
	
	REP(i,n+1,3*n) a[i]=a[i-n]; 
	REP(i,1,3*n) pre[i]=pos[a[i]],pos[a[i]]=i;
	REP(i,1,3*n) f[i]=f[i-1]+i-pre[i];
	
	
	REP(i,1,3) {
		sum[i]=0;
		REP(j,1+(i-1)*n,i*n) sum[i]=(sum[i]+f[j])%MOD;
	}
	
	int ans=(sum[1]+(2*sum[2]%MOD+(sum[3]-sum[2]+MOD)%MOD*(k+MOD-2)%MOD)%MOD*(k+MOD-1)%MOD*qpow(2))%MOD;
	printf("%lld\n",ans%MOD);
	return 0;
}
