#include<bits/stdc++.h>
using namespace std;
char a[101][101];
bool id[101][101];
int n,m;
void dfs(int x,int y,int s)
{
	if(x<0&&y<0&&x>n&&y>m&&id[x][y]>0&&a[x][y]!='W')return;
	id[x][y]=s;
	dfs(x+1,y,s);
	dfs(x-1,y,s);
	dfs(x,y+1,s);
	dfs(x,y-1,s);
	dfs(x+1,y+1,s);
	dfs(x+1,y-1,s);
	dfs(x-1,y+1,s);
	dfs(x+1,y-1,s);
}
int main()
{
	int ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%s",a[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(id[i][j]==0&&a[i][j]=='W')dfs(i,j,++ans);
	cout<<ans;
}
