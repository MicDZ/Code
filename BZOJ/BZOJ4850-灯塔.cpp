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

const int MAXN=100000+10;

int n,lg[MAXN],st[20][MAXN];

int ask(int l,int r) {
	l=max(1,l),r=min(r,n);
	if(l>n) return 0;if(r<1) return 0;
	return max(st[lg[r-l+1]][l],st[lg[r-l+1]][r-(1<<lg[r-l+1])+1]);
}

signed main() {
	n=read();
	REP(i,1,n) st[0][i]=read();
	REP(i,2,n) lg[i]=lg[i>>1]+1;
	REP(i,1,18) for(int j=1; j+(1<<i)-1<=n; j++) st[i][j]=max(st[i-1][j],st[i-1][j+(1<<(i-1))]);
	REP(i,1,n) {
		int ans=0;
		for(int j=1; (j-1)*(j-1)<=n; j++) {
			int l=(j-1)*(j-1)+1,r=j*j;
			ans=max(ans,max(ask(i-r,i-l),ask(i+l,i+r))+j);
		}

		printf("%d\n",max(0,ans-st[0][i]));
	}
	return 0;
}
