#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
 
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
 
const int MAXN=80000+10,MAXM=MAXN*200;
 
int rt[MAXM],a[MAXN],b[MAXN];
 
struct President_Tree {
    int cnt,ls[MAXM],rs[MAXM],sum[MAXM];
    void init() {
        cnt=0;
        memset(ls,0,sizeof(ls));
        memset(rs,0,sizeof(rs));
        memset(sum,0,sizeof(sum));
    }
    void build(int &p,int l,int r) {
        p=++cnt;
        if(l==r) return ;
        int mid=(l+r)>>1;
        build(ls[p],l,mid);
        build(rs[p],mid+1,r);
    }
    void change(int &p,int l,int r,int u,int x) {
        p=++cnt,ls[p]=ls[u],rs[p]=rs[u],sum[p]=sum[u]+1;    
 
        if(l==r) return ;
        int mid=(l+r)>>1;
        if(x<=mid) change(ls[p],l,mid,ls[u],x);
        else change(rs[p],mid+1,r,rs[u],x);
    }
    int ask(int x,int y,int l,int r,int lc,int falc,int k) {
        if(x==y) return x;
        int mid=(x+y)>>1;
        int v=sum[ls[l]]+sum[ls[r]]-sum[ls[lc]]-sum[ls[falc]];
        if(v>=k) return ask(x,mid,ls[l],ls[r],ls[lc],ls[falc],k);
        else return ask(mid+1,y,rs[l],rs[r],rs[lc],rs[falc],k-v);
    }
} s;
 
 
int head[MAXN],_next[MAXN<<1],to[MAXN<<1],cnt;
 
void addedge(int u,int v) {
    cnt++;
    _next[cnt]=head[u];
    head[u]=cnt;
    to[cnt]=v;
}
 
int fa[MAXN][25],dist[MAXN];
 
queue<int> q;
 
int sz;
 
void bfs(int s) {
    q.push(s);
    while(!q.empty()) {
        int u=q.front();q.pop();
        for(int i=head[u]; i; i=_next[i]) {
            int v=to[i];
            if(fa[u][0]==v) continue;
            fa[v][0]=u;
            dist[v]=dist[u]+1;
            q.push(v);
        }
    }
}
 
int f[MAXN],son[MAXN],vis[MAXN];
 
int find(int x) {
    if(f[x]==x) return x;
    return f[x]=find(f[x]);
}
 
void dfs(int u,int p,int _rt) {
    fa[u][0]=p;
    REP(i,1,19) fa[u][i]=fa[fa[u][i-1]][i-1];
    son[_rt]++;
    dist[u]=dist[p]+1;
    f[u]=p;
    vis[u]=1;
    s.change(rt[u],1,sz,rt[p],a[u]);
    for(int i=head[u]; i; i=_next[i]) {
        int v=to[i];
        if(v==p) continue;
        dfs(v,u,_rt);
    }
}
 
int lca(int u,int v) {
    if(dist[u]<dist[v]) swap(u,v);
    int len=dist[u]-dist[v];
    DREP(i,19,0) if(1<<i&len) u=fa[u][i];
    if(u==v) return u;
    DREP(i,19,0) if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}
 
int last=0;
 
void init() {
    memset(head,0,sizeof(head));
    memset(vis,0,sizeof(vis));
    memset(fa,0,sizeof(fa));
    memset(dist,0,sizeof(dist));
    memset(son,0,sizeof(son));
    memset(rt,0,sizeof(rt));
    cnt=0;
}
 
int main() {
    read(); 
//  s.init();init();
    int n=read(),m=read(),q=read();
    REP(i,1,n) a[i]=b[i]=read(),f[i]=i;
    sort(b+1,b+1+n);
    sz=unique(b+1,b+1+n)-b-1;
    s.build(rt[0],1,sz);
 
    REP(i,1,n) a[i]=lower_bound(b+1,b+1+sz,a[i])-b; 
    REP(i,1,m) {
        int u=read(),v=read();
        addedge(u,v);
        addedge(v,u);
    }
    REP(i,1,n) {
        if(!vis[i]) {
            dfs(i,0,i);
            f[i]=i;
        }
    }
    int last=0;
 
    REP(i,1,q) {
        char op[3];
        scanf("%s",op+1);
        if(op[1]=='Q') {
            int u=read()^last,v=read()^last,k=read()^last,_lca=lca(u,v);
            last=b[s.ask(1,sz,rt[u],rt[v],rt[_lca],rt[fa[_lca][0]],k)];
            printf("%d\n",last);
        }
        else {
            int u=read()^last,v=read()^last,rtu=find(u),rtv=find(v);
            addedge(u,v);addedge(v,u);
            if(son[rtu]<son[rtv]) swap(u,v),swap(rtu,rtv);
            dfs(v,u,rtu);
        }   
    }
    return 0;
}
