#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdlib>
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

const int MAXN=100000+10;

int tot,rt;

struct Treap {
	#define val(x) tree[x].val
	#define size(x) tree[x].size
	#define ls(x) tree[x].ls
	#define rs(x) tree[x].rs
	#define rd(x) tree[x].rd
	int val,size,ls,rs,rd;
} tree[MAXN];

void newnode(int &p,int val) {
	++tot;
	size(tot)=1;
	val(tot)=val;
	rd(tot)=rand();
	ls(tot)=rs(tot)=0;
	p=tot;
}

void pushup(int p) {
	size(p)=size(ls(p))+size(rs(p))+1;
} 

void split(int p,int &l,int &r,int val) {
	if(!p) {
		l=r=0;
		return ;
	}
	if(val(p)<=val) l=p,split(rs(p),rs(l),r,val);
	else r=p,split(ls(p),l,ls(r),val);
	pushup(p);
}

void merge(int &p,int a,int b) {
	if(!a||!b) {
		p=a+b;
		return ;
	}
	if(rd(a)<rd(b)) p=a,merge(rs(p),rs(a),b);
	else p=b,merge(ls(p),a,ls(b));
	pushup(p);
}

void insert(int val) {
	int x=0,y=0,z=0;
	newnode(z,val);
	split(rt,x,y,val-1);
	merge(x,x,z);
	merge(rt,x,y);
}

void del(int val) {
	int x=0,y=0,z=0;
	split(rt,x,y,val);
	split(x,x,z,val-1);
	merge(z,ls(z),rs(z));
	merge(x,x,z);
	merge(rt,x,y);
}

void ask_rk(int v) {
	int x=0,y=0;
	split(rt,x,y,v-1);
	printf("%d\n",size(x)+1);
	merge(rt,x,y);
}

void ask_num(int x,int kth) {
	while(size(ls(x))+1!=kth) {
		if(size(ls(x))>=kth) x=ls(x);
		else kth-=(size(ls(x))+1),x=rs(x);
	}
	printf("%d\n",val(x));
}

void ask_pre(int v) {
	int x=0,y=0;
	split(rt,x,y,v-1);
	ask_num(x,size(x));
	merge(rt,x,y);
}

void ask_nxt(int v) {
	int x=0,y=0;
	split(rt,x,y,v);
	ask_num(y,1);
	merge(rt,x,y);
}

int main() {
	file("treap");
	srand(1919);
	int n=read();
	REP(i,1,n) {
		int op=read();
		if(op==1) {
			int x=read();
			insert(x);
		}
		if(op==2) {
			int x=read();
			del(x);
		}
		if(op==3) {
			int x=read();
			ask_rk(x);
		}
		if(op==4) {
			int x=read();
			ask_num(rt,x);
		}
		if(op==5) {
			int x=read();
			ask_pre(x);
		}
		if(op==6) {
			int x=read();
			ask_nxt(x);
		}
	}
	return 0;
}

