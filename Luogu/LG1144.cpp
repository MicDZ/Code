#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000000+10
#define MAXM 2000000+10
#define MOD 100003

#define INF 0x3f3f3f

int read() {
     int x=0,f=1;
     char ch=getchar();
     while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
     while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
     return x*f;
}

int next[MAXM],head[MAXN],to[MAXM],cnt;

void addedge(int u,int v) {
    cnt++;
    to[cnt]=v;
    next[cnt]=head[u];
    head[u]=cnt;
}

int last[MAXN];

int d[MAXN],inq[MAXN],num[MAXN];

bool after_first_spfa=0;

void SPFA() {
    memset(d,INF,sizeof(d));
    memset(inq,0,sizeof(inq));
    queue<int> q;
    q.push(1); d[1]=0;
    inq[1]=1;num[1]=1;
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        inq[u]=0;
        for(int i=head[u]; i; i=next[i]) {
            int v=to[i];
            if(d[u]+1<d[v]) {
                d[v]=d[u]+1;
                if(!inq[v]) {
                    inq[v]=1;
                    q.push(v);
                }
				num[v]=0;
            }
			if(d[u]+1==d[v]) num[v]+=num[u]%MOD;
        }
    }
}

int main() {
    int n=read(),m=read();
    for(int i=1; i<=m; i++) {
        int u=read(),v=read();
        addedge(u,v);
        addedge(v,u);
    }
    SPFA();
	for(int i=1; i<=n; i++) {
		cout<<num[i]%MOD<<endl;
	}
}

