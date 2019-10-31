#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define DE(...) fprintf(stderr,__VA_ARGS__);
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define ll long long

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int INF=0x3f3f3f,MAXN=500000+10;

int head[MAXN],to[MAXN],weigh[MAXN],cnt,_next[MAXN];

void addedge(int u,int v,int w) {
    cnt++;
    _next[cnt]=head[u];
    head[u]=cnt;
    to[cnt]=v;
    weigh[cnt]=w;
}

int dist[MAXN],vis[MAXN];

bool dfs(int u) {
    vis[u]=1;
    for(int i=head[u]; i; i=_next[i]) {
        int v=to[i];
        if(dist[v]<dist[u]+weigh[i]) {
            dist[v]=dist[u]+weigh[i];
            if(vis[v]) return 0;
            if(!dfs(v)) return 0;
        }
    }
    vis[u]=0;
    return 1;
}

int main() {
    int n=read(),m=read();
    REP(i,1,m) {
        int op=read(),a,b,c;
        if(op==1) {
            a=read(),b=read(),c=read();
            addedge(b,a,c);
        }
        else if(op==2) {
            a=read(),b=read(),c=read();
            addedge(a,b,-c);
        }
        else if(op==3) {
            a=read(),b=read();
            addedge(a,b,0);
            addedge(b,a,0);
        }
    }

    REP(i,1,n) addedge(0,i,0);
    memset(dist,-127,sizeof(dist));
    //printf("%d\n",dist[1]);
    dist[0]=0;
    if(!dfs(0)) puts("No");
    else puts("Yes");
	return 0;
}

