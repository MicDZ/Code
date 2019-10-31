//////////////////////////////////////////////
// Author: MicDZ 
// Email: me@micdz.cn 
// Last modified: 2019-07-31 18:53
// Filename: LG2829.cpp
//////////////////////////////////////////////
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)

int read() {
    int x=0,f=1,ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

const int MAXN=5000+10,MAXM=200000+10,INF=1073741824;

int n,r,k,_next[MAXM],head[MAXN],to[MAXM],weigh[MAXM],cnt,have[MAXN][MAXN],tot[MAXN];

void addedge(int u,int v,int w) {
    cnt++;
    _next[cnt]=head[u];
    head[u]=cnt;
    to[cnt]=v;
    weigh[cnt]=w;
    if(!have[u][v]) {
        have[u][v]=1;
        tot[v]++;
    }
}
int dis1[MAXN],dis2[MAXN],dis3[MAXN],inq[MAXN];

void SPFA1(int st) {
    queue<int> q;
    q.push(st);
    memset(inq,0,sizeof(inq));
    memset(dis1,1,sizeof(dis1));
    dis1[st]=0;
    while(!q.empty()) {
        int u=q.front();q.pop();
        inq[u]=0;
        for(int i=head[u]; i; i=_next[i]) {
            int v=to[i];
            if((dis1[v]>dis1[u]+weigh[i])&&(tot[v]>=k||v==n||v==1)) {
                dis1[v]=dis1[u]+weigh[i];
                if(!inq[v]) {
                    q.push(v);
                    inq[v]=1;
                }
            } 
        }
    }
}
void SPFA2(int st) {
    queue<int> q;
    q.push(st);
    memset(inq,0,sizeof(inq));
    memset(dis2,1,sizeof(dis2));
    dis2[st]=0;
    while(!q.empty()) {
        int u=q.front();q.pop();
        inq[u]=0;
        for(int i=head[u]; i; i=_next[i]) {
            int v=to[i];
            if((dis2[v]>dis2[u]+weigh[i])&&(tot[v]>=k||v==n||v==1)) {
                dis2[v]=dis2[u]+weigh[i];
                if(!inq[v]) {
                    q.push(v);
                    inq[v]=1;
                }
            } 
        }
    }
}

struct edge{
    int id,step;
	vector<int> ans;
};

edge SPFA3(int st) {
    queue<edge> q;
    q.push((edge){st,1});
    memset(inq,0,sizeof(inq));
    memset(dis3,1,sizeof(dis3));
    dis3[st]=0;
    while(!q.empty()) {
        edge u=q.front();q.pop();
        inq[u.id]=0;
        if(u.id==n) return u;
        for(int i=head[u.id]; i; i=_next[i]) {
            int v=to[i];
            if((dis3[v]>dis3[u.id]+weigh[i])&&(tot[v]>=k||v==n||v==1)) {
                dis3[v]=dis3[u.id]+weigh[i];
                if(!inq[v]) {
                    
                    edge push_el;push_el.id=v,push_el.ans=u.ans,push_el.ans.push_back(weigh[i]),push_el.step=u.step+1;
                    q.push(push_el);
                    inq[v]=1;
                }
            } 
        }
    }
}

int main() {
    //freopen("POJ3255.in","r",stdin);
    n=read(),r=read(),k=read();
    REP(i,1,r) {
        int u=read(),v=read(),w=read();
        addedge(u,v,w);
        addedge(v,u,w);
    }
    //REP(i,1,n) cout<<tot[i]<<" ";
    //puts("");
    SPFA1(1);
    SPFA2(n);
    int ans=INF;
    if(dis1[n]>=dis1[0]) {
        puts("-1");return 0;
    }
    REP(u,1,r) {
        int s;
        for(int j=head[u]; j; j=_next[j]) {
            int v=to[j];
            if(dis1[u]<=dis1[v])
        		s=weigh[j]+dis1[u]+dis2[v];
            else s=weigh[j]+dis2[u]+dis1[v];
            if(s>dis1[n]&&ans>s) ans=s;
            s=weigh[j]*3;
            if(u==1&&v==n&&s>dis1[n]&&ans>s) ans=s;
        }
    }

    edge x=SPFA3(1);
    int minn=INF;
    REP(i,0,x.ans.size()-1) minn=min(minn,x.ans[i]);

	int s=dis3[n]+2*minn;
	ans=min(ans,s);
	printf("%d\n",ans);
}


