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

const int MAXN=65536+10;

int p[MAXN],cover[MAXN],f[MAXN];

int main() {
	int n=read(),_case=0;
	while(n) {
		memset(cover,0,sizeof(cover));
		memset(f,0,sizeof(f));
		memset(p,0,sizeof(p));
		REP(i,0,n-1) {
			int m=read();
			p[i]|=1<<i;
			REP(j,1,m) p[i]|=(1<<read());
		}

		int sum=(1<<n)-1;

		REP(s,0,sum) {
			cover[s]=0;
			REP(i,0,n-1) if(s&(1<<i)) cover[s]|=p[i];
		}

		
		f[0]=0;
		REP(s,0,sum) {
			f[s]=0;
			for(int s0=s; s0; s0=(s0-1)&s) {
				if(cover[s0]==sum) f[s]=max(f[s],f[s^s0]+1);
			}
		}

		printf("Case %d: %d\n",++_case,f[sum]);
		n=read();
	}
	return 0;
}
