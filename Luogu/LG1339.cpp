//
// Created by Douglas on 2018/6/11.
//

#include<bits/stdc++.h>

#define MAXN 10000+10
#define MAXM 500000+10
#define INF 0x3f3f3f
using namespace std;

int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int next[MAXM<<1],to[MAXM<<1],weigh[MAXM<<1],head[MAXN],cnt,dis[MAXN];

int n,m,S;
void add(int u,int v,int w) {
    cnt++;
    to[cnt]=v;
    next[cnt]=head[u];
    head[u]=cnt;
    weigh[cnt]=w;
}
bool have[MAXN];
void SPFA() {
    queue<int> q;
    bool inq[MAXN];
    memset(inq,0,sizeof(inq));
    memset(dis,INF,sizeof(dis));
    q.push(S); inq[S]=true; dis[S]=0;
    while(!q.empty()) {
        int u=q.front();
        q.pop(); inq[u]=0;
        for(int i=head[u]; i; i=next[i]) {
            int v=to[i],w=weigh[i];
            have[v]=true;
            if(dis[v]>dis[u]+w) {
                dis[v]=dis[u]+w;
                if(!inq[v]) {
                    q.push(v);
                    inq[v]=1;
                }
            }
        }
    }

}
int main() {
    n=read(),m=read(),S=read();
    for(int i=1; i<=m; i++) {
        int u=read(),v=read(),w=read();
        add(u,v,w);
    }
    SPFA();
    for(int i=1; i<= n; i++) {
        if(!have[i])cout<<2147483647<<" ";
        else cout<<dis[i]<<" ";
    }
}