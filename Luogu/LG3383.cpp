#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define DREP(i,e,s) for(register int i=e; i>=s; i--)
#define file(a) freopen(a".in","r",stdin);freopen(a".out","w",stdout)

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int MAXN=10000000+10;

int prime[MAXN],vis[MAXN],cnt;

int main() {
	//file("LG3383");
	int n=read(),m=read();
	vis[1]=1;
	
	REP(i,2,n) {
		if(!vis[i]) prime[++cnt]=i;
		for(int j=1; j<=cnt&&i*prime[j]<=n; j++) {
			vis[i*prime[j]]=1;
			if(i%prime[j]) break;
		}
	}

	REP(i,1,m) {
		int a=read();
		printf("%s\n",!vis[a]?"Yes":"No");
	}
	return 0;
}
