#include<bits/stdc++.h>
using namespace std;
int n,m,t,xq,yq,xz,yz,ans;
bool Map[1010][1010],book[1010][1010];
void dfs(int x,int y)
{
	if(x>n||y>m||x<1||y<1||Map[x][y]||book[x][y])return;
	if(x==xz&&y==yz){
		ans++;
		return;
	}
	book[x][y]=1;
	dfs(x,y+1);
	dfs(x,y-1);
	dfs(x+1,y);
	dfs(x-1,y);
	book[x][y]=0;
}
int main()
{
	cin>>n>>m>>t>>xq>>yq>>xz>>yz;
	for(int i=1;i<=t;i++)
	{
		int u,v;
		cin>>u>>v;
		Map[u][v]=1;	
	}
	dfs(xq,yq);
	cout<<ans;
} 
