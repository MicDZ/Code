#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000+10
#define INF 0x3f3f3f3f
int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,xa,xb,ya,yb;

int a[MAXN][MAXN];

int z[MAXN][MAXN],m[MAXN][MAXN];


void debug1() {
	cout<<endl;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			printf("%3d",m[i][j]==INF?0:m[i][j]);
		}
		cout<<endl;
	}
}


void debug2() {
	cout<<endl;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			printf("%3d",(z[i][j]==INF?0:z[i][j]));
		}
		cout<<endl;
	}
}

struct edge{
	int xq,yq;
};

int have[MAXN][MAXN];

void bfs1(int xs,int ys) {
	int tx[5]={0,1,0,-1,0};
	int ty[5]={0,0,1,0,-1};
	
	queue<edge> q;
	q.push((edge){xs,ys});
	while(!q.empty()) {
		int x=q.front().xq,y=q.front().yq;

		q.pop();
		for(int i=1; i<=4; i++) {
			int xx=x+tx[i],yy=y+ty[i];
			if(have[xx][yy]||xx<1||xx>n||yy<1||yy>n) continue;
			
			if(a[xx][yy]) {
				if(i==1) xx++;
				if(i==2) yy++;
				if(i==3) xx--;
				if(i==4) yy--;
			}
			
			if(have[xx][yy]||xx<1||xx>n||yy<1||yy>n) continue;
			
			if(!a[xx][yy]) {
				m[xx][yy]=min(m[xx][yy],m[x][y]+1);
				q.push((edge){xx,yy});
				have[xx][yy]=1;
			}
		}
		
	}
}

struct edge2{
	int s,xq,yq;
};

void bfs2(int xs,int ys) {
	int tx[5]={0,1,0,-1,0};
	int ty[5]={0,0,1,0,-1};
	queue<edge2> q;
	q.push((edge2){0,xs,ys});
	have[xs][ys]=1;
	z[xs][ys]=0;
	while(!q.empty()) {
		int x=q.front().xq,y=q.front().yq,s=q.front().s;
		q.pop();
		if(a[x][y]) continue;
		for(int i=1; i<=4; i++) {
			int xx=x+tx[i],yy=y+ty[i];

			if(xx<1||xx>n||yy<1||yy>n||a[xx][yy]) continue;
			if(!have[xx][yy]) {
				have[xx][yy]=1;
				z[xx][yy]=s+1;
				q.push((edge2){s+1,xx,yy});
			}
			for(int j=1; j<=4; j++) {
				int xr=xx+tx[j],yr=yy+ty[j];
				if(xr<1||xr>n||yr<1||yr>n||a[xr][yr]||have[xr][yr]) continue;
				have[xr][yr]=1;
				z[xr][yr]=s+1;
				q.push((edge2){s+1,xr,yr});
			}
		}
	}
}

int main() {
	n=read(),xa=read(),ya=read(),xb=read(),yb=read();
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) a[i][j]=getchar()-'0';
		getchar();
	}
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) 
			m[i][j]=INF,z[i][j]=INF;
	m[xb][yb]=0;
	bfs1(xb,yb);
	
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) 
			have[i][j]=0;
	z[xa][ya]=0;
	bfs2(xa,ya);
	int ans=INF;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) {
			ans=min(ans,max(m[i][j],z[i][j]));
		}
	cout<<ans<<endl;
}
