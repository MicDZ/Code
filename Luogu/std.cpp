#include <bits/stdc++.h>
#define N 100000 
#define LL long long 
using namespace std;

LL q;
int a[(N+5)<<2],cnt=0,tot=0,pr[N+5];
bool vis[N+5];

void init() {
    for(int i=2;i<=N;++i) {
        if(!vis[i]) pr[++tot]=i;
        for(int j=1;j<=tot && i*pr[j]<=N;++j) {
            vis[i*pr[j]]=1;
            if(i%pr[j]==0) break;
        }
    }
}

inline bool is_prime(int x) {
    if(x==1) return 0;
    if(x<=N) return !vis[x];
    for(int i=1;pr[i]*pr[i]<=x;++i)
        if(x%pr[i]==0) return 0;
    return 1;
}

void dfs(LL now,int x,LL y) {
    if(now==1) {
        a[++cnt]=y;
        return;
    }
    if(now-1>=pr[x] && is_prime(now-1)) {
        a[++cnt]=y*(now-1);
    }   
    int i;
    LL p,tmp;
    for(i=x;pr[i]*pr[i]<=now;++i) {
        tmp=pr[i];
        p=pr[i]+1;
        for(;p<=now;tmp*=pr[i],p+=tmp) {
            if(now%p==0) dfs(now/p,i+1,y*tmp);      
        }
    }
    return;
}

int main() {
	freopen("data.in","r",stdin);
	freopen("data.ans","w",stdout);
    init();
    int i;
    int m;
    while(~scanf("%d",&m)) {
        q=sqrt(m);
        memset(a,0,sizeof(a));
        cnt=0;
        dfs(1LL*m,1,1LL);
        printf("%d\n",cnt);     
        sort(a+1,a+cnt+1);
        for(i=1;i<cnt;++i) printf("%d ",a[i]);
        if(cnt) printf("%d\n",a[cnt]);
    }
} 
