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

const int MAXN=5e4+10;

int fa[MAXN<<2];

int find(int x) {
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

void link(int x,int y) {
	fa[find(x)]=find(y);
}

int main() {
	int n=read(),k=read(),ans=0;

	REP(i,1,3*n) fa[i]=i;

	REP(i,1,k) {
		int op=read(),x=read(),y=read();
		if(x>n||y>n) ans++;
		else {
			if(op==1) {
				if(find(x+n)==find(y)||find(x+2*n)==find(y)) ans++;
				else {
					link(x,y);
					link(x+n,y+n);
					link(x+2*n,y+2*n);
				}
			}
			else {
				if(find(x)==find(y)||find(x+2*n)==find(y)) ans++;
				else {
					link(x,y+2*n);
					link(x+n,y);
					link(x+2*n,y+n);
				}
			}
		}
	}

	printf("%d\n",ans);
	return 0;
}
