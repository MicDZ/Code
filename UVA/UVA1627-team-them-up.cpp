#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>

using namespace std;

#define REP(i,e,s) for(register int i=(e); i<=(s); i++)
#define DREP(i,e,s) for(register int i=(e); i>=(s); i--)
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define ll long long

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=100+10,MAXM=10000+10;

int head[MAXN],to[MAXM],_next[MAXM],cnt;

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

int have[MAXN][MAXN];

queue<int> q;

int color[MAXN],_num,tot;

vector<int> g[2][MAXN];

bool bfs(int s) {
	q.push(s);
	color[s]=0;_num=1;g[0][tot].push_back(s);
	while(!q.empty()) {
		int u=q.front();q.pop();
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			if(color[v]==-1) color[v]=color[u]^1,_num++,g[color[v]][tot].push_back(v);
			else if(color[v]==color[u]) return 1;
			else continue;
			q.push(v);
		}
	}
	return 0;
}

void init() {
	memset(color,-1,sizeof(color));
	memset(head,0,sizeof(head));
	memset(have,0,sizeof(have));
}

int num[MAXN];

int main() {
	file("data");
	int t=read();
	while(t--) {
		memset(color,-1,sizeof(color));
		memset(head,0,sizeof(head));	
		memset(have,0,sizeof(have));
		cnt=0;
		int n=read();
		REP(u,1,n) {
			int v=read();
			while(v) {
				have[u][v]=1;
				v=read();
			}
		}
		REP(i,1,n) REP(j,i+1,n) 
			if(!have[i][j]||!have[j][i]) 
				addedge(i,j),addedge(j,i);
		tot=0;
		bool flag=0;
		REP(i,1,n) {
			if(color[i]==-1) {
				if(bfs(i)) {
					puts("No solution");
					flag=1;
					break;	
				}
				num[++tot]=_num;
			}
		}

		REP(i,1,tot) DE("%d ",num[i]);DE("\n");
		if(flag) continue;
	}
	return 0;
}

