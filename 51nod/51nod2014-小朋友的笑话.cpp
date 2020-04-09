#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<set>
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a)	freopen(a".in","r",stdin);freopen(a".out","w",stdout)
using namespace std;

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m;
namespace Brute {
	const int MAXN=1e4+10;
	bool mark[MAXN][MAXN],sta[MAXN];
	void main() {
		REP(i,1,m) {
			int op=read();
			if(op==1) {
				int x=read(),l=read(),k=read();
				REP(j,max(1,x-k),min(n,x+k)) {
					if(mark[j][l]) sta[j]=0;
					else sta[j]=1;
					mark[j][l]=1;
				}
			}
			else {
				int l=read(),r=read(),ans=0;
				REP(j,l,r) ans+=sta[j];
				printf("%d\n",ans);
			}
		}
	}
}

namespace AC {
	const int MAXN=1e5+10;

	set<pair<int,int> > s[MAXN];

	struct SegmentTree {
		int lf[MAXN<<2],rg[MAXN<<2],add[MAXN<<2],sum[MAXN<<2],a[MAXN<<2];
#define l(x) lf[x]
#define r(x) rg[x]
#define len(x) (rg[x]-lf[x]+1)
		void pushup(int p) {sum[p]=sum[p*2]+sum[p*2+1];}
		void pushdown(int p) {
			if(add[p]!=-1) {
				add[p*2]=add[p];
				add[p*2+1]=add[p];
				sum[p*2]=add[p]*len(p*2);
				sum[p*2+1]=add[p]*len(p*2+1);
				add[p]=-1;
			}
		}
		void build(int p,int l,int r) {
			l(p)=l,r(p)=r;
			if(l==r) {sum[p]=0,add[p]=-1;return ;}
			int mid=(l+r)>>1;
			build(p*2,l,mid);
			build(p*2+1,mid+1,r);
			pushup(p);
		}
		void change(int p,int l,int r,int d) {
			if(l(p)>=l&&r(p)<=r) {
				sum[p]=d*len(p);
				add[p]=d;
				return ;
			} 
			pushdown(p);
			int mid=(l(p)+r(p))>>1;
			if(l<=mid) change(p*2,l,r,d);
			if(r>mid) change(p*2+1,l,r,d);
			pushup(p);
		}
		int ask(int p,int l,int r) {
			if(l(p)>=l&&r(p)<=r) return sum[p];
			int ans=0;
			pushdown(p);
			int mid=(l(p)+r(p))>>1;
			if(l<=mid) ans+=ask(p*2,l,r);
			if(r>mid) ans+=ask(p*2+1,l,r);
		return ans;
		}
	} seg;
#define mp(a,b) make_pair(a,b)
	void main() {
		seg.build(1,1,n);
		REP(i,1,m) {
			int op=read();
			if(op==1) {
				int x=read(),L=read(),k=read(),l=max(1,x-k),r=min(n,x+k),tl=l,tr=r;
				if(s[L].empty()) {
					seg.change(1,l,r,1);
					s[L].insert(mp(l,r));
				}
				else {
					set<pair<int,int> >::iterator it=s[L].lower_bound(mp(l,0));
					set<pair<int,int> >::iterator pre=it;
					if(it!=s[L].begin()) {
						pre--;
						if((*pre).second>=l) it=pre;
					}
					if(it==s[L].end()||(*it).first>r) {
						seg.change(1,l,r,1);
						s[L].insert(mp(l,r));
					}
					else {
						tl=min(tl,(*it).first);seg.change(1,l,r,1);
						seg.change(1,l,r,1);
						while(it!=s[L].end()&&(*it).first<=r) {
							seg.change(1,max(l,(*it).first),min(r,(*it).second),0);				
							tr=max(tr,(*it).second);
							pre=it,it++;s[L].erase(pre);
						}
						s[L].insert(mp(tl,tr));
					}
				}
			}
			else {
				int l=read(),r=read();
				printf("%d\n",seg.ask(1,l,r));
			}
		}
	}
}

int main() {
	file("test");
	n=read(),m=read();
	AC::main();
	return 0;
}
