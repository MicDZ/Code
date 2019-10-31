#include<bits/stdc++.h>
using namespace std;
#define MAXN 150+10
#define INF 0x3f3f3f

int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

struct farm {
	int x,y; 
}a[MAXN];

double dist(int i,int j) {
	return sqrt(pow(a[i].x-a[j].x,2)+pow(a[i].y-a[j].y,2));
}
double dis[MAXN][MAXN],fard[MAXN];

int main() {
	int n=read();
	for(int i=1; i<=n; i++) {
		a[i].x=read();
		a[i].y=read();	
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++) {
			char a;
			cin>>a;
			if(a=='1') {
				dis[i][j]=dist(i,j);
			}
			else dis[i][j]=INF;
		}
	}
	for(int i=1; i<=n; i++) dis[i][i]=0;
	for(int k=1; k<=n; k++) 
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++) {
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
	double ans1;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) {
			if(dis[i][j]!=INF) fard[i]=max(fard[i],dis[i][j]);
			ans1=max(ans1,fard[i]);
		}
	double ans2=INF;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) {
			if(dis[i][j]==INF) ans2=min(ans2,fard[i]+fard[j]+dist(i,j));
		}
	printf("%.6lf",max(ans1,ans2));
}
