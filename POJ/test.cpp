#include<cstdio>
#include<cstring>
#include<algorithm>
#define zero(u) memset(u,0,sizeof(u))
using namespace std;
bool vis[200001];
int f[200001],l[200001],nxt[400001],to[400001],deg[200001],w[400001],ans[200001],n,t,tot;
inline void dp(register int u)
{
    vis[u]=true;
    f[u]=0;
    for(register int i=l[u];i;i=nxt[i])
    {
        int v=to[i];
        if(vis[v]) continue;
        dp(v);
        if(deg[v]==1) f[u]+=w[i];
        else f[u]+=min(f[v],w[i]);
    }
}
inline void dfs(register int u)
{
    vis[u]=true;
    for(register int i=l[u];i;i=nxt[i])
    {
        int v=to[i];
        if(vis[v]) continue;
        if(deg[u]==1) ans[v]=f[v]+w[i];
        else ans[v]=f[v]+min(ans[u]-min(f[v],w[i]),w[i]);
        dfs(v);
    }
}
inline void add(register int u,register int v,register int z)
{
    to[++tot]=v;w[tot]=z;nxt[tot]=l[u];l[u]=tot;return;//建边
}
signed main()
{
    scanf("%d",&t);
    while(t--)
    {
        zero(f);zero(l);zero(nxt);zero(to);zero(deg);
        zero(w);zero(ans);zero(vis);tot=0;//全部清掉
        scanf("%d",&n);
        for(register int i=1,u,v,z;i<n;i++) 
        {
            scanf("%d%d%d",&u,&v,&z);deg[u]++;deg[v]++;
            add(u,v,z);
            add(v,u,z);//建边
        }
        dp(2);
        zero(vis);
        ans[2]=f[2];
        dfs(2);
        int maxx=0;
        for(register int i=1;i<=n;i++) maxx=max(maxx,ans[i]);        printf("%d\n",maxx);
    }
}
