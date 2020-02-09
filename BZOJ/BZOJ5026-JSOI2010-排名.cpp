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

const int MAXN=200000+10;

int head[MAXN],_next[MAXN],to[MAXN],cnt;

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

priority_queue<int> q;

int a[MAXN],ans[MAXN],in[MAXN],out[MAXN];

int main() {
	int n=read();
	REP(i,1,n) {
		a[i]=read();
		if(!a[i]) continue;
		addedge(a[i],i);
		in[i]++,out[a[i]]++;
	}
	int tot=n;
	REP(i,1,n) if(!out[i]) q.push(i);
	
	while(!q.empty()) {
		int u=q.top();q.pop();
		ans[u]=tot--;
		if(!(--out[a[u]])) q.push(a[u]);
	}tot=0;
	REP(i,1,n) printf("%d ",ans[i]);
	puts("");
	REP(i,1,n) if(!in[i]) q.push(i);
	while(!q.empty()) {
		int u=q.top();q.pop();
		ans[u]=++tot;
		for(int i=head[u]; i; i=_next[i]) {
			int v=to[i];
			q.push(v);
		}
	}

	REP(i,1,n) printf("%d ",ans[i]);
	return 0;
}

