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
const int MAXN=100000+10;
int n,m;

struct Splay {
	int rt,tot,val[MAXN],ch[MAXN][2],fa[MAXN],cnt[MAXN],size[MAXN],tag[MAXN];
	
	Splay() {
		rt=0,tot=0;
		memset(val,0,sizeof(val));
		memset(ch,0,sizeof(ch));
		memset(fa,0,sizeof(fa));
		memset(cnt,0,sizeof(cnt));
		memset(size,0,sizeof(size));
	}

	void maintain(int x) {size[x]=size[ch[x][0]]+size[ch[x][1]]+cnt[x];}
	int get(int x) {return x==ch[fa[x]][1];}
	void clear(int x) {fa[x]=val[x]=ch[x][0]=ch[x][1]=size[x]=cnt[x]=0;}
	void pushdown(int x) {
		if(tag[x]) {
			tag[ch[x][0]]^=1;
			tag[ch[x][1]]^=1;
			tag[x]=0;
			swap(ch[x][0],ch[x][1]);
		}
	}
	void rotate(int x) {
		int y=fa[x],z=fa[y],chk=get(x);
		pushdown(x),pushdown(y);
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
	void insert(int k) {
		if(!rt) {
			rt=++tot;
			cnt[tot]++;
			val[tot]=k;
			maintain(tot);
			return ;
		}
		int cnr=rt,f=0;
		while(1) {
			if(val[cnr]==k) {
				cnt[cnr]++;
				maintain(f);
				maintain(cnr);
				splay(cnr);
				return ;
			}
			f=cnr;
			cnr=ch[cnr][val[cnr]<k];
			if(!cnr) {
				cnr=++tot;
				cnt[tot]++;
				val[tot]=k;
				fa[tot]=f;
				ch[f][val[f]<k]=tot;
				maintain(f);
				maintain(cnr);
				splay(cnr);
				return ;
			}
		}
	}

	int rk(int k) {
		int res=0,cnr=rt;
		while(1) {
			if(k<val[cnr]) cnr=ch[cnr][0];
			else {
				res+=size[ch[cnr][0]];
				if(val[cnr]==k) {
					splay(cnr);
					return res+1;
				}
				res+=cnt[cnr];
				cnr=ch[cnr][1];
			}
		}
	}
	int kth(int k) {
		int cnr=rt;
		while(1) {
			pushdown(cnr);
			if(ch[cnr][0]&&k<=size[ch[cnr][0]]) cnr=ch[cnr][0];
			else {
				k-=size[ch[cnr][0]]+cnt[cnr];
				if(k<=0) 
					return val[cnr];
				cnr=ch[cnr][1];
			}
		}
	}
	int pre() {
		int cnr=ch[rt][0];
		while(ch[cnr][1]) cnr=ch[cnr][1];
		return cnr;
	}
	int nxt() {
		int cnr=ch[rt][1];
		while(ch[cnr][0]) cnr=ch[cnr][0];
		return cnr;
	}

	void del(int k) {
		rk(k);
		if(cnt[rt]>1) {
			cnt[rt]--;
			maintain(rt);
			return ;
		}
		if(!ch[rt][0]&&!ch[rt][1]) {
			clear(rt);
			rt=0;
			return ;
		}
		if(!ch[rt][0]) {
			int cnr=rt;
			rt=ch[cnr][1];
			fa[rt]=0;
			clear(cnr);
			return ;
		}
		if(!ch[rt][1]) {
			int cnr=rt;
			rt=ch[cnr][0];
			fa[rt]=0;
			clear(cnr);
			return ;
		}
		int cnr=rt,x=pre();
		splay(x);
		ch[x][1]=ch[cnr][1];
		fa[ch[cnr][1]]=x;
		clear(cnr);
		maintain(rt);
		return ;
	}
	void work(int x,int y) {
		int l=kth(x),r=kth(y+2);
		splay(l,0);
		splay(r,l);
		tag[ch[ch[rt][1]][0]]^=1;
	}
	void write(int x) {
		pushdown(x);
		if(ch[x][0]) write(ch[x][0]);
		if(val[x]>1&&val[x]<n+2) printf("%d ",val[x]-1);
		if(ch[x][1]) write(ch[x][1]);
	}
} s;

const int INF=0x3f3f3f3f;

int main() {
	//file("splay");
	n=read(),m=read();
	REP(i,1,n+2) s.insert(i);
	REP(i,1,m) {int l=read(),r=read();s.work(l,r);}
	s.write(s.rt);

}
