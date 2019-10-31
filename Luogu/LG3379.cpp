#include<bits/stdc++.h>
#define MAXN 500000+10


using namespace std;

int head[MAXN],to[MAXN],next[MAXN],cnt=0;

int n,m,s;

void addedge(int u,int v) {
    cnt++;
    to[cnt]=v;
    next[cnt]=head[u];
    head[u]=cnt;
}

int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int d[MAXN],p[MAXN][21];

void dfs(int u,int fa) {
    //cout<<"debug("<<u<<","<<fa<<")"<<endl;
    
    d[u]=d[fa]+1;
    p[u][0]=fa;
    for(int i=1; (1<<i)<=d[u]; i++)
        p[u][i]=p[p[u][i-1]][i-1];
	for(int i=head[u];i;i=next[i]) {
        int v=to[i];
        if(v!=fa)
            dfs(v,u);
    }
}

int lca(int a,int b) {
    if(d[a]>d[b]) swap(a,b);
    for(int i=20; i>=0; i--)
        if(d[a]<=d[b]-(1<<i))
            b=p[b][i];
    if(a==b) return a;
    
    for(int i=20; i>=0; i--) {
        if(p[a][i]==p[b][i]) continue;
        else {
            a=p[a][i];
            b=p[b][i];
        }
    }
    return p[a][0];

}
int main() {
    freopen("P3379.in","r",stdin);
	freopen("P3379.out","w",stdout);
	
	memset(head,-1,sizeof(head));
    
    n=read(); m=read(); s=read();
    for(int i=1; i<=n-1; i++) {
        int x,y;
        x=read(),y=read();
        addedge(x,y);
        addedge(y,x);
    }
    dfs(s,0);
    for(int i=1; i<=m; i++) {
        int a=read(),b=read();
        printf("%d\n",lca(a,b));
    }
    return 0;
}
