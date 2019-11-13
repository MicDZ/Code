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

const int MAXN=1000+10;

int f[MAXN*MAXN],a[MAXN];
int main() {
	int t=read();
	while(t--) {
		int n=read(),ans=n;
		memset(f,0,sizeof(f));
		REP(i,1,n) a[i]=read();
		sort(a+1,a+1+n);
		f[0]=1;
		REP(i,1,n) {
			if(f[a[i]]) 
				ans-=1;
			else REP(j,a[i],a[n]) f[j]=f[j]|f[j-a[i]];
		}
		printf("%d\n",ans);
	}
	return 0;
}

