#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#define DE(...) fprintf(stderr,__VA_ARGS__);
#define DEBUG(a) DE("DEBUG: %d\n",a)
using namespace std;
const int maxn = 1e5 + 1e4, maxm = 1e5 + 1e4;
int Index,pd[maxn],DFN[maxn],LOW[maxn];
int tot,color[maxn],sum[maxn],f[maxn];
int edge,fir[maxn],Next[maxm],to[maxm];
int sta[maxn],top; //手写栈 
int n,m,val[maxn],x[maxm],y[maxm],ans;
int read(){
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-48; ch=getchar();}
    return f*x;    
}
void add(int x,int y){
    to[++edge]=y; Next[edge]=fir[x]; fir[x]=edge;
}
void tarjan(int x){  
    sta[++top]=x;
    pd[x]=1;
    DFN[x]=LOW[x]= ++Index;
    for(int i=fir[x];i;i=Next[i]){
        int v=to[i];
        if(!DFN[v]){
            tarjan(v);
            LOW[x]=min(LOW[x],LOW[v]);
        }
        else if(pd[v]){
            LOW[x]=min(LOW[x],DFN[v]);
        }
    }
    if(DFN[x]==LOW[x]){
        tot++;
        while(sta[top+1]!=x){
            color[sta[top]]=tot;
            sum[tot]+=val[sta[top]];
            pd[sta[top--]]=0;
        }
    }
}
void search(int x){   //在DAG上记忆化搜索
    if(f[x]) return ;
    f[x]=sum[x];
    int maxsum = 0;
    for(int i=fir[x];i;i=Next[i]){
        if(!f[to[i]]) search(to[i]);
        maxsum=max(maxsum,f[to[i]]);
    }
    f[x]+=maxsum;
}
int main(){
    n=read(); m=read();
    for(int i=1;i<=n;i++) val[i]=read();
    for(int i=1;i<=m;i++){
        x[i]=read();                                // 这里用数组保存好原边，便于后续重新建图；
        y[i]=read();
        add(x[i],y[i]);
    }
    for(int i=1;i<=n;i++) if(!DFN[i]) tarjan(i);
    memset(fir,0,sizeof(fir));                 //清空原图
    memset(Next,0,sizeof(Next));
    memset(to,0,sizeof(to));
    edge=0;
    for(int i=1;i<=m;i++){       //重新建图（枚举每一条原边，若不在同一强连通分量里，则连一条边（方向同原边））
        if(color[x[i]]!=color[y[i]])
            add(color[x[i]],color[y[i]]);
    }
	for(int i=1; i<=n; i++) DEBUG(color[i]);
    for(int i=1;i<=tot;i++){  
        if(!f[i]){
            search(i);
            ans=max(ans,f[i]);
        }
    }
    printf("%d",ans);
    return 0;
}
