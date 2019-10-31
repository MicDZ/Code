//////////////////////////////////////////////
// Author: MicDZ 
// Email: me@micdz.cn 
// Last modified: 2019-07-31 18:03
// Filename: CJ1478.cpp
//////////////////////////////////////////////

#include<bits/stdc++.h>
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
const int MAXN=100+10;
int a[MAXN][MAXN]; 

int main() {
	int n=read(),m=read();
	memset(a,1,sizeof(a));
	
	REP(i,1,m) {
		int u=read(),v=read(),w=read();
		a[u][v]=a[v][u]=w;
	}
	REP(k,1,n) REP(i,1,n) REP(j,1,n) 
		a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	
	int ans=0;
	REP(i,2,n) 
		ans=max(ans,a[1][i]);
	if(ans>=a[0][0]) puts("-1");
	else printf("%d\n",ans);
	return 0;
}


