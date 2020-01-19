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



const int MAXN=100000+10;

priority_queue<int> q[MAXN];
int c[MAXN],l[MAXN],rt[MAXN];

int main() {
	int n=read(),m=read();
	REP(i,1,n) {
		int b=read();c[i]=read(),l[i]=read();
		addedge(b,i);
	}
	int tot=0;

	DREP(u,1,0) {
		if(c[u]<=m) rt[u]=++tot,num[u]=1
	}
	return 0;
}

