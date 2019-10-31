#include<bits/stdc++.h>
using namespace std;
#define MAXN (int)1e3+10
#define INF 0x3f3f3f
int splace[MAXN][MAXN],road[MAXN][MAXN],m,n,ans=INF;
short jx[5]={0,-1,1,0,0};
short jy[5]={0,0,0,-1,1};
void csh(){
	memset(road,INF,sizeof(road));
	//memeset(splace,INF,sizeof(splace));
}
void debug(){
	//
}
void dfs(int x,int y,int sum,bool mf){
	if(x<1||y<1||x>m||y>m||!splace[x][y]||sum>=road[x][y])return;
	road[x][y]=sum;
	if(x==m&&y==m){
		if(sum<ans)ans=sum;
        return;
	}
	for(int i=1;i<=4;i++){
		int bx=x+jx[i],by=y+jy[i];//这里打错一个y2333，找半天
		if(splace[bx][by]){
			if(splace[bx][by]==splace[x][y])dfs(bx,by,sum,0);
			else dfs(bx,by,sum+1,0);
		}
		else if(!mf&&!splace[bx][by]){
			splace[bx][by]=splace[x][y];
			dfs(bx,by,sum+2,1);//使用膜法
			splace[bx][by]=0;
		}
	}
}
int main(){
	csh();
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		int u,v,s;
		cin>>u>>v>>s;
		splace[u][v]=s+1;
	}
	dfs(1,1,0,0);
	if(ans==INF){
		cout<<-1;
		return 0;
	}
	cout<<ans;
}