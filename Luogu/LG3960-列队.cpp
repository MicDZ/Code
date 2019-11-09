#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>

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

const int MAXN=300000+10;

int n,m,q,rt[MAXN],tot;

struct SegmentTree {
	int lson,rson,sum;
	#define lson(x) tree[x].lson
	#define rson(x) tree[x].rson
	#define sum(x) tree[x].sum
}tree[MAXN<<2];

int ask(int p,int l,int r,int d) {
	if(l==r) return l;
	int mid=(l+r)>>1,temp=mid-l+1-sum(lson(p));
	if(d<=temp) return ask(lson(p),l,mid,d);
	else return ask(rson(p),mid+1,r,d-temp);
}

void change(int &p,int l,int r,int x) {
	if(!p) p=++tot;sum(p)++;
	if(l==r) return ;
	int mid=(l+r)>>1;
	if(x<=mid) change(lson(x),l,mid,x);
	else change(rson(x),mid+1,r,x);
}

vector<int> v[MAXN];

int main() {
	n=read(),m=read(),q=read();
	int lim=max(n,m)+q;
	REP(t,1,q) {
		int x=read(),y=read();
		if(y==m) {
			int pos=ask(rt[n+1],1,lim,x);
			change(rt[n+1],1,lim,pos);
			int ans=pos<=n?pos*m:v[n+1][pos-n-1];
			v[n+1].push_back(y?y:ans);
			printf("%d\n",ans);
		}
		else {
			int pos=ask(rt[x],1,lim,y);
			change()
		}	
	}
	return 0;
}
