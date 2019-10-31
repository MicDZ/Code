#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>

using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define ll long long
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=10000+10;

struct node {
	int x,y,z;
} a[MAXN];

double dist(int m,int n) {
	return sqrt((a[m].x-a[n].x)*(a[m].x-a[n].x)+(a[m].y-a[n].y)*(a[m].y-a[n].y)+(a[m].z-a[n].z)*(a[m].z-a[n].z));
}

int head[MAXN],_next[MAXN<<1],to[MAXN<<1],cnt;

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
} 

int have[MAXN];

int main() {
	int t=read();
	while(t--) {
		int n=read(),h=read(),r=read();
		REP(i,1,n) a[i].x=read(),a[i].y=read(),a[i].z=read();
		cnt=0;
		memset(head,0,sizeof(head));
		memset(have,0,sizeof(have));
		REP(i,1,n) REP(j,i+1,n) 
			if(dist(i,j)<=2*r) addedge(i,j),addedge(j,i);
		
		queue<int> q;
		REP(i,1,n) {
			if(abs(a[i].z)<=r) {
				have[i]=1;
				q.push(i);
			}
		}
	
		while(!q.empty()) {
			int u=q.front();q.pop();
			for(int i=head[u]; i; i=_next[i]) {
				int v=to[i];
				if(have[v]) continue;
				have[v]=1;
				q.push(v);
			}
		}
		bool flag=0;

		REP(i,1,n) {
			if(abs(h-a[i].z)<=r&&have[i]) flag=1;
		}

		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}
