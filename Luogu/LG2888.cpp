#include<bits/stdc++.h>
using namespace std;
int ans[1010][1010],a[1010][1010],n,m,w;
#define INF 0x3f3f3f
void memset_2(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            ans[i][j]=a[i][j];
}
void memset_1(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j)ans[i][j]=a[i][j]=INF;
}
int main()
{
    int q;
    cin>>n>>m>>q;
    memset_1();
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v>>w;
        a[u][v]=w;
    }
    memset_2();
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                ans[i][j]=min(ans[i][j],max(ans[i][k],ans[k][j]));
    for(int i=1;i<=q;i++){
        int u,v;
        cin>>u>>v;
        if(ans[u][v]==INF) cout<<-1<<endl;
        else cout<<ans[u][v]<<endl;
    }
}