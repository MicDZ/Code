#include<iostream>
#include<cstdio>
#include<cstring>


#define MAXN 200+10
#define INF 0x3f3f3f3f
using namespace std;

int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int a[MAXN][MAXN],p[MAXN],match[MAXN],n,m;

int dfs(int k) {
	for(int i=1; i<=m; i++) {
		if(p[i] || !a[k][i]) continue;
		p[i]=true;
		if(!match[i] || dfs(match[i])) {
			match[i]=k;
			return 1;
		}
	}
	return 0;
}

int main() {
	n=read(),m=read();
	for(int i=1; i<=n; i++) {
		int s=read();
		for(int j=1; j<=s; j++) {
			a[i][read()]=1;
		}
	}
	int ans=0;
	for(int i=1; i<=n; i++) {
		memset(p,0,sizeof(p));
		ans+=dfs(i);
	}
	printf("%d\n",ans);
	return 0;
}


