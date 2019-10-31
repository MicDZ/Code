#include<bits/stdc++.h>
using namespace std;
#define REP(i,e,s) for(register int i=e; i<=s; i++)
#define ll long long
const int MAXN=20+5;

ll f[MAXN][MAXN],book[MAXN][MAXN];

int read() {
	int x=0,f=1,ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int dx[10]={0,-1,-2,-1,-2,1,2,1,2};
int dy[10]={0,-2,-1,2,1,-2,-1,2,1};
int main() {
	long long n=read(),m=read(),x=read(),y=read();
	book[x+1][y+1]=1;
	REP(i,1,8) book[x+dx[i]+1][y+dy[i]+1]=1;

	f[1][1]=1;//Ïò×óÏÂÆ½ÒÆ

	REP(i,1,n+1) REP(j,1,m+1) {
		f[i][j]=max(f[i-1][j]+f[i][j-1],f[i][j]);
		if(book[i][j]) f[i][j]=0;
	}

	printf("%lld\n",f[n+1][m+1]);
	return 0;
}
