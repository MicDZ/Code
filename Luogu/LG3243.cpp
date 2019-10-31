#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define ll long long
#define DE(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG(a) DE("DEBUG: %d\n",a)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=100000+10;

int head[MAXN],_next[MAXN],to[MAXN],cnt;

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

int in[MAXN];

priority_queue<int> q;
int ans[MAXN],num;
int main() {
	int t=read();
	while(t--) {
		int n=read(),m=read();
		memset(in,0,sizeof(in));
		cnt=0;
		memset(head,0,sizeof(head));
		bool flag=0;
		REP(i,1,m) {
			int u=read(),v=read();
			addedge(v,u);
			in[u]++;
			if(u==v) flag=1;
		}
		if(flag) {
			puts("Impossible!");
			continue;
		}
		REP(i,1,n) if(!in[i]) q.push(i);
		num=0;
		while(!q.empty()) {
			int u=q.top();q.pop();ans[++num]=u;
			for(int i=head[u]; i; i=_next[i]) {
				int v=to[i];
				in[v]--;
				if(in[v]==0) q.push(v);
			}
		}
		if(num<n) {
			puts("Impossible!");
			continue;
		}
		DREP(i,num,1) printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}
