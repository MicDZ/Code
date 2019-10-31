#include<bits/stdc++.h>
using namespace std;
char a[105][105];
int book[105][105];
int n,m;
int mhd(int x1,int x2,int y1,int y2)
{
	return (abs(x1-x2)+abs(y1-y2));
}
void dfs(int x,int y,int id)
{
    if(x>n||x<1||y>m||y<1||a[x][y]!='#'||book[x][y]>0)return;
    book[x][y]=id;
    dfs(x+1,y,id);
	dfs(x-1,y,id);
	dfs(x,y+1,id);
	dfs(x,y-1,id);
	dfs(x+1,y+1,id);
	dfs(x-1,y-1,id);
	dfs(x-1,y+1,id);
	dfs(x+1,y-1,id);
	dfs(x+2,y,id);
	dfs(x-2,y,id);
	dfs(x,y+2,id);
	dfs(x,y-2,id);
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        scanf("%s",a[i]+1);
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]=='#'&&book[i][j]==0)dfs(i,j,++ans);
    cout<<ans;
} 
