#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;
#define int ll
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

const int MAXN=1000000+10;

int head[MAXN],_next[MAXN<<1],to[MAXN<<1],cnt;

void addedge(int u,int v) {
	cnt++;
	_next[cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}

char a[MAXN];

int s[MAXN],tp=0;

int f[MAXN],fa[MAXN],book[MAXN],ans[MAXN];

void dfs(int u) {
	int flag=0;
	if(a[u]=='(') {
		f[u]=0;
		s[++tp]=u;
	}	
	else {
		if(tp) {
			f[u]=f[fa[s[tp]]]+1;
			flag=s[tp];
			tp--;
		}
	}
	ans[u]=f[u]+ans[fa[u]];
	for(int i=head[u]; i; i=_next[i]) {
		int v=to[i];
		dfs(v);
	}
	if(flag) s[++tp]=flag;
	else if(tp) tp--;
}

signed main() {
	int n=read();
	scanf("%s",a+1);
	REP(i,2,n) {
		fa[i]=read();
		addedge(fa[i],i);
	}
	dfs(1);
	
	int sum=ans[1];
	REP(i,2,n) {
		sum=sum^(ans[i]*i);
	}

	printf("%lld\n",sum);
	return 0;
}

