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

const int MAXN=100000+10,INF=0x3f3f3f3f;

int a[MAXN];

int main() {
	int n=read(),m=read(),f=read();
	REP(i,1,n) a[i]=read();
	int lastans=0;
	REP(t,1,m) {
		int op=read();
		if(op==1) {
			int l=read(),r=read(),x=read();
			if(f==1) l^=lastans,r^=lastans,x^=lastans;
			REP(i,l,r) a[i]=x;
		}
		else if(op==2) {
			int x=read(),y=read();
			if(f==1) x^=lastans,y^=lastans;
			if(x>y) swap(x,y);
			int ans=INF;
			REP(i,1,n) REP(j,i,n) {
				if(a[i]==x&&a[j]==y) ans=min(ans,j-i);
			}
			printf("%d\n",ans==INF?-1:ans);
			lastans=ans==INF?0:ans;
		}
	}
	return 0;
}
