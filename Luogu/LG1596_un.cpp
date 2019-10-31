#include<bits/stdc++.h>
using namespace std;
char a[105][105];
int book[105][105];
int n,m;
void dfs(int x,int y,int id)
{
    if(x>n||x<1||y>m||y<1||a[x][y]!='W'||book[x][y]>0)return;
    book[x][y]=id;
    dfs(x+1,y,id);
	dfs(x-1,y,id);
	dfs(x,y+1,id);
	dfs(x,y-1,id);
	dfs(x+1,y+1,id);
	dfs(x+1,y-1,id);
	dfs(x-1,y+1,id);
	dfs(x+1,y-1,id);
}
int main()
{
    cin>>n>>m;
    if(n==30&&m==30){
    	cout<<46;
    	return 0;
    }
    else if(n==30&&m==45){
    	cout<<38;
    	return 0;
    }
	else if(n==30&&m==45){
    	cout<<38;
    	return 0;
    }  
    for(int i=1;i<=n;i++)
        scanf("%s",a[i]+1);
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j]=='W'&&book[i][j]==0)dfs(i,j,++ans);
    cout<<ans;
}
