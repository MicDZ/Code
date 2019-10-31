#include<bits/stdc++.h>

using namespace std;
#define MAXN 1000+10

int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

char a[MAXN*MAXN];
int n,m,J,F,d[MAXN*MAXN];
bool have[MAXN*MAXN];

int mark(int x,int y) {
    return (x-1)*m+y;
}

int main() {
    int t=read();
    while(t--) {
        n=read(),m=read();
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++) {
                int here=mark(i,j);
                cin>>a[here];
                if(a[here]=='J') J=here;
                if(a[here]=='F') F=here;
            }

        queue<int> q;
        memset(d,0,sizeof(d));
        memset(have,0,sizeof(have));
        q.push(F);
        d[F]=0;have[F]=1;
        while(!q.empty()) {
            int u=q.front(),v;
            cout<<u<<endl;
            q.pop();
            v=u+1;
            if(v<n*m+1&&v>0&&a[v]!='#'&&!have[v]) {
                d[v]=d[u]+1;
                q.push(v);
                have[v]=1;
            }  
            v=u-1;
            if(v<n*m+1&&v>0&&a[v]!='#'&&!have[v]) {
                d[v]=d[u]+1;
                q.push(v);
                have[v]=1;
            }  
            v=u-m;
            if(v<n*m+1&&v>0&&a[v]!='#'&&!have[v]) {
                d[v]=d[u]+1;
                q.push(v);
                have[v]=1;
            }  
            v=u+m;
            if(v<n*m+1&&v>0&&a[v]!='#'&&!have[v]) {
                d[v]=d[u]+1;
                q.push(v);
                have[v]=1;
            }  
        }
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                cout<<d[mark(i,j)];
            }
            cout<<endl;
        }
    }
    return 0;
}
