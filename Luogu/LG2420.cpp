#include<bits/stdc++.h>
#define MAXN 500000+10


using namespace std;

int head[MAXN],to[MAXN<<1],next[MAXN<<1],weigh[MAXN<<1],cnt=0;

int n,m,s;

void addedge(int u,int v,int w) {
    cnt++;
    to[cnt]=v;
    next[cnt]=head[u];
    head[u]=cnt;
    weigh[cnt]=w;
}

int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int d[MAXN],p[MAXN][21];

void dfs(int k)
{
    for(int j=head[k];j!=-1;j=next[j])
        if(!d[to[j]])
            d[to[j]]=d[k]+1,d[to[j]]=d[k]^weigh[j],dfs(to[j]);
}

int main() {

    memset(head,-1,sizeof(head));

    n=read();  s=1;
    for(int i=1; i<=n-1; i++) {
        int x,y,w;
        x=read(),y=read(),w=read();
        addedge(x,y,w);
        addedge(y,x,w);
    }
    int m=read();
    dfs(s);
    for(int i=1; i<=m; i++) {
        int a=read(),b=read();
        printf("%d\n",d[a]^d[b]);
    }
    return 0;
}

