#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

#define REP(i,e,s) for(register int i=(e); i<=(s); i++)
#define DREP(i,e,s) for(register int i=(e); i>=(s); i--)
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

const int MAXN=1e5+10;

priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q[MAXN];

int fa[MAXN],book[MAXN];

int find(int x) {
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

int main() {
	int n=read(),m=read();
	REP(i,1,n) fa[i]=i;
	REP(i,1,n) q[i].push(make_pair(read(),i));

	REP(i,1,m) {
		int op=read();
		if(op==1) {
			int x=read(),y=read();
			if(book[x]||book[y]||find(x)==find(y)) continue;
			if(q[find(x)].size()<q[find(y)].size()) swap(x,y);
			x=find(x),y=find(y),fa[y]=x;
			while(!q[y].empty()) {
				q[x].push(q[y].top());
				q[y].pop();
			}
		}
		else {
			int x=read();
			if(book[x]) puts("-1");
			else printf("%d\n",q[find(x)].top().first),book[q[find(x)].top().second]=1,q[find(x)].pop();
		}
	}
	return 0;
}

