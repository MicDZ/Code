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
const int MAXN=1000000+10;

const int INF=10000000+1;
struct Splay {
	
	int rt,tot,val[MAXN],ch[MAXN][2],fa[MAXN],size[MAXN],mx[MAXN],g[MAXN];
	
	Splay() {
		rt=0,tot=0;
		memset(val,0,sizeof(val));
		memset(ch,0,sizeof(ch));
		memset(fa,0,sizeof(fa));
		memset(size,0,sizeof(size));
	}

	void maintain(int x) {
		size[x]=size[ch[x][0]]+size[ch[x][1]]+1;
		mx[x]=g[x];
		mx[x]=max(mx[x],max(mx[ch[x][1]],mx[ch[x][0]]));
		if(val[x]==INF||val[x]==0) mx[x]=0,g[x]=0;
	}
	int get(int x) {return x==ch[fa[x]][1];}
	void rotate(int x) {
		int y=fa[x],z=fa[y],chk=get(x);
		ch[y][chk]=ch[x][chk^1];
		fa[ch[x][chk^1]]=y;
		ch[x][chk^1]=y;
		fa[y]=x;
		fa[x]=z;
		if(z) ch[z][y==ch[z][1]]=x;
		maintain(y);
		maintain(x);
	}
	void splay(int x,int g=0) {
		while(fa[x]!=g) {
			int f=fa[x],ff=fa[f];
			if(ff!=g) get(x)==get(f)?rotate(f):rotate(x);
			rotate(x);
		}
		if(!g) rt=x;
	}
	void init() {
		rt=++tot;val[tot]=INF;size[rt]=2;fa[rt]=0;ch[rt][1]=++tot;
		val[tot]=0;size[tot]=1;ch[tot][1]=ch[tot][0]=0;fa[tot]=rt;
	}

	int kth(int k) {
		int cnr=rt;
		while(1) {
			if(ch[cnr][0]&&k<=size[ch[cnr][0]]) cnr=ch[cnr][0];
			else {
				k-=size[ch[cnr][0]]+1;
				if(k<=0) 
					return cnr;
				cnr=ch[cnr][1];
			}
		}
	}
	int ask(int p,int i) {
		int a=kth(p),b=kth(p+1);
		splay(a,0);splay(b,a);
		int t=ch[rt][1];
		ch[t][0]=++tot;
		fa[tot]=t;
		val[tot]=i;
		ch[tot][1]=ch[tot][0]=0;
		size[tot]=1;splay(t,0);
		splay(tot,0);
		g[tot]=mx[ch[rt][0]]+1;maintain(tot);
		return mx[tot];
	}
} s;


int main() {
	file("最长上升子序列");
	int n=read();
	s.init();
	REP(i,1,n) {
		int p;scanf("%d",&p);p++;DE("%d\n",p);
		printf("%d\n",s.ask(p,i));
	}
}

