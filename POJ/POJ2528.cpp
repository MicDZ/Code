#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;
#define ll long long
#define REP(i,e,s) for(register ll i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define DE(...) fprintf(stderr,__VA_ARGS__);
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)


int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int INF=0x3f3f3f,MAXN=100000+10,MAX_NUM=10000000+10;

struct SegmentTree {
    int l,r,dat,add;
    #define l(x) tree[x].l
    #define r(x) tree[x].r
    #define dat(x) tree[x].dat
    #define add(x) tree[x].add
}tree[MAXN<<2];

void build(int p,int l,int r) {
    l(p)=l,r(p)=r;
    if(l==r) return ;
    int mid=(l(p)+r(p))>>1;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
}

void spread(int p) {
    if(!dat(p)) return ;
    dat(p*2)=dat(p*2+1)=dat(p);
    dat(p)=0;
}

int vis[MAXN];

void change(int p,int l,int r,int d) {
    if(l(p)>=l&&r(p)<=r) {
        dat(p)=d;
        return ;
    }
    int mid=(l(p)+r(p))>>1;
    spread(p);
    if(l<=mid) change(p*2,l,r,d);
    if(r>mid) change(p*2+1,l,r,d);
}

int ans;

void ask(int p,int l,int r) {
    
    if(dat(p)&&!vis[dat(p)]) {
        ans++;
        vis[dat(p)]=1;
        return ;
    }
    if(l(p)==r(p)) return ;
    //DEBUG(p);
    spread(p);

    int mid=(l(p)+r(p))>>1;
    if(l<=mid) ask(p*2,l,r);
    if(r>mid) ask(p*2+1,l,r);
    //DE("in\n");
    return ;
}

int disc[MAX_NUM],a[MAXN<<2],pl[MAXN],pr[MAXN];

int main() {
    file("POJ2528");
    int t=read();
    while(t--) {
        int n=read();
        ans=0;
        memset(tree,0,sizeof(tree));
        memset(vis,0,sizeof(vis));
        int cnt=0;
        REP(i,1,n) {
            pl[i]=read();
            pr[i]=read();
            a[++cnt]=pl[i];
            a[++cnt]=pr[i];
        }
        sort(a+1,a+1+cnt);
        int tot=cnt=unique(a+1,a+cnt+1)-a-1;
        
        REP(i,1,cnt-1) 
            if(a[i+1]-a[i]>1) a[++tot]=a[i]+1;
        sort(a+1,a+1+tot);

        REP(i,1,tot) disc[a[i]]=i;

        build(1,1,tot);
        
        REP(i,1,n) {
            //printf("%d %d\n",disc[pl[i]],disc[pr[i]]);
            change(1,disc[pl[i]],disc[pr[i]],i);
        }

        //DEBUG(tot);

        ask(1,1,tot);

        printf("%d\n",ans);
    
    }
	return 0;
}