#include<bits/stdc++.h>
using namespace std;
bool a[1011][1011];
int n,m,s,u,v,ans;
int dfs(int x,int y){
     for(int k=1;k<=2;k++){
        int t,g;
        if(k==1)t=u,g=x;else t=v,g=y;
        for(int i=t;i<=g;i++){
            if(k==1&&!a[i][y])return 0;
            else if(k==2&&!a[x][i])return 0;
        }
    }
    s++;
    dfs(x+1,y+1);
    return s;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]){
                u=i;v=j;s=0;
                ans=max(ans,dfs(i,j));
            }
    cout<<ans<<endl;
}