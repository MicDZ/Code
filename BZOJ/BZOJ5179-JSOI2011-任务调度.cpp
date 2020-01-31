#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define int ll
using namespace std;
 
#define REP(i,e,s) for(register int i=(e); i<=(s); i++)
#define DREP(i,e,s) for(register int i=(e); i>=(s); i--)
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define ll long long
 
int read() {
    int x=0,f=1,ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
 
const int MAXN=500+10,MAXM=300000+10;
 
namespace brute {
    struct edge {
        int m,id;
    } ;
    bool operator< (edge a,edge b) {
        return a.m>b.m;
    }
    priority_queue<edge> q[MAXN];
    void main() {
        read(),read();int _k=read();
        while(_k--) {
            char op[20];scanf("%s",op+1);
            if(op[1]=='A') {
                int n=read(),k=read(),w=read();
                q[n].push((edge){w,k});
            }
            else if(op[1]=='D') {
                int n=read(),k=read(),w=read();
                vector<edge> g;
                while(q[n].top().id!=k) g.push_back(q[n].top()),q[n].pop();
                edge x=q[n].top();q[n].pop();
                REP(i,0,(int)g.size()-1) q[n].push(g[i]);
                x.m-=w;
                q[n].push(x);
            }
            else if(op[1]=='T') {
                int n1=read(),n2=read(),flag=0;
                if(q[n1].size()>q[n2].size()) swap(n1,n2),flag=1;
                while(q[n1].size()) q[n2].push(q[n1].top()),q[n1].pop();
                if(flag) swap(q[n1],q[n2]);
            }
            else if(op[1]=='M') {
                int n=read();
                printf("%lld\n",q[n].top().m);
            }
            else if(op[1]=='W'){
                int n=read(),w=read();
                if(q[n].empty()) {
                    puts("ERROR");continue;
                }
                edge tp1=q[n].top();q[n].pop();
                if(q[n].empty()) {
                    tp1.m+=w;
                    q[n].push(tp1);
                }
                else {
                    edge tp2=q[n].top();
                    if(tp1.m==tp2.m) {
                        puts("ERROR");
                        q[n].push(tp1);
                    }
                    else {
                        tp1.m+=w;
                        q[n].push(tp1);
                    }
                }
            }
        }
    }
}
 
namespace AC {
    const int MAXN=500+10,MAXM=300000+10;
    int d[MAXN];
    struct node {
        int w,d,ch[2],fa;
    } q[MAXM];
    bool operator<(node a,node b) {return a.w<b.w;}
    int merge(int x,int y) {
        if(!x||!y) return x+y;
        if(q[y]<q[x]) swap(x,y);
        q[x].ch[1]=merge(q[x].ch[1],y);
        q[q[x].ch[1]].fa=x;
        if(q[q[x].ch[1]].d>q[q[x].ch[0]].d) swap(q[x].ch[1],q[x].ch[0]);
        q[x].d=q[q[x].ch[1]].d+1;
        return x;
    }
    void erase(int n,int k,int w) {
        int u=merge(q[k].ch[0],q[k].ch[1]),g=q[k].fa;
        if(d[n]==k) d[n]=u;
        if(q[g].ch[0]==k) q[g].ch[0]=u;
        else if(q[g].ch[1]==k) q[g].ch[1]=u;
        q[u].fa=g;
        q[k].ch[0]=q[k].ch[1]=q[k].fa=q[k].d=0;
        q[k].w+=w;
        d[n]=merge(d[n],k);
    }
 
    void main() {
        read();read();int _k=read();
        while(_k--) {
            char op[20];
            scanf("%s",op+1);
            if(op[1]=='A') {
                int n=read(),k=read(),w=read();
                q[k].w=w;
                d[n]=merge(d[n],k);
            }
            else if(op[1]=='D') {
                int n=read(),k=read(),w=read();
                erase(n,k,-w);
            }
            else if(op[1]=='T') {
                int n=read(),k=read();
                d[k]=merge(d[n],d[k]);
                d[n]=0;
            }
            else if(op[1]=='M') {
                int n=read();
                printf("%lld\n",q[d[n]].w);
            }
            else if(op[1]=='W') {
                int n=read(),k=read();
                int l=q[d[n]].ch[0],r=q[d[n]].ch[1];
                if((l&&q[l].w==q[d[n]].w)||(r&&q[r].w==q[d[n]].w)) puts("ERROR");
                else erase(n,d[n],k);
            }
        }
 
    }
}
 
signed main() {
    //brute::main();
    AC::main();
    return 0;
}
