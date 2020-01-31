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

struct Splay {
	int cnt[MAXN],size[MAXN],val[MAXN],ch[MAXN][2],fa[MAXN];
	void maintain(int x) {size[x]=size[ch[x][1]]+size[ch[x][0]]+cnt[x];}
	bool get(int x) {return x==ch[fa[x]][1];}
	void clear(int x) {cnt[x]=size[x]=val[x]=ch[x][0]=ch[x][1]=fa[x]=0;}

	void rotate(int x) {
		int y=fa[x],z=fa[y],chk=get(x);
		ch[y][chk]=ch[x][chk^1];
		fa[ch[x][chk^1]]=y;
		ch[x][chk^1]=y;
		fa[y]=x;
		fa[x]=z;
		if(z) ch[z][y==ch[z][1]]=x;
	}
} s;

int main() {
	
	return 0;
}
