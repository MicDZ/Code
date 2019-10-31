// luogu-judger-enable-o2
#include<iostream>
#include<cstdio>
#include<queue>
#define MAXM 100050
#define MAXN 10000+1000
#define INF 0x3f3f3f3f
using namespace std;
int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int head[MAXN],cnt=1,dis[MAXN],S,T,cur[MAXN],n,m;
struct edge {
    int to,next,w;
}e[MAXM*2];

void addedge(int x,int y,int w) {
    cnt++;
    e[cnt].to=y; e[cnt].next=head[x]; e[cnt].w=w;
    head[x]=cnt;
    cnt++;
    e[cnt].to=x; e[cnt].next=head[y]; e[cnt].w=0;
    head[y]=cnt;
}

queue<int> q;
bool bfs() {
    for(int i=1; i<=n; i++) dis[i]=-1;
    q.push(S);
    dis[S]=0;
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for(int i=head[u]; i; i=e[i].next) {
            int v=e[i].to;
            if(e[i].w>0&&dis[v]==-1) {
                dis[v]=dis[u]+1;
                q.push(v);
            }	
        }
    }
    return dis[T]!=-1;
}


/*核心代码*/
 

int dfs(int u,int minn) {
    if(u==T) return minn;
    int ft=0,sum=0;
    for(int i=cur[u]; i>0; i=e[i].next) {
        cur[u]=i;
        int v=e[i].to;
        if(e[i].w>0&&dis[v]==dis[u]+1&&(ft=dfs(v,min(minn-sum,e[i].w)))) { 
            e[i].w-=ft; e[i^1].w+=ft;
            sum+=ft;
            
        }
    } 
    return sum;
}

int time=read();
int cntt=0;
int main() {
    //freopen("1.in","r",stdin);
    
    n=read(),m=read(),S=1,T=n;
    
    for(int i=1; i<=m; i++) {
        int u=read(),v=read(),s=read();
        addedge(u,v,s);
    }
//	for(int i=1; i<=m; i++)addedge(read(),read(),read()); 
    int sum=0;
    while(bfs()) {
        for(int i=1; i<=n; i++) cur[i]=head[i];
        
        //cout<<"in";
        while(1) {
            int dpt=dfs(S,INF);//cout<<dpt; 
            if(!dpt) break;
            sum+=dpt;
        } 
    }
    cntt++;
    cout<<"Case: "<<cntt<<": "<<sum<<endl;
    time--;
    if(time==0)return 0;
    else main();
    return 0;
}