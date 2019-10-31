//////////////////////////////////////////////
// Author: MicDZ 
// Email: micdzcn@gmail.com 
// Last modified: 2019-08-01 08:47
// Filename: POJ3321.cpp
//////////////////////////////////////////////
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define lowbit(x) (x&(-x))
#define ll long long
int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int MAXN=200000+10;

int head[MAXN],to[MAXN],_next[MAXN],l[MAXN],r[MAXN],a[MAXN],c[MAXN],cnt;

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

int n,m;

int ask(int x) {
	int ans=0;
	while(x) {
		ans+=c[x];
		x-=lowbit(x);
	}
	return ans;
}

void change(int x,int v) {
	while(x<=n) {
		c[x]+=v;
		x+=lowbit(x);
	}
}

int tot,vis[MAXN];

void dfs(int x) {
	tot++;
	l[x]=tot;vis[x]=1;
	for(int i=head[x]; i; i=_next[i]) {
		int y=to[i];
		if(vis[y]) continue;
		dfs(y);
	}
	r[x]=tot;
}

int main() {
	n=read();
	cnt=0;
	REP(i,1,n-1) {
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
	tot=0;dfs(1);
	
	REP(i,1,n) {change(i,1);a[i]=1;}
	
	scanf("%d",&m);
	
	char op[5];int x;

	REP(i,1,m) {
		scanf("%s%d",op,&x);
		if(op[0]=='Q') 
			printf("%d\n",ask(r[x])-ask(l[x]-1));		
		else if(op[0]=='C'){
			if(a[x]) {change(l[x],-1);a[x]=0;}
			else {change(l[x],1);a[x]=1;}
		}
	}
	
	return 0;
}

