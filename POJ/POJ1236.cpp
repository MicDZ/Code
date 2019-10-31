#include<cstdio>
#include<queue>
#include<iostream>
using namespace std;
#define MAXN 4000+10
int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int _next[MAXN],head[MAXN],to[MAXN],cnt,dfn[MAXN],low[MAXN];

void addedge(int u,int v){
    cnt++;
    _next[cnt]=head[u];
    head[u]=cnt;
    to[cnt]=v;
}

int n,num,top,cntt;

vector<int> scc[MAXN];

int _stack[MAXN],ins[MAXN],c[MAXN];

void tarjan(int x) {
    dfn[x]=low[x]=++num;
    _stack[++top]=x;
    ins[x]=1;
    for(int i=head[x]; i; i=_next[i]) {
        int v=to[i];
        if(!dfn[v]) {
            tarjan(v);
            low[x]=min(low[x],low[v]);
        }
        else if(ins[v]) low[x]=min(low[x],low[v]);
    }
    if(dfn[x]==low[x]) {
        cntt++;
        int y;
        do{
            y=_stack[top--];
            ins[y]=0;
            c[y]=cntt;
            scc[cntt].push_back(y);
        }while(x!=y);
    }
}

int out[MAXN],in[MAXN];

int main() {
    n=read();
    for(int i=1; i<=n; i++) {
        int x=read();
        while(x!=0) {
            addedge(i,x);
            x=read();
        }
    }
    for(int i=1; i<=n; i++) if(!dfn[i]) tarjan(i);
    for(int x=1; x<=n; x++) {
        for(int i=head[x]; i; i=_next[i]) {
            int y=to[i];
            if(c[x]==c[y]) continue;
            out[c[x]]++;
            in[c[y]]++;
        }
    }
    if(cntt==1) {cout<<1<<endl<<0<<endl;return 0;}
    int p=0,q=0;
    for(int i=1; i<=cntt; i++) {
        if(out[i]==0) p++;
        if(in[i]==0) q++;
    }
    cout<<q<<endl<<max(p,q)<<endl;
}

