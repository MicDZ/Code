#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
 
using namespace std;
#define int ll
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
 
const int MAXN=400000+10;
 
struct SegmentTree {
    int l,r,maxx;
    #define l(x) tree[x].l
    #define r(x) tree[x].r
    #define maxx(x) tree[x].maxx
} tree[MAXN<<2];
 
int a[MAXN];
 
void build(int p,int l,int r) {
    l(p)=l,r(p)=r;
    if(l==r) {maxx(p)=a[l]; return ;}
    int mid=(l+r)>>1;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    maxx(p)=max(maxx(p*2),maxx(p*2+1));
}
 
void change(int p,int x,int d) {
    if(l(p)==r(p)) {maxx(p)=d; return ;}
    int mid=(l(p)+r(p))>>1;
    if(x<=mid) change(p*2,x,d);
    else change(p*2+1,x,d);
    maxx(p)=max(maxx(p*2),maxx(p*2+1));
}
 
signed main() {
    int n=read(),m=read(),q=read(),sum=0;
    REP(i,1,n) a[i]=read(),sum+=a[i];
    build(1,1,n);
    printf("%lld\n",max(maxx(1),(sum-1)/m+1));
    REP(i,1,q) {
        int p=read(),c=read();
        change(1,p,c);
        sum-=a[p],sum+=c;
		a[p]=c;
        printf("%lld\n",max(maxx(1),(sum-1)/m+1));
    }
    return 0;
}
